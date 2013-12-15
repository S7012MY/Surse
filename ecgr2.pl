$a=1;
$b=100000000;
$c=1;

$delta=$b*$b-$c*$a*4;
$x1=(-$b+sqrt($delta))/2;
$x2=(-$b-sqrt($delta))/2;
printf "%.18f %.18f", $x1,$x2