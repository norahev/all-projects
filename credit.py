from cs50 import get_string
from sys import exit


def main():
    d1 = 0
    d2 = 0
    num_d = 0
    sum1 = 0
    sum2 = 0
    card = int(get_number())
    while card > 0:
        d2 = d1
        d1 = card % 10

        if num_d % 2 == 0:
            sum2 += d1
        else:
            multiple = 2 * d1
            sum1 += (multiple // 10) + (multiple % 10)

        card //= 10
        num_d += 1

    is_valid = (sum1 + sum2) % 10 == 0
    first_two_digits = (d1 * 10) + d2

    if d1 == 4 and num_d >= 13 and num_d <= 16 and is_valid:
        print("VISA\n")
    elif first_two_digits >= 51 and first_two_digits <= 55 and num_d == 16 and is_valid:
        print("MASTERCARD\n")
    elif (first_two_digits == 34 or first_two_digits == 37) and num_d == 15 and is_valid:
        print("AMEX\n")
    else:
        print("INVALID\n")
    return 0


def get_number():  # function for card number
    while True:
        s = get_string("Insert your credit card number: ")  # prompt user for number
        if len(s) > 0:
            break
    return s


main()