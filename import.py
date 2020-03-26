import csv
from sys import argv, exit
import cs50
import string

if len(argv) != 2 or argv[1].endswith('.csv') == False:  # error if incorrect command line argument
    print("Incorrect command-line arguments")
    exit(1)

db = cs50.SQL("sqlite:///students.db")  # open students database
characters = []  # creating list
csvfile = argv[1]
with open (csvfile, "r") as char:  # store csv file in list
    characters = list(csv.reader(char))
    characters.pop(0)  # remove all the headings
    for row in characters:
        name = row[0].split()  # splitting the names
        if len(name) == 3:
            db.execute(f"INSERT INTO students (first, middle, last, house, birth) VALUES ('{name[0]}', '{name[1]}', '{name[2]}', '{row[1]}', '{row[2]}')")
        else:
            db.execute(f"INSERT INTO students (first, middle, last, house, birth) VALUES ('{name[0]}', None , '{name[1]}', '{row[1]}', '{row[2]}')")


