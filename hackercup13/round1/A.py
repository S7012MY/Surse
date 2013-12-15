f=open('input.txt','r')
g=open('output.txt','w')
T=int(f.readline())
for t in xrange(1,T+1):
	s,nr=f.readline().split();
	nr=int(nr)
	#print s,n;
	rez=""
	pc=len(s);
	l=0
	while(pc<nr):
		nr-=pc
		pc*=len(s)
		l+=1
	pc/=len(s)
	for i in xrange(0,l+1):
		j=0
		while(j<len(s) and pc<nr):
			nr-=pc
			j+=1
		rez+=s[j]
		pc/=len(s)
	#print rez
	g.write("Case #"+str(t)+": "+rez+'\n')