def solve():
	n = int(input())
	mx = -1
	for i in range(n):
		mx = max(mx,int(input()))
	print(mx)
	return
if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		solve();