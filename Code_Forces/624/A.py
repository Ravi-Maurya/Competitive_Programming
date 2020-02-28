def solve():
	a,b = map(int,input().split())
	if a==b:
		print(0)
	elif a>b:
		y = a-b
		if not y&1:
			print(1)
		else:
			print(2)
	else:
		x = b-a
		if x&1:
			print(1)
		else:
			print(2)
	return

if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		solve();