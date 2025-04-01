import matplotlib.pyplot as plt
from json import loads

with open("times.json", "r") as f:
    json_data = loads(f.read())

print(json_data)

plt.figure(figsize=(12, 8), dpi=80)
plt.style.use('classic')
plt.plot([0] + list(json_data['brut_force'].keys()), [0] + [val for _, val in json_data['brut_force'].items()],
         'ko-')
plt.plot([0] + list(json_data['ants'].keys()), [0] + [val for _, val in json_data['ants'].items()], 'k*--')
plt.ylabel('Время 10 запусков (сек)')
plt.xlabel('Число вершин в графе')
plt.title("Сравнение методов решения задачи коммивояжера")
plt.legend(['Полный перебор', "Муравьиный алгоритм"], loc='best')
plt.grid(True)
plt.savefig('./all_plot.pdf')
plt.show()
