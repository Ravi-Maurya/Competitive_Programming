# Test set 1 Passed but TLE in other

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

def main():
    t = int(input())
    for test in range(1,t+1):
        n,_,p = map(int,input().split())
        stacks = []
        for _ in range(n):
            tmp = list(map(int,input().split()))
            stacks.append(tmp[::-1])
        print("Case #{}: {}".format(test,find_max_sum(stacks,p)))

if __name__ == "__main__":
    main()