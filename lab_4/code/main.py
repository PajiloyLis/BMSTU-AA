import matplotlib.pyplot as plt
from json import loads

with open("measures.json", 'r') as f:
    lines = f.readlines()
json_line = ""
for elem in lines:
    json_line = json_line + elem
data = loads(json_line)
print(data)
plt.scatter([int(key) for key in data.keys()], [elem[1] for elem in data.items()], marker='.', edgecolors='black',
            fc='black')
plt.grid(True)
plt.xlabel("Число потоков")
plt.ylabel("Среднее количество выгружаемых страниц в единицу времени")
plt.show()
