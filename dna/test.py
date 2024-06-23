import csv
import sys

# Read database file into a variable
database = []
with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        database.append(row)
print(database)
