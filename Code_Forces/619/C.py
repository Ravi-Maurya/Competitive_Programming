def solve():
	n,m = map(int,input().split())
	z = n-m
	g = m+1
	k = z//g
	ans = (n*(n+1)/2) - (k*(k+1)*g/2) - ((k+1)*(z%g))
	print(int(ans))

if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		solve()