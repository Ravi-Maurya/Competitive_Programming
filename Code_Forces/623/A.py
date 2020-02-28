def solve():
	R,C, x,y = map(int,input().split())
	mx = max(R*y, x*C)
	if y+1!=C:
		mx = max(mx,R*(C-y-1))
	if x+1!=R:
		mx = max(mx,(R-x-1)*C)
	print(mx)


if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		solve()