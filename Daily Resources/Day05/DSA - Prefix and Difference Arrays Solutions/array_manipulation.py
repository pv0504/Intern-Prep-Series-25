def arrayManipulation(n, queries):
    diff = [0] * (n + 2)  # difference array with extra space

    for a, b, k in queries:
        diff[a] += k
        if b + 1 <= n:
            diff[b + 1] -= k

    max_value = 0
    current = 0
    for i in range(1, n + 1):
        current += diff[i]
        if current > max_value:
            max_value = current

    return max_value
