import json
import random

with open('capitals.json', 'r') as f:
    capitals = json.loads(f.read())

# print(capitals)

with open('distances.json', 'r') as f:
    distances = json.loads(f.read())

# print(distances)

n = 10
for kek in range(2, 3):
    cities = set()
    while len(cities) != n:
        cities.add(random.randint(0, len(capitals) - 1))
    # print(cities)
    with open(f'graph{kek}.dot', 'w') as f:
        f.write('graph G{\n')
        for num in cities:
            f.write(f'{num}[label="{capitals[str(num)]}"];\n')

        for num in cities:
            for to in distances[str(num)].keys():
                if int(to) in cities and int(to) > num:
                    f.write(f'{num} -- {to}[label="{round(distances[str(num)][to], 2)}"]\n')
        f.write('}')

    with open(f'graph{kek}.txt', 'w') as f:
        f.write(f'{n} {n * (n - 1) // 2}\n')
        array_cities = list(cities)
        for i in range(len(array_cities)):
            for to in distances[str(array_cities[i])].keys():
                if int(to) in cities and int(to) > array_cities[i]:
                    f.write(f'{i + 1} {array_cities.index(int(to)) + 1} {distances[str(array_cities[i])][to]}\n')
