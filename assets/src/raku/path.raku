#!/usr/bin/env raku

sub MAIN ($start-date = Date.today.Str) {
    my $leetcode = "/Users/liuxueyang/fun/leetcode-everyday/".IO;
    my @dir-list = ($leetcode, $leetcode.add("past"));

    my &avaliable-name := -> $a {
        my $res;
        for 2018..2022 {
            $res ||= $a.starts-with($_);
        }
        $res
    }

    my &avaliable-dir-name := -> $a {
        avaliable-name($a.basename)
    }

    my @problem-set;

    my &list-dir := -> $dir {
        for dir($dir) -> $name {
            if avaliable-dir-name($name) {
                my $index = $name.basename.index("_");
                if $index.defined {
                    @problem-set.push($name);
                } else {
                    list-dir($name);
                }
            }
        }
    }

    for @dir-list -> $dir {
        list-dir($dir);
    }

    @problem-set = @problem-set.sort: *.basename;
    @problem-set = @problem-set.reverse;

    my $date-fmt = { sprintf "%04d%02d%02d", .year, .month, .day };
    my $today = Date.today(formatter => $date-fmt);
    my $deadline = Date.new(2018, 4, 1, formatter=> $date-fmt);
    my $cur = Date.new($start-date, formatter => $date-fmt);

    while $cur > $deadline {
        my $name = @problem-set.shift;
        unless $name.basename.starts-with($cur.Str) {
            say $cur;
            last;
        }
        $cur = $cur.pred;
    }
}
