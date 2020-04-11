from sys import stdin
def main():
    n = int(stdin.readline())
    arr = list(map(int, stdin.readline().split()))
    res = 0
    for i in range(n):
        curr = 1
        for j in range(i,n):
            curr *= abs(arr[j])
            if curr%4 != 2:
                res += 1
    print(res)
    return


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        main()