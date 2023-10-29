class FitnessApp:
    def __init__(self):
        self.steps = 0
        self.calories_burned = 0

    def record_steps(self, num_steps):
        self.steps += num_steps

    def calculate_calories_burned(self):
        # A simple formula to calculate calories burned based on steps
        # You can replace this with a more accurate formula
        self.calories_burned = self.steps // 20

    def display_stats(self):
        print(f"Total Steps: {self.steps}")
        print(f"Calories Burned: {self.calories_burned} calories")

def main():
    fitness_app = FitnessApp()

    while True:
        print("\nFitness App Menu:")
        print("1. Record Steps")
        print("2. Calculate Calories Burned")
        print("3. Display Stats")
        print("4. Quit")

        choice = input("Enter your choice: ")

        if choice == '1':
            num_steps = int(input("Enter the number of steps: "))
            fitness_app.record_steps(num_steps)
            print("Steps recorded!")

        elif choice == '2':
            fitness_app.calculate_calories_burned()
            print("Calories burned calculated!")

        elif choice == '3':
            fitness_app.display_stats()

        elif choice == '4':
            print("Goodbye!")
            break

        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main()
