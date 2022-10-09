#python 3.7.1

import random

def game(comp,player):

  if comp == player:

    return None

  elif comp == 's':

      if player == 'w':

        return False

      elif player == 'g':

        return True

  elif comp == 'w':

      if player == 'g':

        return False

      elif player == 's':

        return True

  elif comp == 'g':

      if player == 's':

        return False

      elif player == 'w':

        return True

            

        

print("computers tern :: snake(s) water(w) gun(g)")

random=random.randint(1,3)

if random == 1:

   comp='s'

elif random == 2:

   comp='w'

elif random == 3:

   comp='g'

player=input("players tern :: snake(s) water(w) gun(g)").lower()

a = game(comp,player)

print(f"computer has choosen {comp}")

print(f"player has choosen {player}")

if a== None:

   print ("tie!!!")

elif a:

   print ("computer lost!!")

   print ("PLAYER HAS WON THE MATCH")

else:

   print ("PLAYER HAS LOST THE MATCH")

   print("computer win!!")

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 
