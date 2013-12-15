for NUM in $(seq 1 200);
do
	echo Gentest
	g++ gentest.cpp
	./a.out
	echo main
	g++ ephie.cpp
	./a.out
	echo dinamica
	g++ petru_greedy_NlogN_stl.cpp
	./a.out
done
