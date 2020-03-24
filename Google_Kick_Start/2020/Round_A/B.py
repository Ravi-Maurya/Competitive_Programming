def find_max_sum(s_arr, n):
    if n == 0:
        return 0
    
    if len(s_arr) == 1:
        return sum(s_arr[0][-n:])
    max_sum = find_max_sum(s_arr[1:], n)
    
    first_stack = s_arr[0]
    for i in range(1,n+1): 
        stack_sum = sum(first_stack[-i:])
        rem_sum = find_max_sum(s_arr[1:], n-i)
        if stack_sum + rem_sum > max_sum:
            max_sum = stack_sum + rem_sum
    
    return max_sum

def knapSack(arr,W):
    n = len(arr)
    k = len(arr[0])
    dp = [[0 for _ in range(W+1)] for _ in range(n+1)]
    for i in range(n+1):
        for j in range(W+1):
            if i==0 or j==0:
                continue
            else:
                pass
    
def main():
    t = int(input())
    for test in range(1,t+1):
        n,k,p = map(int,input().split())
        value = [0]
        wt = [0]
        for _ in range(n):
            tmp = list(map(int,input().split()))
            value.append(tmp[0])
            wt.append(1)
            for j in range(1,k):
                tmp[j] += tmp[j-1]
                value.append(tmp[j])
                wt.append(j+1)
        print(value,wt)
        print("Case #{}: {}".format(test,knapSack(value,wt)))
if __name__ == "__main__":
    main()