for NUM in $(seq 1 200);
do
	echo $NUM
	echo Gentest
	g++ gentest.cpp
	./a.out
	echo main
	g++ main.cpp
	./a.out
	echo brute
	g++ brute.cpp
	./a.out
done
