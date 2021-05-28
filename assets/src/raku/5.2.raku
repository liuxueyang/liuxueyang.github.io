#!/usr/bin/env raku

sub MAIN () {
    my $i = 12;
    while $i <= 75 {
        put $i if $i %% 3;

        ++$i;

        put "Exit" if $i > 75;
    }
}
