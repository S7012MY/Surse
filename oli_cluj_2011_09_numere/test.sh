for NUM in $(seq 1 200);
do
	echo Gentest
	g++ gentest.cpp
	./a.out
	echo main
	g++ stefana.cpp
	./a.out
	echo brute
	g++ main.cpp
	./a.out
done
