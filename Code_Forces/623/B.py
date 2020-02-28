def solve():
	a,b,p = map(int,input().split())
	s = input()
	n = len(s)
	if n==1:
		print(1)
		return
	if n==2:
		if s == 'AA' or s=='AB':
			if a<=p:
				print(1)
				return
			else:
				print(2)
				return
		else:
			if b<=p:
				print(1)
				return
			else:
				print(2)
				return
	i = 0
	dp = [0]*n
	if s[:2]=='AA' or s[:2]=='AB':
		dp[1] = a
	else:
		dp[1] = b
	i = 2
	while i<n:
		if (s[i]!=s[i-1] and s[i-1]==s[i-2])  or s[i]==s[i-1]==s[i-2]:
			dp[i] = dp[i-1]
		elif s[i]!=s[i-1]:
			if s[i-1]=='A':
				dp[i] = dp[i-1]+a
			else:
				dp[i] = dp[i-1]+b
		else:
			if s[i]=='A':
				dp[i] = dp[i-1]+a
			else:
				dp[i] = dp[i-1]+b
		i+=1
	# print(dp)
	if dp[n-1]<=p:
		print(1)
	else:
		t = 0
		s = dp[n-1]
		idx = -1
		i = 0
		while i<n:
			tmp = t # 
			while i<n and dp[i]==t:
				idx = i # 
				i+=1 # 
			if s-tmp<=p:
				break
			if i<n:
				t = dp[i]
		print(idx+1)
	return

if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		solve()