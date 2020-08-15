#!/usr/bin/env perl
# use 5.032;
use strict;
use warnings;
use File::Spec;
use Getopt::Long qw(GetOptions);
use Data::Dumper;
use FindBin qw($Bin);

my $link = "http://ybt.ssoier.cn:8088/problem_show.php?pid=";
my $section_name;
my $help_msg = "Usage: $0 --section-name NAME";
GetOptions(
    'section-name=s' => \$section_name,
    ) or die $help_msg;
$section_name or die $help_msg;

open(MDF, '>', $section_name . ".md");
my $section_dir_path = File::Spec->catfile($Bin, $section_name);
opendir my $dir, $section_dir_path or die "Cannot open directory: $!";
for my $f (sort(grep(/\.cpp$/, readdir $dir))) {
    my $file = File::Spec->catfile($section_dir_path, $f);
    open(my $in, '<', $file) or die $!;
    $f =~ /(\d+)\.cpp/;
    my $num = $1;
    my $ref = $link . $num;
    print MDF "[Problem $num]($ref)\n\n```cpp\n";
    while(<$in>) {
        print MDF $_;
    }
    print MDF "```\n\n[$f](/assets/src/ybt/$section_name/$f)\n\n----\n\n";
}
