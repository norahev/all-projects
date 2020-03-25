import csv
from sys import argv, exit
import sqlite3


if len(argv) != 2:
    print("Incorrect number of command-line arguments")
    exit(1)

file = argv[1]
s_file = "students.db"
connect = sqlite3.connect(s_file)
cursor = connect.cursor()
with open("characters.csv", "r") as characters:
    reader = csv.DictReader(characters)
    for row in reader:
        name = []
        for part in row["name"].split(" "):
            name.append(part)
            name.append(row["house"])
            name.append(row["birth"])
            if len(name) == 5:
                cursor.execute ("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", name[:5])
            if len(name) == 4:
                cursor.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)", name[:4])
connect.commit()
connect.close()
