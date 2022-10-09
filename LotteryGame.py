import random

lucky_numbers = []
user_numbers = []

correct_numbers = 0

print('Welcome To Lucky Lottery Numbers')
print('Enter 5 Numbers:')

# For generating random lucky numbers
for num in range(0,5):
    random_num = random.randint(1, 100)
    lucky_numbers.append(random_num)

# For getting user numbers
for num in range(0,5):
    user_num = int(input())
    user_numbers.append(user_num)

# For checking if got any lucky numbers
for lucky_num in lucky_numbers:
    for user_num in user_numbers:
        if user_num == lucky_num:
            correct_numbers = correct_numbers + 1

print(f'You got {correct_numbers} correct numbers')

print(f'Result: {lucky_numbers}')
