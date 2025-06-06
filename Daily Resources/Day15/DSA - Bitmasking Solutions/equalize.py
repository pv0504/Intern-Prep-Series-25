def min_operations(n, s, t):
    i = 0
    ans = 0
    while i < n:
        if s[i] != t[i]:
            if i + 1 < n and s[i+1] != t[i+1] and s[i] != s[i+1]:
                ans += 1
                i += 2
            else:
                ans += 1
                i += 1
        else:
            i += 1
    return ans

# Example usage
n = int(input())
s = input()
t = input()
print(min_operations(n, s, t))
