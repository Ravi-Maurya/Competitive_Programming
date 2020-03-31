class Solution:
    # @param A : string
    # @return a list of strings
    def prettyJSON(self, A):
        t_count = 0
        ans = []
        n = len(A)
        curr = ''
        for i in range(n-1):
            curr += A[i]
            if A[i]=='{' or A[i] =='[':
                t_count+=1
                ans.append(curr)
                curr = '\t'*t_count
            elif A[i]==',':
                ans.append(curr)
                curr = '\t'*t_count
            elif A[i+1]=='{' or A[i+1]=='[':
                ans.append(curr)
                curr = '\t'*t_count
            elif A[i+1]==']' or A[i+1]=='}':
                t_count-=1
                ans.append(curr)
                curr = '\t'*t_count
        ans.append(A[n-1])
        # print(ans)
        return ans