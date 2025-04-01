for i in range(3):
    with open(f"params{i}.csv", "r") as f:
        # n, m = map(int, f.readline().split())
        # g = [[0] * n for j in range(n)]
        # for j in range(m):
        #     a, b, c = map(float, f.readline().split())
        #     a, b = int(a) - 1, int(b) - 1
        #     g[a][b] = g[b][a] = c
        # for j in range(n):
        #     for k in range(n):
        #         print(round(g[j][k], 1), end="", sep="")
        #         if k != n - 1:
        #             print(" & ", end="", sep="")
        #     print("\\\\", sep="")
        # print()
        with open(f"params_tex{i}.txt", "w") as f1:
            titles = f.readline().split(',')
            f1.write(
                f"{titles[0]} & {titles[1]} & {titles[2]} & {titles[3]} & {titles[4]} & {titles[5]} & {titles[6]} & {titles[7]} \\\\\\hline\n")
            for j in range(10450):
                days, a, b, r, elite, mx, avg, med = map(float, f.readline().split(','))
                days, elite = int(days), int(elite)
                if a in [0.0, 0.2, 0.4, 0.6, 0.8, 1.0] and days <=500:
                    f1.write(f"{days} & {a} & {b} & {r} & {elite} & {mx} & {avg} & {med} \\\\\\hline\n")
