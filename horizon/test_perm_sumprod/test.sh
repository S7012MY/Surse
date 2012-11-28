for NUM in $(seq 1 200);
do
	echo Gentest
	g++ gentest.cpp
	./a.out
	echo main
	g++ main.cpp
	./a.out
	echo back
	g++ back.cpp
	./a.out
done
