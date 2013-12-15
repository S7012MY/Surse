import sys

sys.stdin=open('input.txt','r');
sys.stdout=open('output.txt','w');
n=int(raw_input())
s=0
for i in range(1,n+1):
	s+=i
print s