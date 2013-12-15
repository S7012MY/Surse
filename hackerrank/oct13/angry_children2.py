n=long(raw_input())
k=long(raw_input())
v=[]
for i in xrange(0,n):
	x=long(raw_input())
	v.append(x)
v.sort()
sp=0
sum=0
for i in xrange(1,k):
	sp+=v[i-1]
	sum+=(i*v[i]-sp)
r=sum
#print str(sp)+' '+str(sum)
sp+=v[k-1]
for i in xrange(k,n):
	#il scoatem pe v[i-k]
	sp-=v[i-k]
	sum-=(sp-(k-1)*v[i-k])
	#il adaugam pe v[i]
	sum+=((k-1)*v[i]-sp)
	sp+=v[i]
	r=min(r,sum)
	#print str(i)+' '+str(sp)+' '+str(sum)+' '+str(r)
print r