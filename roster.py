import sqlite3
import csv
import sys


if len(sys.argv) != 2:
    sys.exit("Insert house name as command-line argument")

housename = sys.argv[1].lower()
houses = ["slytherin", "gryffindor", "ravenclaw", "hufflepuff"]
if housename.lower() not in houses:
    sys.exit("insert house name: Gryffindor, Hufflepuff, Slytherin or Ravenclaw.")
sqlite_file = "students.db"
connect = sqlite3.connect(sqlite_file)
cursor = connect.cursor()
cursor.execute('SELECT first, middle, last, birth FROM students WHERE lower(house) = "{}" ORDER BY last, first;'.format(housename))
# Fetchall gives us all the rows of the table as a list of tuples with strings.
houseroster = cursor.fetchall()
for row in houseroster:
    if not row[1]:
        print("{} {}, born {}".format(row[0], row[2], row[3]))
    else:
        print("{} {} {}, born {}".format(row[0], row[1], row[2], row[3]))

connect.close()