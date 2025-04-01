import matplotlib.pyplot as plt
import matplotlib
import pandas as pd
from sys import argv

# with open(argv[1]) as f:
#     binary_values = f.readlines()
# for i in range(len(binary_values)):
#     binary_values[i] = int(binary_values[i].strip())
# with open(argv[2]) as f:
#     linear_values = f.readlines()
# for i in range(len(linear_values)):
#     linear_values[i] = int(linear_values[i].strip())
standard = pd.read_csv(argv[1])
# strassen = pd.read_csv(argv[2])
winograd = pd.read_csv(argv[3])
winograd_opt = pd.read_csv(argv[4])

plt.figure(figsize=(12, 8), dpi=80)
plt.style.use('classic')
plt.plot([0]+list(standard['n']), [0]+list(standard['t']), 'ko-')
plt.ylabel('Время 10 запусков (сек)')
plt.xlabel('Размер матрицы')
plt.title("Сравнение алгоритмов умножения матриц")
# plt.plot(list(strassen['n']), list(strassen['t']), 'kx--')
plt.plot([0]+list(winograd['n']), [0]+list(winograd['t']), 'k*-')
plt.plot([0]+list(winograd_opt['n']), [0]+list(winograd_opt['t']), 'k^-')
plt.legend(['Стандартный алгоритм', "Алгоритм Винограда", "Алгоритм Винограда\nоптимизированный"], loc='best')
plt.savefig('./all_plot.pdf')
plt.grid(True)
plt.show()
