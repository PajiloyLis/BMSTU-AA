import random

n = 11
m = n * (n - 1) // 2

g = [[] for i in range(n)]

for i in range(n):
    for j in range(i + 1, n):
        g[i].append((j, random.randint(1, 100)))

print("graph G{")
for i in range(n):
    for elem in g[i]:
        print(f"{i + 1} -- {elem[0] + 1} [label={elem[1]}];")
print("}")

print(n, m)
for i in range(n):
    for elem in g[i]:
        print(f"{i + 1} {elem[0] + 1} {elem[1]}")

g_m = [[0] * n for i in range(n)]
for i in range(n):
    for elem in g[i]:
        g_m[i][elem[0]] = elem[1]
        g_m[elem[0]][i] = elem[1]

print("{", end="", sep="")
for i in range(n):
    print('{', end="", sep="")
    for j in range(n):
        print(g_m[i][j], end="", sep="")
        if j != n - 1:
            print(',', end=" ", sep="")
    print("}", end="", sep="")
    if i != n - 1:
        print(",")
print("}", end="", sep="")
