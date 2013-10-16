l=[]
for i in range (0, 2000):
	l.append(0)
t=int(input())
count=0
inl=raw_input().split()
for i in range (0, t):
	inl[i]=int(inl[i])-1
	if(inl[i]==0):
		if(l[inl[i]+1]==0):
			count=count+1
	elif(inl[i]==1999):
		if(l[inl[i]-1]==0):
			count=count+1
	else:
		if(l[inl[i]+1]==1 and l[inl[i]-1]==1):
			count=count-1
		elif(l[inl[i]+1]==0 and l[inl[i]-1]==0):
			count=count+1
	print(count)
	l[inl[i]]=1
print("Justice")