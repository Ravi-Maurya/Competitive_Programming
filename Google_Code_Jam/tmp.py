from itertools import *  # We will be using itertools.permutations and itertools.product
def f(n):  # Function taking the side length as a parameter
      s = range(n)  # Generate all the numbers from 0 to n-1
      l = len  # Shortcut to compute size of sets
      for r in permutations(product(s, s)):  # Generate all permutations of all pairs (Cartesian product) of those numbers, for each permutation:
            if all([l({x[0] for x in r[i * n : (- ~ i) * n]})* l({x[1] for x in r[i * n:(- ~ i) * n]})* l({r[j * n + i][0] for j in s})* l({r[j * n + i][1] for j in s})== n ** 4 for i in s]):
                  return r
if __name__ == "__main__":
    print(f(4))