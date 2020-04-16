import math

def read_ints():
    return list(map(int, input().split(" ")))

class Arr:
    def __init__(self, n):
        self._n = n
        self._dist_to_next = [None] * n
        self._dist_to_prev = [None] * n
        self._first = None
    def set(self, i):
        self._dist_to_next[i] = 0
        self._dist_to_prev[i] = 0
        if self._first is None:
            self._first = i
    def build(self):
        if self._first is None:
            for i in range(self._n):
                self._dist_to_next[i] = math.inf
                self._dist_to_prev[i] = math.inf
        else:
            d = None
            for _i in range(self._n-1, -1, -1):
                i = (_i+1 + self._first) % self._n
                if self._dist_to_next[i] is not None:
                    d = self._dist_to_next[i]
                else:
                    assert d is not None
                    self._dist_to_next[i] = d
                d += 1
            d = None
            for _i in range(self._n):
                i = (_i + self._first) % self._n
                if self._dist_to_prev[i] is not None:
                    d = self._dist_to_prev[i]
                else:
                    assert d is not None
                    self._dist_to_prev[i] = d
                d += 1
    def dist_to_next(self, i):
        return self._dist_to_next[i]
    def dist_to_prev(self, i):
        return self._dist_to_prev[i]

def main():
    for ti in range(int(input())):
        n, g, t = read_ints()
        guests = []
        clock = Arr(n)
        anti = Arr(n)
        for _ in range(g):
            hi, diri = input().split(" ")
            hi = int(hi) - 1
            if diri == "C":
                hi = (hi + t) % n
                clock.set(hi)
            else:
                hi = (hi - t) % n
                anti.set(hi)
            guests.append((hi, diri))
        clock.build()
        anti.build()
        clock_scores = [0] * n
        anti_scores = [0] * n
        for i in range(n):
            d_c = clock.dist_to_next(i)
            d_a = anti.dist_to_prev(i)
            if d_c <= d_a and d_c <= t:
                clock_scores[(i + d_c) % n] += 1
            if d_a <= d_c and d_a <= t:
                anti_scores[(i - d_a) % n] += 1
        ans = []
        for (hi, diri) in guests:
            if diri == "C":
                ans.append(clock_scores[hi])
            else:
                ans.append(anti_scores[hi])
        print("Case #{}: {}".format(ti+1, " ".join(map(str, ans))))

if __name__ == "__main__":
    main()