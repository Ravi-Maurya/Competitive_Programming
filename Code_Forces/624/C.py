def solve():
	res = [0 for i in range(26)]
	n,m = map(int,input().split())
	s = input()
	p = list(map(int,input().split()))
	arr = [0 for i in range(n)]
	for pi in p:
		arr[pi-1] += 1
	if arr[n-1]==0:
		arr[n-1] += 1
	res[ord(s[n-1])-ord('a')] += arr[n-1]
	for i in range(n-2,-1,-1):
		arr[i] += arr[i+1]
		res[ord(s[i])-ord('a')] += arr[i]
	for i in range(26):
		if i==25:
			print(res[i])
		else:
			print(res[i],end=" ")
	return

if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		solve();