class Solution:
    # @param A : tuple of integers
    # @param B : tuple of integers
    # @param C : tuple of integers
    # @return an integer
    def minimize(self, A, B, C):
        a = len(A)
        b = len(B)
        c = len(C)
        i = j = k =0
        ans = 2**31 -1
        while i<a and j<b and k<c:
            d1 = abs(A[i]-B[j])
            d2 = abs(B[j]-C[k])
            d3 = abs(C[k]-A[i])
            tmp = max(d1,d2,d3)
            ans = min(ans,tmp)
            if tmp==d1:
                if A[i]==min(A[i],B[j]):
                    i+=1
                else:
                    j+=1
            elif tmp==d2:
                if B[j]==min(B[j],C[k]):
                    j+=1
                else:
                    k+=1
            else:
                if C[k]==min(C[k],A[i]):
                    k+=1
                else:
                    i+=1
        return ans