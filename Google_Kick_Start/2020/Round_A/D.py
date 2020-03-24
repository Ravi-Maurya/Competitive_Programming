ALPHABET_SIZE = 26
indexs = 0
class TrieNode: 
	def __init__(self): 
		self.isLeaf = False
		self.children = [None]*ALPHABET_SIZE 
def insert(key, root): 
	pCrawl = root 
	for level in range(len(key)): 
		index = ord(key[level]) - ord('A') 
		if pCrawl.children[index] == None: 
			pCrawl.children[index] = TrieNode() 
		pCrawl = pCrawl.children[index] 
	pCrawl.isLeaf = True

def constructTrie(arr, n, root): 
	for i in range(n): 
		insert(arr[i], root) 

def countChildren(node): 
	count = 0
	for i in range(ALPHABET_SIZE): 
		if node.children[i] != None: 
			count +=1
			global indexs 
			indexs = i 
	return count 
	
def walkTrie(root): 
	pCrawl = root 
	prefix = "" 
	while(countChildren(pCrawl) == 1 and pCrawl.isLeaf == False): 
		pCrawl = pCrawl.children[indexs] 
		prefix += chr(97 + indexs) 
	return prefix

def commonPrefix(arr, n, root): 
	constructTrie(arr, n, root) 
	return walkTrie(root)

def main():
    T = int(input())
    for t in range(1,T+1):
        n,k = map(int,input().split())
        arr = []
        for _ in range(n):
            arr.append(input())
        arr.sort()
        res = 0
        for i in range(0,n,k):
            r = TrieNode()
            res += len(commonPrefix(arr[i:i+k],k,r))
            del r
        print("Case #{}: {}".format(t,res))

if __name__ == "__main__":
    main()