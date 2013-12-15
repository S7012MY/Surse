import re
import sys

sys.stdin = open('input.txt', 'r')

inp=sys.stdin.read()
rgx=re.compile(r'//.*?$|/\*.*?\*/',re.MULTILINE|re.DOTALL)
m=rgx.findall(inp)
for i in m:
	print i