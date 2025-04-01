import matplotlib.pyplot as plt
import matplotlib
from sys import argv

with open(argv[1]) as f:
    binary_values = f.readlines()
for i in range(len(binary_values)):
    binary_values[i] = int(binary_values[i].strip())
with open(argv[2]) as f:
    linear_values = f.readlines()
for i in range(len(linear_values)):
    linear_values[i] = int(linear_values[i].strip())
index = [i for i in range(-1, len(binary_values) - 1)]

print("Среднее число сравнений для бинарного поиска:", sum(binary_values)/len(binary_values))

print("Среднее число сравнений для линейного поиска:", sum(linear_values)/len(linear_values))

plt.figure(figsize=(12, 8), dpi=80)
plt.style.use('classic')
plt.bar(index, binary_values, align='edge')
plt.ylabel('Число сравнений')
plt.xlabel('Индекс на котором находится искомый элемент')
plt.title("Бинарный поиск")
# plt.savefig('./binary.pdf')
plt.show()

plt.figure(figsize=(12, 8), dpi=80)
plt.style.use('classic')
plt.bar(index, linear_values, align='edge')
plt.ylabel('Число сравнений')
plt.xlabel('Индекс на котором находится искомый элемент')
plt.title("Линейный поиск")
# plt.savefig('./linear.pdf')
plt.show()


