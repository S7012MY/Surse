f=open('input.txt','r')
g=open('output.txt','w')
T=int(f.readline())
#print T
for t in xrange(1,T+1):
	n=int(f.readline().split()[0])
	#print n
	mini=100
	minj=100
	maxi=-100
	maxj=-100
	m=[]
	for i in xrange(0,n):
		m.append(f.readline())
	for i in xrange(0,n):
		for j in xrange(0,n):
			if(m[i][j]=='#'):
				mini=min(mini,i);
				minj=min(minj,j);
				maxj=max(maxj,j);
				maxi=max(maxi,i);
	ok=" YES\n"
	for i in xrange(mini,maxi+1):
		for j in xrange(minj,maxj+1):
			if(m[i][j]!='#'): ok=" NO\n"
	if(maxi-mini!=maxj-minj): ok=" NO\n"
	g.write("Case #"+str(t)+ok)