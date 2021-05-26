sub MAIN($step = 3) {
    loop {
        state $num = 0;
        put $num += $step;
    }
}
