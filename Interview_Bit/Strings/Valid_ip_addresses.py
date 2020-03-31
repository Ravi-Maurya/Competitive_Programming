class Solution:
    # @param A : string
    # @return a list of strings
    def isvalid(self,s):
        return len(s)==1 or (s[0]!='0' and int(s)<=255)
    
    def restoreIpAddresses(self, A):
        res = []
        parts = [None]*4
        for i in range(1,min(len(A),4)):
            parts[0] = A[:i]
            if self.isvalid(parts[0]):
                for j in range(1,min(len(A)-i,4)):
                    parts[1] = A[i:i+j]
                    if self.isvalid(parts[1]):
                        for k in range(1,min(len(A)-i-j,4)):
                            parts[2],parts[3] = A[i+j:i+j+k],A[i+j+k:]
                            if self.isvalid(parts[2]) and self.isvalid(parts[3]):
                                res.append('.'.join(parts))
        return res