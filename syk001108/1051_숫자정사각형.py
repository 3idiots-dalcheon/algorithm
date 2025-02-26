n, m = map(int, input().split())
grid = [list(map(int, list(input().strip()))) for _ in range(n)]

max_size = 1

for r in range(n):
    for c in range(m):
        for size in range(min(n, m)):
            if r + size < n and c + size < m:
                if (grid[r][c] == grid[r][c + size] == grid[r + size][c] == grid[r + size][c + size]):
                    max_size = max(max_size, (size + 1) ** 2)

print(max_size)
