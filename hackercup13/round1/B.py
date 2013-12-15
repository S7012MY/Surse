f=open('input.txt','r')
g=open('output.txt','w')
T=int(f.readline())
for t in xrange(1,T+1):
	n,k,c=f.readline().split()
	n=int(n);
	k=int(k)
	c=int(c)
	#print n,k,c
	bestdiv=1
	rez=99999999
	if(k/n>=c):
		rez=c
	for i in xrange(1,k+1):
		lg=k/i;
		if(k%i>0):
			lg+=1
		if(k/i+(k%i>0)<=n):
			rez=min(rez,n-(k/i)+c)
			#break
	g.write("Case #"+str(t)+": "+str(rez)+'\n')