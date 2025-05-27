if __name__ == "__main__":
    import sys
    input = sys.stdin.readline

    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))

    operations = []
    for _ in range(m):
        l, r, d = map(int, input().split())
        operations.append((l, r, d))

    op_count = [0] * (m + 2)
    for _ in range(k):
        x, y = map(int, input().split())
        op_count[x] += 1
        if y + 1 <= m:
            op_count[y + 1] -= 1

    # Compute how many times each operation is applied
    for i in range(1, m + 1):
        op_count[i] += op_count[i - 1]

    # Apply all operations using a difference array
    delta = [0] * (n + 2)
    for i in range(m):
        l, r, d = operations[i]
        times = op_count[i + 1]
        delta[l] += d * times
        if r + 1 <= n:
            delta[r + 1] -= d * times

    # Build final array
    for i in range(1, n + 1):
        delta[i] += delta[i - 1]
        a[i - 1] += delta[i]

    print(" ".join(map(str, a)))
