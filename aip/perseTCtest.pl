#!/usr/bin/perl -w
use v5.14;
use warnings;

#powered by Gavrilator

use List::MoreUtils qw/pairwise part/;
use File::Slurp qw/write_file/;

##################################################

my @lines;

while ($_ = <>){
  push @lines, (/>(.+)</)[0] if (/System Testing/ ... /End System Testing/) && /statText/ && ! /Passed/;
}

shift @lines for 1 .. 3;

my $i=0;
my @parts = part { $i++ % 2 } @lines;

$i=1;
pairwise {
  write_file "grader_test$i.in", $a;
  write_file "grader_test$i.ok", $b;
  $i++;
} @{$parts[0]}, @{$parts[1]};
