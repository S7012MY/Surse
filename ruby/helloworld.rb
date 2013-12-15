x = "world"
puts "hello #{x}"

def fibo n
	if n < 2
		1
	else 
		fibo(n - 1) + fibo(n - 2)
	end
end

puts fibo(3)


f1
f2
f3