from collections import deque,defaultdict
import heapq
class Graph:
	def __init__(self,V):
		super(Graph, self).__init__();
		self.graph = defaultdict(set);
		self.V = V;

	def add_edge(self,u,v,weight=1,directed = True):
		self.graph[u].add((v,weight));
		if not directed:
			self.graph[v].add((u,weight));

	def bfs(self,start):
		visited = [False for _ in range(self.V)];
		queue = deque();
		queue.append(start);
		visited[start] = True;
		res = []
		while len(queue):
			node = queue.popleft();
			res.append(node);
			for v,wt in self.graph[node]:
				if not visited[v]:
					queue.append(v);
					visited[v] = True;
		return res;

	def dfs(self,start):
		visited = [False for _ in range(self.V)];
		stack = deque();
		stack.append(start);
		res = []
		while len(stack):
			node = stack.pop();
			if not visited[node]:
				res.append(node);
				visited[node] = True;
				for v,wt in self.graph[node]:
					if not visited[v]:
						stack.append(v);
		return res;

	def dijkstra(self,start):
		distance = [float('inf') for _ in range(self.V)]
		distance[start] = 0
		min_distance = [(0,start)]
		heapq.heapify(min_distance)
		visited = set()
		while min_distance:
			curr_distance,u = heapq.heappop(min_distance)
			if u in visited: continue
			visited.add(u)
			for v,wt in self.graph[u]:
				if v in visited: continue
				if curr_distance + wt < distance[v]:
					distance[v] = curr_distance + wt
					heapq.heappush(min_distance,(distance[v],v))
		return distance

class FloyddWarshal:
	def __init__(self, V):
		super(FloyddWarshal, self).__init__()
		self.V = V
		self.graph = [[float('inf') for _ in range(self.V)] for _ in range(self.V)]
		for i in range(self.V):
			self.graph[i][i] = 0
	
	def add_edge(self,u,v,weight=1,directed=True):
		self.graph[u][v] = weight
		if not directed:
			self.graph[v][u] = weight
	
	def compute(self):
		for k in range(self.V):
			for i in range(self.V):
				for j in range(self.V):
					self.graph[i][j] = min(self.graph[i][j],self.graph[i][k]+self.graph[k][j])
		return self.graph
		

if __name__ == '__main__':
	g = Graph(4);
	g.add_edge(0, 1, weight=1)
	g.add_edge(1, 2, weight=2)
	g.add_edge(2, 3, weight=4) 
	g.add_edge(0, 3, weight=3) 
	print("DFS -> " + str(g.dfs(0)));
	print("BFS -> " + str(g.bfs(0)));
	print("Dijkstra -> " + str(g.dijkstra(0)));

	g = FloyddWarshal(7)
	g.add_edge(0, 1)
	g.add_edge(0, 2)
	g.add_edge(1, 3) 
	g.add_edge(1, 4) 
	g.add_edge(2, 5) 
	g.add_edge(2, 6)
	g.add_edge(4 ,1)
	mat = g.compute()
	print("FloyddWarshal -> ")
	for row in mat:
		print(row)