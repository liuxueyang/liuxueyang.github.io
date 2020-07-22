use 5.032;
use strict;
use warnings;
use Getopt::Long qw(GetOptions);

my $s;
GetOptions('from=s' => \$s) or die "Usage: $0 --from NAME\n";
if ($s) {
    say $s;
}
