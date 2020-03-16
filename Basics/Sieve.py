from bisect import bisect_right
class Sieve:
	"""Sieve of Erasthanos in O(N) time"""
	def __init__(self, n):
		self.n = n
		self.isPrime = [True]*(self.n+1)
		self.spf = [0]*(self.n+1)
		self.primes = []

	def modified_sieve(self):
		self.isPrime[0] = self.isPrime[1] = False
		self.spf[1] = 1
		for i in range(2,self.n+1):
			if self.isPrime[i]:
				self.primes.append(i)
				self.spf[i] = i
			j = 0
			while j<len(self.primes) and i*self.primes[j]<=self.n and self.primes[j]<=self.spf[i]:
				self.isPrime[j] = False
				self.spf[i*self.primes[j]] = self.primes[j]
				j+=1
		return

	def count_primes(self,k):
		"""Note ->
			This Counts number of primes of any k <= N in O(log(count of primes till N)) time
		"""
		return bisect_right(self.primes,k)