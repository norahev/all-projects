import cs50
from sys import exit, argv

if len(argv) != 2:  # exit if incorrect usage
    print("Incorrect number of command-line arguments")
    exit(1)
#if argv[1] != 'Gryffindor' or argv[1] != 'Hufflepuff' or argv[1] != 'Slytherin' or argv[1] != 'Ravenclaw':
   # print("Please enter correct house name")
   # exit(1)
db = cs50.SQL("sqlite:///students.db")  # open students database
liststudents = db.execute(f"SELECT * FROM students WHERE house = '{argv[1]}' ORDER BY last, first")  # list students from corresponding houses

middle = ""
for i in liststudents:
    if i['middle'] != None:
        middle = " " + i['middle']
    else:
        middle = None
    print(f"{i['first']} {i['middle']} {i['last']}, born in {i['birth']}")

