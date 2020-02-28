def solve():
	n,d = map(int,input().split())
	arr = [0 for _ in range(n)]
	sm = [0 for _ in range(n)]
	for i in range(n):
		f = 2*i+1
		s = 2*i+2
		if f<n: 
			arr[f] = i+1
		if s<n:
			arr[s] = i+1
	i = 0
	s = 0
	x = 1
	while i<n:
		tmp = x
		while i<n and x:
			sm[i] = s
			x-=1
			i+=1
		s += 1
		x = tmp*2
	s1 = sum(sm)
	s2 = (n*(n-1))//2
	if d<s1 or d>s2:
		print("NO")
		return
	diff = d-s1
	

if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		solve()