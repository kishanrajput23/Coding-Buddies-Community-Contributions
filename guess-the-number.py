while True:
    # Import random module.
    import random

    # Choose an upper limit and a lower limit.
    # Use the int function to ensure the value entered is an integer.
    lower_limit = int(input("Enter the lower limit: "))
    upper_limit = int(input("Enter upper limit: "))

    # We select a number randomly and store it in variable
    # The function takes the upper limit and the lower limit as parameters and picks a number between the two numbers.
    # In python, variables can be declared and assigned at the same time
    random_number = random.randint(lower_limit, upper_limit)
    print("You will have to choose a number between ", upper_limit, " and ", lower_limit)

    # We assign a variable "Chances" that will act as the counter for a loop
    # The user will have to input his guess so we assign his guess into a variable.
    chances = 0
    while chances < 8:
        chances += 1
        guess = int(input("Enter your guess: "))
        if random_number == guess:
            print("Congragulations, you did it. The number was ", random_number)
            break
        elif guess < random_number:
            print("You guessed a small number.")
        elif guess > random_number:
            print("You guessed a large number.")
        if chances == 7:
            print("\n You've run out of chances")
            print("\n The number was ", random_number)
            print("Better luck next time")
            break
    print("\n")
    break
