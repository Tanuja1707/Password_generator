# Python program to generate a random password
import random
import string

def generate_password(length):
    letters = string.ascii_letters
    digits = string.digits
    symbols = string.punctuation
    all_chars = letters + digits + symbols

    while True:
        password = ''.join(random.choice(all_chars) for _ in range(length))

        if (password[0] in letters and
            password[-1] not in symbols and
            any(c in digits for c in password) and
            any(c in symbols for c in password)):
            return password

# Input validation loop
while True:
    try:
        length = int(input("Enter password length (min 4): "))
        if length >= 4:
            break
        else:
            print("Length must be at least 4. Try again.")
    except ValueError:
        print("Please enter a valid number.")

print("Generated Password:", generate_password(length))