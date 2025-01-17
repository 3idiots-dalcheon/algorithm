n = int(input())
serials = [input().strip() for _ in range(n)]

serials.sort(key=lambda x: (len(x), sum(int(c) for c in x if c.isdigit()), x))

print("\n".join(serials))
