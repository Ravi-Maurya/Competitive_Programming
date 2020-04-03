def main():
	T = int(input())
	for x in range(1,T+1):
		# dx = dict()
		# dy = dict()
		nx,ny = map(int,input().split())
		X = set(map(int,input().split()))
		# for i in X:
		# 	dx[i] = True
		Y = set(map(int,input().split()))
		# for i in Y:
		# 	dy[i] = True
		ans = 0
		zero = False
		for i in X:
			for j in Y:
				if (i>0 and j>0) or (i<0 and j<0):
					yd = -1.0 * (i*i/j)
					xd = -1.0 * (j*j/i)
					# if dy.get(yd,False):
					# 	ans+=1
					# if dx.get(xd,False):
					# 	ans+=1
					if yd in Y:
						ans+=1
					if xd in X:
						ans+=1
				elif i==0 and not zero:
					zero = True
					ans += (nx-1)*ny
				elif j==0 and not zero:
					zero = True
					ans += (ny-1)*nx
		print(ans)

main();