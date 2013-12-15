import sys
import math

def isPrime(n):
	if(n==1):
		return 0
	for i in xrange(2,int(math.sqrt(n))+1):
			if(n%i==0):
				return 0
	return 1

def e1():
	n=int(raw_input())
	ok=0
	while(isPrime(n)==0):
		n+=1
	return n

def e4():
	n=int(raw_input())
	for i in xrange(1,n):
		if(isPrime(i) and isPrime(n-i)):
			print i," ",n-i
			break

			
def e5():
	n=int(raw_input())
	isp=[0]*1000005
	primes=[]
	for i in xrange(2,len(isp)):
		if(isp[i]==0):
			primes.append(i)
			for j in xrange(i+i,len(isp),i):
				isp[j]=1
	for i in xrange(1,len(primes)):
		if(n<primes[i-1] and primes[i]-primes[i-1]==2):
			print primes[i],' ',primes[i-1]
			break
def e6():
	f=[1]*2
	n=int(raw_input())
	while(f[len(f)-1]+f[len(f)-2]<=n):
		f.append(f[len(f)-1]+f[len(f)-2])
	print f[len(f)-1]+f[len(f)-2]
def e7():
	n=int(raw_input())
	i=0
	
#e1()
#e4()
e5()
#e6()
#e7()