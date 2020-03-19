from cs50 import get_int

while True:
    n = get_int("Height: ")  # prompt user for number
    if n > 0 and n < 9:  # repeats until number fits parameters
        break
for i in range(n)  # rows
    print(" " * ((n - i)-1), end="")  # prints spaces
    print("#" * (i + 1))  # prints #
