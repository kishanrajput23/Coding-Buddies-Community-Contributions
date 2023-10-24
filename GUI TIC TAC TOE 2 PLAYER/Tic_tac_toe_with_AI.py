import tkinter as tk
from tkinter import messagebox

# Initialize the game
def initialize_game():
    global player
    player = "X"
    for i in range(3):
        for j in range(3):
            buttons[i][j]["text"] = ""
            buttons[i][j]["state"] = "active"

# Check for a win or tie
def check_win():
    for i in range(3):
        if buttons[i][0]["text"] == buttons[i][1]["text"] == buttons[i][2]["text"] != "":
            buttons[i][0].config(bg="yellow")
            buttons[i][1].config(bg="yellow")
            buttons[i][2].config(bg="yellow")
            return True

    for i in range(3):
        if buttons[0][i]["text"] == buttons[1][i]["text"] == buttons[2][i]["text"] != "":
            buttons[0][i].config(bg="yellow")
            buttons[1][i].config(bg="yellow")
            buttons[2][i].config(bg="yellow")
            return True

    if buttons[0][0]["text"] == buttons[1][1]["text"] == buttons[2][2]["text"] != "":
        buttons[0][0].config(bg="yellow")
        buttons[1][1].config(bg="yellow")
        buttons[2][2].config(bg="yellow")
        return True

    if buttons[0][2]["text"] == buttons[1][1]["text"] == buttons[2][0]["text"] != "":
        buttons[0][2].config(bg="yellow")
        buttons[1][1].config(bg="yellow")
        buttons[2][0].config(bg="yellow")
        return True

    if all(button["text"] != "" for row in buttons for button in row):
        messagebox.showinfo("Tic-Tac-Toe", "It's a tie!")
        initialize_game()
        return True

    return False

# Handle a button click for a 2-player game
def button_click(row, col):
    global player
    if buttons[row][col]["text"] == "":
        buttons[row][col]["text"] = player
        buttons[row][col]["state"] = "disabled"
        if check_win():
            messagebox.showinfo("Tic-Tac-Toe", f"Player {player} wins!")
            initialize_game()
        player = "X" if player == "O" else "O"

# Create the main window
root = tk.Tk()
root.title("Tic-Tac-Toe")

# Create buttons
buttons = [[None, None, None], [None, None, None], [None, None, None]]
for i in range(3):
    for j in range(3):
        buttons[i][j] = tk.Button(root, text="", width=10, height=3, font=("Arial", 20), command=lambda i=i, j=j: button_click(i, j))
        buttons[i][j].grid(row=i, column=j)

# Initialize the game
initialize_game()

root.mainloop()
