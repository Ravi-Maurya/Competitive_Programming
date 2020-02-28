T = int(input())
for x in range(1,T+1):
	N,P = map(int, input().split())
	D = list(map(int, input().split()))
	for i in range(N-1,-1,-1):
		if D[i]>P:
			P -= D[i]
			ans[i] = 1
			S += ans[i]*D[i]
			flag = True
			break
		elif P%D[i]!=0:
			ans[i] = 1 + (P//D[i])
			S += ans[i]*D[i]
			P -= ans[i]*D[i]
			flag = True
			break
	if flag:
		print("YES",end = " ")
		for i in range(N-1):
			print(ans[i],end=" ")
		print(ans[N-1])
	else:
		print("NO")