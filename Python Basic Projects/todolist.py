# Simple command-line to-do list
tasks = []

while True:
    task = input("Enter a task (or 'quit' to exit): ")
    if task.lower() == 'quit':
        break
    tasks.append(task)

print("Your To-Do List:")
for index, task in enumerate(tasks):
    print(f"{index + 1}. {task}")
