MOD = 1000000007
t=int(raw_input())
for i in xrange(0,t):
	a,b=map(long,raw_input().split())
	a=a%MOD
	print pow(a,b,MOD)