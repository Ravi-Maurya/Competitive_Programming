def fix(v1):
	tmp = v1
	v1 = []
	for i in range(len(tmp)):
		if tmp[i][0]!=0:
			v1.append(tmp[i])
	return v1

def main():
	v = []
	n,m,k = map(int,input().split())
	all = 0
	for i in range(1,n+1):
		v.append((m-1,"R"))
		all += (v[-1][0]*len(v[-1][1]))
		if i==1:
			v.append((m-1,"L"))
		else:
			v.append((m-1,"UDL"))
		all += (v[-1][0]*len(v[-1][1]))
		if i==n:
			v.append((m-1,"U"))
		else:
			v.append((m-1,"D"))
		all += (v[-1][0]*len(v[-1][1]))
	if all<k:
		print("NO")
		return
	while all>k:
		tmp = v[-1][1]
		cur = (v[-1][0]*len(v[-1][1]))
		v.pop()
		all-=cur
		if all>=k:
			continue
		cur = k-all
		if (cur/len(tmp) > 0):
			v.append((cur/len(tmp),tmp))
		tmp = tmp[:cur%len(tmp)]
		if len(tmp)>0:
			v.append((1,tmp))
		all = k
	print("YES")
	v = fix(v)
	print(len(v))
	for i in range(len(v)):
		print(v[i][0],end=" ")
		print(v[i][1])
	return 0

main()