from cs50 import get_float

def main():
    change = get_change()  # prompts user for correct change
    n = round(change * 100)  # rounds number
    a = 25
    b = 10
    c = 5
    d = 1
    i = 0  # counter for coins
    while n > 0:  # loop for counting the change
        if n >= a:
            i = i + 1
            n = n - a
        elif n >= b:
            i = i + 1
            n = n - b
        elif n >= c:
            i = i + 1
            n = n - c
        elif n >= d:
            i = i + 1
            n = n - d
    print(i)

def get_change():  # function for userprompt
    while True:
        n = get_float("How much change is owed?\n")
        if n > 0.009:
            break
    return n

main()