class Solution:
    # @param A : list of integers
    # @return a list of integers
    def maxset(self, A):
        tp = []
        i = 0
        s = -1
        length = len(A)
        while i<length:
            if A[i] < 0:
                i += 1
            else:
                temp = []
                while i<length and A[i]>=0:
                    temp.append(A[i])
                    i += 1
                if sum(temp)>s:
                    s = sum(temp)
                    tp = temp
        return tp