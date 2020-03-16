class Minstack:
	"""docstring for Minstack"""
	def __init__(self):
		self.stack = []
		self.n = 0
		self.mini = -1

	def getMin(self):
		if self.n == 0:
			return -1
		return self.mini

	def push(self,x):
		if self.n==0:
			self.stack.append(x)
			self.mini = x
		else:
			if x<=self.getMin():
				self.stack.append(2*x-self.getMin())
				self.mini = x
			else:
				self.stack.append(x)
		self.n+=1
		return

	def pop(self):
		if self.n==0:
			return
		tmp = self.stack.pop()
		mn = self.getMin()
		if tmp<=mn:
			self.mini = 2*mn - tmp
		self.n-=1
		return

	def top(self):
		if self.n==0:
			return -1
		tmp = self.stack[self.n-1]
		mn = self.getMin()
		if tmp<=mn:
			return mn
		return tmp

if __name__ == '__main__':
	stack = Minstack()
	stack.push(10)
	stack.push(24)
	stack.push(7)
	stack.push(3)
	stack.push(9)
	stack.push(1)
	stack.push(4)
	stack.push(8)
	print(stack.top(),stack.getMin())
	stack.pop()
	print(stack.top(),stack.getMin())
	stack.pop()
	print(stack.top(),stack.getMin())
	stack.pop()
	print(stack.top(),stack.getMin())
	stack.pop()
	print(stack.top(),stack.getMin())
	stack.pop()
	print(stack.top(),stack.getMin())