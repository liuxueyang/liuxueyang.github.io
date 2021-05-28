#!/usr/bin/env raku

sub MAIN () {
    loop (my $i = 12; $i <= 75; $i++) {
        FIRST { put "Starting" }
        put "$i" if $i %% 3;
    }
}
