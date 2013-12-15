for NUM in $(seq 1 200);
do
	echo $NUM
	echo Gentest
	g++ gentest.cpp
	./a.out
	echo main
	g++ main.cpp -w
	./a.out
	echo brute
	g++ ON.cpp
	./a.out
	diff 2ndesc.out 2ndesc2.out -n
	#echo "AICI"
	#read var
done
