



import random

mt = ["Paper","Scissor","Stone"]

	print("Welcome to Stone Paper Scissor Game...")

c = 0

p = 0

i = 0

while (i<10):

	random.shuffle(mt)

	random.shuffle(mt)

	compchoice = random.choice(mt)

	

	plchoice = input("Choose your move\n1 for Stone\n2 for Paper\n3 for Scissor\n")

	

	if plchoice == "1":

		

		if compchoice == "Stone":

			print("Draw\n")

			i = i + 1

			

		if compchoice == "Paper":

			print("You Lose\n")

			i = i + 1

			c = c + 1

			

		if compchoice == "Scissor":

			print("You Win\n")

			i = i + 1

			p = p + 1

			

	if plchoice == "2":

		

		if compchoice == "Stone":

			print("You Win\n")

			i = i + 1

			p = p + 1

			

		if compchoice == "Paper":

			print("Draw\n")

			i = i + 1

			

		if compchoice == "Scissor":

			print("You Lose\n")

			i = i + 1

			c = c + 1

			

	if plchoice == "3":

		

		if compchoice == "Stone":

			print("You Lose\n")

			i = i + 1

			c = c + 1

			

		if compchoice == "Paper":

			print("You Win\n")

			i = i + 1

			p = p + 1

			

		if compchoice == "Scissor":

			print("Draw\n")

			i = i + 1

			

print("Your total points: ",p)

print("Computer's total points: ",c)

if p == c :

	print("DRAW!\n")

if p>c:

	print("CONGRATULATIONS! YOU WON...")

if p<c:

	print("YOU LOSE!\n")

print("Thank you")
