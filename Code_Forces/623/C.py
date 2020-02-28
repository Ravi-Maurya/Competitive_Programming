import heapq as pq
def solve():
	n = int(input())
	A = list(map(int,input().split()))
	d = dict()
	arr = [0 for _ in range(2*n)]
	for i in range(n):
		d[A[i]] = i
		arr[2*i] = A[i]
		A[i] = (A[i],i)
	remaining = []
	pq.heapify(remaining)
	for i in range(1,(2*n)+1):
		if d.get(i,-1)==-1:
			pq.heappush(remaining,i)
	# print("sds")
	# print(A,arr,remaining)
	A.sort(key = lambda x: x[0])
	r = []
	pq.heapify(r)
	for i in range(n):
		curr1 = pq.heappop(remaining)
		pq.heappush(r,curr1)
		if A[i][0]>curr1:
			print(-1)
			return
		
	A.sort(key = lambda x: x[0]+x[1])
	for i in range(n):
		curr1 = pq.heappop(r)
		arr[(2*d.get(A[i][0]))+1] = curr1

	for i in range(2*n):
		if i==(2*n)-1:
			print(arr[i])
		else:
			print(arr[i],end=" ")
	return


if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		solve()