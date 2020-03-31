class Solution:
    def gcd(self, A, B):
        if (B > A):
            A, B = B, A
        if (B == 0):
            return A
        return self.gcd(B, A % B)
 
    def solve(self, A):
        ans = 1
        for k in A:
            for i in range(1, 1000000000):
                if (((i * (i + 1)) // 2) % len(k) == 0):
                    ans = ((ans * i) // self.gcd(ans, i))
                    break
        return (ans % 1000000007)