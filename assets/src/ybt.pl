#!/usr/bin/env perl
use 5.018;
use strict;
use warnings;
use File::Spec;

my $dir_path="./ybt/";
opendir my $dir, $dir_path or die "Cannot open directory: $!";

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
