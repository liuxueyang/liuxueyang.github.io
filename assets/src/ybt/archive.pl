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

# 源文件归档脚本
# eg. perl archive.pl --dst-dir for_loop for_loop.org
# for_loop.org 文件包含题号列表
GetOptions(
    'dst-dir=s' => \$target_dir_path,
    ) or die `Usage: $0 --dst-dir DIRNAME FILENAME`;

unless (@ARGV) {
    exit;
}

my $dst_dir = File::Spec->catfile($dir_path, $target_dir_path);;

if ($target_dir_path and !(-d $target_dir_path)) {
    mkdir $dst_dir;
}

while(<>) {
    chomp;
    my $inputfile = $_ . ".in";
    my $srcfile = $_ . ".cpp";
    $inputfile = File::Spec->catfile($dir_path, $inputfile);
    $srcfile = File::Spec->catfile($dir_path, $srcfile);

    move($inputfile, $dst_dir) or warn "move failed: $!, $inputfile";
    move($srcfile, $dst_dir) or warn "move failed: $!, $srcfile";
}
