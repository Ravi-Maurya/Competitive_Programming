def solve():
	l = list(map(int,input().split()))
	l.sort()
	if l[0]==0 and l[1]==0 and l[2]==0:
		print(0)
	elif l[0]==0 and l[1]==0:
		print(1)
	elif l[0]==0:
		if l[1]>=2 and l[2]>=2:
			print(3)
		else:
			print(2)
	elif l[0]==1 and l[1]==1:
		print(3)
	elif l[0]==1:
		print(4)
	elif l[0]==2:
		if l[1]==2 and l[2]==2:
			print(4)
		else:
			print(5)
	elif l[0]==3:
		print(6)
	else:
		print(7)
	return

if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		solve()
