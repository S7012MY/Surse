for NUM in $(seq 1 2000);
do
	echo $NUM
	echo Gentest
	g++ gentest.cpp
	./a.out
	echo brute
	g++ brute.cpp
	./a.out
	echo bun
	g++ main.cpp -w 
	./a.out
done
