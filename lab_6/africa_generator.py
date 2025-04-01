import json
from random import *
from math import sin, cos, radians, atan2, sqrt, hypot

capitals = {0: "Algiers", 1: "Luanda", 2: "Porto-Novo", 3: "Gaborone", 4: "Ouagadougou", 5: "Gitega", 6: "Yaounde",
            7: "Praia", 8: "Bangui", 9: "N'Djamena", 10: "Moroni", 11: "Kinshasa", 12: "Brazzaville", 13: "Djibouti",
            14: "Cairo", 15: "Malabo", 16: "Asmara", 17: "Mbabane", 18: "Adis Ababa", 19: "Liberville", 20: "Banjul",
            21: "Accra", 22: "Conakry", 23: "Bissau", 24: "Yamoussoukro", 25: "Nairobi", 26: "Maseru", 27: "Monrovia",
            28: "Tripoli", 29: "Antananarivo", 30: "Lilongwe", 31: "Bamako", 32: "Nouakchott", 33: "Port Louis",
            34: "Rabat", 35: "Maputo", 36: "Windhoek", 37: "Niamey", 38: "Abuja", 39: "Kigali", 40: "Sao Tome",
            41: "Dakar", 42: "Victoria", 43: "Freetown", 44: "Mogadishu", 45: "Cape Town", 46: "Juba", 47: "Khartoum",
            48: "Dodoma", 49: "Lome", 50: "Tunis", 51: "Kampala", 52: "Lusaka", 53: "Harare"}
coords = {0: (36.7325, 3.087222), 1: (-8.838333, 13.234444), 2: (6.497222, 2.605), 3: (-24.658056, 25.912222),
          4: (12.368611, -1.5275), 5: (-3.428333, 29.925), 6: (3.866667, 11.516667), 7: (14.918, -23.509),
          8: (4.373333, 18.562778), 9: (12.105278, 15.044722), 10: (-11.699, 43.256), 11: (-4.321944, 15.311944),
          12: (-4.266667, 15.266667), 13: (11.594444, 43.148056), 14: (30.044444, 31.235833), 15: (3.745556, 8.774444),
          16: (15.335833, 38.941111), 17: (-26.326111, 31.143889), 18: (9.03, 38.74), 19: (0.390278, 9.454167),
          20: (13.458056, -16.578611), 21: (5.55, -0.2), 22: (9.509167, -13.712222), 23: (11.85, -15.566667),
          24: (6.816111, -5.274167), 25: (-1.286389, 36.817222), 26: (-29.315, 27.486944), 27: (6.313333, -10.801389),
          28: (32.887222, 13.191389), 29: (-18.91, 47.525), 30: (-13.983333, 33.783333), 31: (12.639167, -8.002778),
          32: (18.085278, -15.9725), 33: (-20.164444, 57.541666), 34: (34.033333, -6.833333),
          35: (-25.966667, 32.583333), 36: (-22.57, 17.083611), 37: (13.513611, 2.108889), 38: (9.066667, 7.483333),
          39: (-1.943889, 30.059444), 40: (0.336111, 6.730556), 41: (14.692778, -17.446667), 42: (-4.623056, 55.4525),
          43: (8.484444, -13.234444), 44: (2.039167, 45.341944), 45: (-29.116667, 26.216667), 46: (4.853889, 31.5825),
          47: (15.6, 32.5), 48: (-6.173056, 35.741944), 49: (6.130833, 1.215278), 50: (36.806389, 10.181667),
          51: (0.313611, 32.581111), 52: (-15.416667, 28.283333), 53: (-17.829167, 31.052222)}

distances = {i: {} for i in range(len(capitals))}

radius = 6371.032
for i in range(len(capitals)):
    z_i = sin(radians(coords[i][0]))
    x_i = cos(radians(coords[i][1]))
    y_i = sin(radians(coords[i][1]))
    for j in range(len(capitals)):
        if i != j:
            z_j = sin(radians(coords[j][0]))
            x_j = cos(radians(coords[j][1]))
            y_j = sin(radians(coords[j][1]))
            angle = atan2(hypot((y_i * z_j - y_j * z_i), (x_i * z_j - x_j * z_i), (x_i * y_j - x_j * y_i)),
                          x_i * x_j + y_i * y_j + z_i * z_j)
            distances[i][j] = angle * radius

with open("capitals.json", 'w') as f:
    f.write(json.dumps(capitals))

with open('coords.json', 'w') as f:
    f.write(json.dumps(coords))

with open('distances.json', 'w') as f:
    f.write(json.dumps(distances))
