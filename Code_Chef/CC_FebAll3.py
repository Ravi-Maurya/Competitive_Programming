from collections import deque
x = (-1,0,1,0)
y = (0,1,0,-1)
def bfs(grid,h,w,r,c,val):
	global x,y
	visited = dict()
	count = 0
	q = deque()
	if grid[r][c]<val:
		visited[(r,c)] = True
		count += 1
		for k in range(4):
			nr = r+x[k]
			nc = c+y[k]
			if 0<=nr<h and 0<=nc<w:
				q.append((nr,nc))
	while len(q):
		curr = q.popleft()
		visited[curr] = True
		if grid[curr[0]][curr[1]]<val:
			count += 1
			for k in range(4):
				nr = curr[0]+x[k]
				nc = curr[1]+y[k]
				if 0<=nr<h and 0<=nc<w and visited.get((nr,nc),False)==False and (nr,nc) not in q:
					q.append((nr,nc))
	return count

def main():
	H,W,Q = map(int,input().split())
	grid = []
	for i in range(H):
		grid.append(tuple(map(int,input().split())))
	grid = tuple(grid)
	for i in range(Q):
		r,c,val = map(int,input().split())
		print(bfs(grid, H, W, r-1, c-1, val))
	return

t = int(input())
for _ in range(t):
	main()


# 1
# 5 5 1
# 4 3 9 7 2
# 8 6 5 2 8
# 1 7 3 4 3
# 2 2 4 5 6
# 9 9 9 9 9
# 1 4 9