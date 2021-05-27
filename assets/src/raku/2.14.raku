sub MAIN($high = 100) {
    my $secret = $high.rand.Int;

    my $fail_reason_big := 1;
    my $fail_reason_small := 2;

    loop {
        my $guess = prompt "Your Guess: ";
        state $reason = 0;

        if $guess == $secret {
            put "Congratulations";
            last;
        } elsif $guess < $secret {
            put "Too Small";

            if $reason == $fail_reason_small {
                put "You failed again";
            } else {
                $reason = $fail_reason_small;
            }
        } else {
            put "Too Big";

            if $reason == $fail_reason_big {
                put "You failed again";
            } else {
                $reason = $fail_reason_big;
            }
        }
    }
}
