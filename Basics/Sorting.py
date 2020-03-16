class Sorting:
	def merge(self,arr,l,m,r):
		tmp = [0]*(r-l+1)
		i = l
		j = m+1
		k = 0
		while i<=m and j<=r:
			if arr[i]<=arr[j]:
				tmp[k] = arr[i]
				k+=1
				i+=1
			else:
				# inversion i.e. swap will happen so inversion+= (m-i+1)
				tmp[k] = arr[j]
				k+=1
				j+=1

		while i<=m:
			tmp[k] = arr[i]
			k+=1
			i+=1

		while j<=r:
			tmp[k] = arr[j]
			k+=1
			j+=1
		for i in range(l,r+1):
			arr[i] = tmp[i-l]
		return arr

	def mergesort(self,arr,l,r):
		if l<r:
			mid = (l+r)//2
			arr = self.mergesort(arr,l,mid)
			arr = self.mergesort(arr,m++1,r)
			arr = self.merge(arr,l,mid,r)
		return arr

	def partition(self,arr,l,h):
		i = l-1
		pi = arr[h]

		for j in range(l,h):
			if arr[j]<pi:
				i+=1
				arr[i],arr[j] = arr[j],arr[i]
		arr[i+1],arr[h] = arr[h],arr[i+1]
		return i+1,arr

	def quicksort(self,arr,l,h):
		if l<h:
			pi,arr = self.partition(arr,l, h)
			arr = self.quicksort(arr, l, pi-1)
			arr = self.quicksort(arr, pi+1,h)
		return arr