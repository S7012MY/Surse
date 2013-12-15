def conv(n,b):
	if(n!=0):
		conv(n/b,b)
		print n%b
n=int(raw_input())
conv(n,7)