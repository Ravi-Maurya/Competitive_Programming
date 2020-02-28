def solve():
	n = int(input())
	arr = list(map(int,input().split()))
	left_max = [0]*n; left_max[0] = arr[0]
	right_max = [0]*n; right_max[n-1] = arr[n-1]
	mn = []
	for i in range(1,n):
		left_max[i] = max(left_max[i-1],arr[i-1])
		right_max[n-i-1] = max(right_max[n-i],arr[n-i])
	for i in range(n):
		if left_max[i]>arr[i] and right_max[i]>arr[i]:
			mn.append((arr[i],i))
	mn.sort(key = lambda x: x[0], reverse = True)
	arr2 = arr[:]
	# print(mn)
	for val,idx in mn:
		l = arr[:]
		r = arr[:]
		# print("l")
		for i in range(idx+1,n):
			# print(l,i)
			l[i] = min(val,l[i])
			# print(l)
		sl = sum(l)
		# print(l,sl)
		for i in range(idx):
			r[i] = min(val,r[i])
		sr = sum(r)
		# print(r)
		arr = []
		if sl<sr:
			arr = r[:]
		else:
			arr = l[:]
	# print(arr)
	for i in range(n):
		if i==n-1:
			print(arr[i])
		else:
			print(arr[i],end=" ")
if __name__ == '__main__':
	solve()
