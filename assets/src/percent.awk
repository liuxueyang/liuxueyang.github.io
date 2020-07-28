BEGIN {
}

{
    total = $1 + $2;
    print $1 / total * 100;
}

END {
}

# awk -f percent.awk < num.txt
