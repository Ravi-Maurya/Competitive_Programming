def check(a,b,c,n):
	for i in range(n):
		if c[i]!=a[i] and c[i]!=b[i]:
			print("NO")
			return
	print("YES")
	return

if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		a = input()
		b = input()
		c = input()
		n = len(a)
		check(a,b,c,n)