import matplotlib.pyplot as plt
from json import loads
import os

all_times = {}
data = []
cnt = 0
for file in os.listdir("logs"):
    # print(file)
    with open("logs/" + file, 'r') as f:
        lines = f.readlines()
        if cnt < 3:
            cur_data = loads(lines[0])
            for key, val in cur_data.items():
                all_times[val] = file[:-5] + "_" + key
            cnt += 1
        data.append(loads(lines[0]))
sorted_dict = dict(sorted(all_times.items()))
print(sorted_dict)

with open("log.txt", 'w') as f:
    for key, val in sorted_dict.items():
        f.write(f"{key} {val}\n")

all_time = read_queue_time = parse_queue_time = write_queue_time = log_queue_time = read_time = parse_time = write_time = log_time = 0
for i in range(len(data)):
    all_time += (data[i]["log_queue_pop"] - data[i]["read_queue_push"]) // (149)
    read_queue_time = (data[i]["read_queue_start"] - data[i]["read_queue_push"]) // (149)
    write_queue_time = (data[i]["write_queue_start"] - data[i]["write_queue_push"]) // (149)
    parse_queue_time = (data[i]["parse_queue_start"] - data[i]["parse_queue_push"]) // (149)
    log_queue_time = (data[i]["log_queue_start"] - data[i]["log_queue_push"]) // (149)
    read_time = (data[i]["read_queue_pop"] - data[i]["read_queue_start"]) // (149)
    parse_time = (data[i]["parse_queue_pop"] - data[i]["parse_queue_start"]) // (149)
    write_time = (data[i]["write_queue_pop"] - data[i]["write_queue_start"]) // (149)
    log_time = (data[i]["log_queue_pop"] - data[i]["log_queue_start"]) // (149)
print("\hline")
print(f"Среднее время существования задачи & {all_time}\\\\\\hline")
print(f"Среднее время ожидания в очереди чтения & {read_queue_time}\\\\\\hline")
print(f"Среднее время ожидания в очереди обработки & {parse_queue_time}\\\\\\hline")
print(f"Среднее время ожидания в очереди записи & {write_queue_time}\\\\\\hline")
print(f"Среднее время ожидания в очереди логирования & {log_queue_time}\\\\\\hline")
print(f"Среднее время чтения & {read_time}\\\\\\hline")
print(f"Среднее время обработки & {parse_time}\\\\\\hline")
print(f"Среднее время записи & {write_time}\\\\\\hline")
print(f"Среднее время логирования & {log_time}\\\\\\hline")
