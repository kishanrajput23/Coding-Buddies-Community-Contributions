def halfPyramid():

    for i in range(5):

        for j in range(i+1):

            print(end="* ")

        print()

def invertedHalfPyramid():

    for i in range(5):

        for j in range(i, 5):

            print(end="* ")

        print()

def fullPyramid():

    for i in range(5):

        for s in range(5, i+1, -1):

            print(end=" ")

        for j in range(i + 1):

            print(end="* ")

        print()

def invertedFullPyramid():

    for i in range(5):

        for s in range(i):

            print(end=" ")

        for j in range(i, 5):

            print(end="* ")

        print()

while True:

    print("1. Print Half Pyramid of Stars")

    print("2. Print Inverted Half Pyramid of Stars")

    print("3. Print Full Pyramid of Stars")

    print("4. Print Inverted Full Pyramid of Stars")

    print("5. Exit")

    print("Enter Your Choice: ", end="")

    choice = int(input())

    if choice==1:

        halfPyramid()

    elif choice==2:

        invertedHalfPyramid()

    elif choice==3:

        fullPyramid()

    elif choice==4:

        invertedFullPyramid()

    elif choice==5:

        print("Exiting...")

        break

    else:

        print("Wrong Choice!")
