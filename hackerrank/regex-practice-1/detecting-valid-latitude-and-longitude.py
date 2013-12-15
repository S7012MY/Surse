import re
import sys

sys.stdin = open('input.txt', 'r')

n=int(raw_input)
#(-90,90), (-180,180)
rgx=re.compile(r'');
rgy=re.compile(r'')
for i in xrange(0,n):
	inp=raw_input