r,c=map(int,raw_input().split())
m=[]
fa=[]
fb=[]
na=[]
nb=[]
for i in xrange(0,r):
	m.append(map(int,raw_input().split()))
re=0
for i in xrange(0,r):
	for j in xrange(0,c):
		if(m[i][j]==1 and re==0):
			fol[i][j]=1
			re=1
for i in xrange(0,r):
	for j in xrange(0,c):
		if(m[i][j]==1 and fol[i][j]==1):
print re