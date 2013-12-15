while($line=<>) {
	chomp($line);
	@arr=split(',',$line);
	print "@arr";
	print "\n";
}