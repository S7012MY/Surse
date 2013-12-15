import re
from operator import itemgetter

def insert(args,list):
	if(len(args)!=4):
		print "invalid insert sintax"
		return
	field=[]
	#validate input
	if(not args[0].isdigit()):
		print "first argument must be a number"
		return
	if(not args[3].isdigit()):
		print "third argument must be a number"
		return
	
	field.append(int(args[0]));
	field.append(args[1])
	field.append(int(args[3]))
	list.append(field)
	
def remove(args,list):
	if(len(args)==1):
		ok=True
		if(args[0].isdigit()):
			args[0]=int(args[0])
		while (ok==True):
			ok=False
			for i in list:
				if(i[1]==args[0] or i[2]==args[0]):
					list.remove(i)
					ok=True
	elif(len(args)==4):
	#remove a range of elements
		rem=[]
		ok=True
		args[1]=int(args[1])
		args[3]=int(args[3])
		while (ok==True):
			ok=False
			for i in list:
				if(i[2]>=args[1] and i[2]<=args[3]):
					list.remove(i)
					ok=True
	else:
		print "invalid number of arguments"

def replace(args,list):
	
def readLine():
	inp=raw_input("Write operation\n")
	line=re.split(" +|, *",inp)
	return line
	
expenses=[]
#testing
insert(["200","A","at","3"],expenses)
insert(["200","B","at","4"],expenses)
insert(["200","B","at","4"],expenses)
insert(["300","B","at","4"],expenses)
insert(["200","C","at","5"],expenses)
insert(["200","D","at","6"],expenses)
insert(["200","D","at","6"],expenses)
while(True):
	line=readLine()
	if(line[0]=="insert"):
		insert(line[1::],expenses)
	elif(line[0]=="remove"):
		remove(line[1::],expenses)
	elif(line[0]=="replace"):
		replace(line[1::],expenses)
	elif(line[0]=="undo"):
		print "undo"
	else:
		print "invalid operation"
	print expenses