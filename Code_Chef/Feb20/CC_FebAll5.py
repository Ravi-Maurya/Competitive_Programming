class Graph:
	def __init__(self, vertices):
		super(Graph, self).__init__()
		self.V = vertices
		self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]
	def min_dist(self,dist,sptSet):
		mn = float('inf')
		mi = -1
		for v in range(self.V):
			if dist[v]<mn and sptSet[v]==False:
				mn = dist[v]
				mi = v
		return mi
	
	def dijkstra(self,src,dest,depend):
		dist = [float('inf')]*self.V
		dist[src] = 0
		sptSet = [False]*self.V
		for i in range(self.V):
			u = self.min_dist(dist,sptSet)
			if u==-1:
				return -1
			if depend.get(u,-1)!=-1 and sptSet[depend[u]]==False:
				dist[u] = float('inf')
				continue
			sptSet[u] = True
			if sptSet[dest]:
				return dist[dest]
			for v in range(self.V):
				if self.graph[u][v]>0 and sptSet[v]==False and dist[v]>dist[u]+self.graph[u][v]:
					dist[v] = dist[u]+self.graph[u][v]
		return -1


def main():
	N,E,K = map(int,input().split())
	adj_mat = [[0 for _ in range(N)] for _ in range(N)]
	for _ in range(E):
		r,c,w = map(int,input().split())
		adj_mat[r-1][c-1] = w
		adj_mat[c-1][r-1] = w
	depend = dict()
	for _ in range(K):
		L,U = map(int,input().split())
		depend[U-1] = L-1
	g = Graph(N)
	g.graph = adj_mat
	print(g.dijkstra(0,N-1,depend))	

if __name__ == '__main__':
	main()