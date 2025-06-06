getint = lambda: int(input())
getints = lambda: map(int, input().split())

def solve():
	x, y = getints()
	if x == y:
		print(-1)
	else:
		print(2 ** 48 - max(x, y))

t = getint()
for _ in range(t):
	solve()
