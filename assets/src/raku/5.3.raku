#!/usr/bin/env raku

sub MAIN () {
    my &trim_lc := {
        $_ = .trim.lc;
    }

    loop {
        my $line = prompt "Input: ";
        last unless $line;

        trim_lc($line);
        put "line=<$line>";
    }
}
