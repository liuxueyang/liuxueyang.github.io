---
layout: post
title:  使用 Perl 归档源代码和生成题解文档
date:   2020-07-23 18:05:38 +0800
---

一本通上的练习题做了几章，源码管理都是在一个目录下面。所以写了一个脚本来归档每章的源码文件。另外，对每章的题目，生成一篇题解文档。虽然做的事情比较简单，但是使用 Perl 写挺有意思的。

归档源代码实现：

```perl
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
# eg. perl archive.pl --dst-dir sorting sorting.org
# sorting.org 文件包含题号列表
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
```

[archive.pl](/assets/src/ybt/archive.pl)

----

生成题解文档的实现：

```perl
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
```
[gen_md.pl](/assets/src/ybt/gen_md.pl)
