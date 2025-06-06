def solve():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        n = int(input())

        unused = set(range(1, n))  # numbers from 1 to n-1
        a = [0] * (n + 1)  # 1-based indexing

        # Find largest power of two <= n
        po2 = 1
        while po2 * 2 <= n:
            po2 *= 2

        if n & 1:
            # n is odd
            print(n)

            low = n & (-n)  # lowest set bit of n
            a[n - 3] = low
            a[n - 2] = low + (2 if low == 1 else 1)
            a[n - 1] = n - low
            a[n] = n
        else:
            # n is even
            print(po2 * 2 - 1)

            if n == po2:
                a[n - 4] = 1
                a[n - 3] = 3
                a[n - 2] = n - 2
                a[n - 1] = n - 1
                a[n] = n
            else:
                a[n - 2] = n
                a[n - 1] = n - 1
                a[n] = po2 - 1

        # Remove assigned numbers from unused set
        for i in range(1, n + 1):
            if a[i] != 0:
                unused.discard(a[i])

        # Fill remaining positions with smallest unused numbers
        unused = sorted(unused)
        idx = 0
        for i in range(1, n + 1):
            if a[i] == 0:
                a[i] = unused[idx]
                idx += 1

        print(*a[1:])


if __name__ == "__main__":
    solve()
