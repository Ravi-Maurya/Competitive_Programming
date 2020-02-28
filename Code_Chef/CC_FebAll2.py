def solve():
	n = int(input())
	A = list(map(int,input().split()))
	ne = 0
	no = 0
	for i in range(n):
		if A[i]&1:
			no+=1
		else:
			ne+=1
	print(no*ne)
	return

if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		solve();