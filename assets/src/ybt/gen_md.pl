#!/usr/bin/env perl
use 5.032;
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
for my $f (grep (/\.cpp$/, readdir $dir)) {
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

# my @files = grep {/\d{4}\.cpp/ && -f "$dir_path/$_"} readdir($dir);
# closedir($dir);

# @files = sort @files;

# my $dest_file="ybt.md";
# open(DFH, '>', $dest_file) or die $!;

# for my $file (@files){
#     my $file1=File::Spec->catfile($dir_path, $file);
#     open(FH, '<', $file1) or die $!;
#     print DFH "\n```cpp\n";
#     while(<FH>) {
#         print DFH $_;
#     }
#     print DFH "```\n\n[$file](/assets/src/ybt/$file)\n\n"
# }
