class Solution:
    # @param A : integer
    # @return an integer
    def sqrt(self, A):
        if A==0:
            return 0
        if A==1 or A==2 or A==3:
            return 1
        l = 1
        h = A//2
        res = -1
        while l<=h:
            m = (l+h)//2
            if m*m>A:
                h = m-1
            elif m*m<=A:
                res = m
                l = m+1
        return res