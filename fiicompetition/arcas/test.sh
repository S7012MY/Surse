for NUM in $(seq 1 200);
do
	echo $NUM
	echo Gentest
	g++ gentest.cpp
	./a.out
	echo bun
	g++ wzrd_arcas.cpp -w
	./a.out
	echo brute
	g++ brute.cpp
	./a.out
done
