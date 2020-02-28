def insertion_sort(arr):
	# Worst : n^2
	# Best  : n
	# Avg   : n^2
	for i in range(1,len(arr)):
		key = arr[i]
		j = i-1
		while j>=0 and key<arr[j]:
			arr[j+1] = arr[j]
			j -= 1
		arr[j+1] = key

	return arr

def merge_sort(arr):
	def merge(arr,st,mid,end):
		tmp = [0]*(end-st+1)
		i, j, k = st, mid+1, 0

		while i<=mid and j<=end:
			if arr[i] <= arr[j]:
				tmp[k] = arr[i]
				k +=1
				i += 1
			else:
				tmp[k] = arr[j]
				k +=1
				j += 1

		while i<=mid:
			tmp[k] = arr[i]
			k += 1
			i += 1

		while j<=end:
			tmp[k] = arr[j]
			k += 1
			j += 1
		for i in range(st,end+1):
			arr[i] = tmp[i-st]


	def msort(arr,st,end):
		if st<end:
			mid = int((st+end)/2)
			msort(arr,st,mid)
			msort(arr,mid+1,end)
			merge(arr,st,mid,end)

	msort(arr,0,len(arr))
	return arr

def quick_sort(arr):
	def partition(arr, l, h):
		i = l-1
		p = arr[h]
		for j in range(l,h):
			if arr[j]<=p:
				i = i+1
				arr[i],arr[j] = arr[j],arr[i]
		arr[i+1],arr[h] = arr[h],arr[i+1]
		return i+1

	def qsort(arr,l,h):
		if l<h:
			pi = partition(arr,l,h)
			qsort(arr,l,pi-1)
			qsort(arr,pi+1,h)

	qsort(arr,0,len(arr))
	return arr
