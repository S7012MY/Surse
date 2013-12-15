t=int(raw_input())
for z in xrange(0,t):
	n, c, m = map(int, raw_input().split())
	rt=n//c
	r=rt
	while(rt>=m):
		r+=1
		rt+=1
		rt-=m
		#print str(r)+' '+str(rt)+' '+str(c)
	print r