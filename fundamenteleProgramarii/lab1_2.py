import sys

isp=[]

def c():
	i=2
	while(i*i<len(isp)):
		if(isp[i]==1):
			for j in xrange(i*i,len(isp),i):
				isp[j]=0
		i+=1

sys.stdin=open('input.txt','r');
sys.stdout=open('output.txt','w');
for i in xrange(1,1000002):
	isp.append(1)
c()
n=int(raw_input())
print isp[n]