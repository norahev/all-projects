from sys import argv, exit
from csv import reader, DictReader

if len(argv) != 3:  # if user doesn't give 2 command-line arguments send back error message
    print("insert two command-line arguments")
    exit(1)

with open(argv[2]) as DNA_SEQUENCE:  # open text file with dna sewuences
    DNA_SEQUENCE_READER = reader(DNA_SEQUENCE)  # read file
    for row in DNA_SEQUENCE_READER:
        DNA_LIST = row
DNA = DNA_LIST[0]  # store files in a string
SEQUENCES = {}  # dictionary for sequences

with open(argv[1]) as PERSON:  # open csv file
    PERSON_READER = reader(PERSON)  # read file in  list
    for row in PERSON_READER:
        dnaseq = row
        dnaseq.pop(0)
        break

for item in dnaseq:  # the str is the key
    SEQUENCES[item] = 1

for key in SEQUENCES:  # counts repetitions
    k = len(key)
    tmax = 0
    t = 0
    for i in range(len(DNA)):
        while t > 0:
            t -= 1
            continue
        if DNA[i: i + k] == key:
            while DNA[i - k:i] == DNA[i: i +k]:
                t += 1
                i += k
        if t > tmax:
            tmax = t
    SEQUENCES[key] += tmax

with open(argv[1], newline = '') as PERSON:  # go through people like a dictionary and compare sequences
    PERSON_READER = DictReader(PERSON)
    for p in PERSON_READER:
        match = 0
        for DNA in SEQUENCES:
            if SEQUENCES[DNA] == int(p[DNA]):
                match += 1
        if match == len(SEQUENCES):
            print(p['name'])
            exit()
    print("No match")
