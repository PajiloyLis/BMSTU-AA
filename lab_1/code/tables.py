from prettytable import PrettyTable, from_csv
from sys import argv

print(argv[1])
with open(argv[1]) as f:
    my_table = from_csv(f, delimiter=',')
print(my_table)
