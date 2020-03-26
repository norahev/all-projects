import cs50
from sys import exit, argv

if len(argv) != 2:  # exit if incorrect usage
    print("Incorrect number of command-line arguments")
    exit(1)
db = cs50.SQL("sqlite:///students.db")  # open students database
# list students from corresponding houses
liststudents = db.execute(f"SELECT * FROM students WHERE house = '{argv[1]}' ORDER BY last, first")
middle = ""
for i in liststudents:
    if i['middle'] != None:
        middle = " " + i['middle']
        print(f"{i['first']} {i['middle']} {i['last']}, born in {i['birth']}")
    else:
        middle = ""
        print(f"{i['first']} {i['last']}, born in {i['birth']}")