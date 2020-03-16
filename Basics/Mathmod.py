class Math:
	def gcd(self,a,b):
		if b==0:
			return a
		return self.gcd(b,a%b)

	def lcm(self,a,b):
		return a*b//self.gcd(a, b)

	def primality_test(self,n):
		if n<=1:
			return False
		if n<=3:
			return True
		if n%2==0 or n%3==0:
			return False
		i = 5
		while i*i<=n:
			if n%i==0 or n%(i+2)==0:
				return False
			i+=6
		return True

	def powermod(self,a,n,p):
		""" a^n % p"""
		res = 1
		a = a%p
		while n>0:
			if n&1:
				res = (res*a)%p
			n >>= 1
			a = (a*a)%p
		return res