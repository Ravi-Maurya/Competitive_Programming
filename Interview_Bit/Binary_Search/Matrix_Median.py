from bisect import bisect_right
class Solution:
    # @param A : list of list of integers
    # @return an integer
    def findMedian(self, A):
        r = len(A)
        c = len(A[0])
        mi = A[0][0]
        mx = 0
        for i in range(r):
            mi = min(mi,A[i][0])
            mx = max(mx,A[i][c-1])
        des = (r*c+1)//2
        while mi<mx:
            mid = (mi+mx)//2
            pl = [0]
            for i in range(r):
                j = bisect_right(A[i],mid)
                pl[0] = pl[0]+j
            if pl[0]<des:
                mi=  mid+1
            else:
                mx=mid
        return mi