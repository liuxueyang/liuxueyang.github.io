#!/usr/bin/env perl
use 5.018;
use strict;
use warnings;
use File::Spec;
use Getopt::Long qw(GetOptions);
use Data::Dumper;
use FindBin qw($Bin);
use File::Copy;

my $dir_path = $Bin;
my $target_dir_path;
my $filename;

GetOptions(
    'src-dir=s' => \$dir_path,
    'dst-dir=s' => \$target_dir_path,
    # 'filename=s' => \$filename,
    ) or die "Usage: $0 --dirpath PATH --filename NAME";

# my $full_filename = File::Spec->catfile($dir_path, $filename);

opendir my $dir, $dir_path or die "Cannot open directory: $!";

print Dumper $dir_path, $filename; #, $full_filename;

my $dst_dir = File::Spec->catfile($dir_path, $target_dir_path);;

if ($target_dir_path and !(-d $target_dir_path)) {
    mkdir $dst_dir;
}

while(<>) {
    chomp;
    my $inputfile = $dir_path . $_ . ".in";
    my $srcfile = $dir_path . $_ . ".cpp";
    print Dumper $inputfile, $srcfile;
}

exit;

my @files = grep {/\d{4}\.cpp/ && -f "$dir_path/$_"} readdir($dir);
closedir($dir);

@files = sort @files;

my $dest_file="ybt.md";
open(DFH, '>', $dest_file) or die $!;

for my $file (@files){
    my $file1=File::Spec->catfile($dir_path, $file);
    open(FH, '<', $file1) or die $!;
    print DFH "\n```cpp\n";
    while(<FH>) {
        print DFH $_;
    }
    print DFH "```\n\n[$file](/assets/src/ybt/$file)\n\n"
}
