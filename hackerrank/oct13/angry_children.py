n=int(raw_input())
k=int(raw_input())
v=[]
for i in xrange(0,n):
	x=int(raw_input())
	v.append(x)
v.sort()
r=v[k-1]-v[0]
for i in xrange(1,n-k):
	r=min(r,v[i+k-1]-v[i])
print r