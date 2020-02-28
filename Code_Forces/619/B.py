def func(arr,n):
	mn = 2**31 -1 
	mx = -2**31
	for i in range(n):
		if i>0 and arr[i]==-1 and arr[i-1]!=-1:
			mn = min(mn,arr[i-1])
			mx = max(mx,arr[i-1])
		if i<n-1 and arr[i] == -1 and arr[i+1]!=-1:
			mn = min(mn,arr[i+1])
			mx = max(mx,arr[i+1])
	if mn == 2**31 -1:
		print(0,0)
		return
	res = (mx+mn)//2
	ans = 0
	for i in range(n):
		if arr[i]==-1:
			arr[i] = res
		if i:
			ans = max(ans,abs(arr[i]-arr[i-1]))
	print(ans,res)
	return

if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		n = int(input())
		arr = list(map(int,input().split()))
		func(arr,n)