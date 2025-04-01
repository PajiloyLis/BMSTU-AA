from statistics import mean, median, stdev

for i in range(3):
    weights = []
    with open('graph' + str(i) + '.txt') as f:
        n, m = map(int, f.readline().split())
        for j in range(m):
            a, b, c = map(float, f.readline().split())
            weights.append(c)
    print(mean(weights), median(weights), stdev(weights))
