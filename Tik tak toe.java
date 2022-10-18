

GEEKSFORGEEKS
Tic-Tac-Toe Game in Java
In the Tic-Tac-Toe game, you will see the approach of the game is implemented. In this game, two players will be played and you have one print board on the screen where from 1 to 9 number will be displayed or you can say it box number. Now, you have to choose X or O for the specific box number. For example, if you have to select any number then for X or O will be shown on the print board, and turn for next will be there. The task is to create a Java program to implement a 3×3 Tic-Tac-Toe game for two players.

 Game board :

      |---|---|---|        
      | 1 | 2 | 3 |
      |-----------|
      | 4 | 5 | 6 |
      |-----------|
      | 7 | 8 | 9 |
      |---|---|---|  
Sample Input :

Enter a slot number to place X in: 3 



Sample Output :

      |---|---|---|        
      | 1 | 2 | X |
      |-----------|
      | 4 | 5 | 6 |
      |-----------|
      | 7 | 8 | 9 |
      |---|---|---|  
Sample Input :

Now, O’s turn, Enter a slot number to place O in: 5

Sample Output :

      |---|---|---|        
      | 1 | 2 | X |
      |-----------|
      | 4 | O | 6 |
      |-----------|
      | 7 | 8 | 9 |
      |---|---|---|  
So, like this game will be continued.

How to Play the Game :

Both the players choose either X or O to mark their cells.
There will be a 3×3 grid with numbers assigned to each of the 9 cells.
The player who chose X begins to play first.
He enters the cell number where he wishes to place X.
Now, both O and X play alternatively until any one of the two wins.
Winning criteria: Whenever any of the two players has fully filled one row/ column/ diagonal with his symbol (X/ O), he wins and the game ends.
If neither of the two players wins, the game is said to have ended in a draw.
Below is the implementation of the game in Java :

// A simple program to demonstrate  
// Tic-Tac-Toe Game. 

import java.util.*; 

  

public class GFG { 

    

    static String[] board; 

    static String turn; 

    

    

    // CheckWinner method will  

    // decide the combination  

    // of three box given below. 

    static String checkWinner() 

    { 

        for (int a = 0; a < 8; a++) { 

            String line = null; 

  

            switch (a) { 

            case 0: 

                line = board[0] + board[1] + board[2]; 

                break; 

            case 1: 

                line = board[3] + board[4] + board[5]; 

                break; 

            case 2: 

                line = board[6] + board[7] + board[8]; 

                break; 

            case 3: 

                line = board[0] + board[3] + board[6]; 

                break; 

            case 4: 

                line = board[1] + board[4] + board[7]; 

                break; 

            case 5: 

                line = board[2] + board[5] + board[8]; 

                break; 

            case 6: 

                line = board[0] + board[4] + board[8]; 

                break; 

            case 7: 

                line = board[2] + board[4] + board[6]; 

                break; 

            } 

            //For X winner 

            if (line.equals("XXX")) { 

                return "X"; 

            } 

              

            // For O winner 

            else if (line.equals("OOO")) { 

                return "O"; 

            } 

        } 

          

        for (int a = 0; a < 9; a++) { 

            if (Arrays.asList(board).contains( 

                    String.valueOf(a + 1))) { 

                break; 

            } 

            else if (a == 8) { 

                return "draw"; 

            } 

        } 

  

       // To enter the X Or O at the exact place on board. 

        System.out.println( 

            turn + "'s turn; enter a slot number to place "

            + turn + " in:"); 

        return null; 

    } 

      

    // To print out the board. 

    /* |---|---|---| 

       | 1 | 2 | 3 | 

       |-----------| 

       | 4 | 5 | 6 | 

       |-----------| 

       | 7 | 8 | 9 | 

       |---|---|---|*/

    

    static void printBoard() 

    { 

        System.out.println("|---|---|---|"); 

        System.out.println("| " + board[0] + " | "

                           + board[1] + " | " + board[2] 

                           + " |"); 

        System.out.println("|-----------|"); 

        System.out.println("| " + board[3] + " | "

                           + board[4] + " | " + board[5] 

                           + " |"); 

        System.out.println("|-----------|"); 

        System.out.println("| " + board[6] + " | "

                           + board[7] + " | " + board[8] 

                           + " |"); 

        System.out.println("|---|---|---|"); 

    } 

  

    public static void main(String[] args) 

    { 

        Scanner in = new Scanner(System.in); 

        board = new String[9]; 

        turn = "X"; 

        String winner = null; 

  

        for (int a = 0; a < 9; a++) { 

            board[a] = String.valueOf(a + 1); 

        } 

  

        System.out.println("Welcome to 3x3 Tic Tac Toe."); 

        printBoard(); 

  

        System.out.println( 

            "X will play first. Enter a slot number to place X in:"); 

  

        while (winner == null) { 

            int numInput; 

            

           // Exception handling. 

           // numInput will take input from user like from 1 to 9. 

           // If it is not in range from 1 to 9. 

           // then it will show you an error "Invalid input." 

            try { 

                numInput = in.nextInt(); 

                if (!(numInput > 0 && numInput <= 9)) { 

                    System.out.println( 

                        "Invalid input; re-enter slot number:"); 

                    continue; 

                } 

            } 

            catch (InputMismatchException e) { 

                System.out.println( 

                    "Invalid input; re-enter slot number:"); 

                continue; 

            } 

              

            // This game has two player x and O. 

            // Here is the logic to decide the turn. 

            if (board[numInput - 1].equals( 

                    String.valueOf(numInput))) { 

                board[numInput - 1] = turn; 

  

                if (turn.equals("X")) { 

                    turn = "O"; 

                } 

                else { 

                    turn = "X"; 

                } 

  

                printBoard(); 

                winner = checkWinner(); 

            } 

            else { 

                System.out.println( 

                    "Slot already taken; re-enter slot number:"); 

            } 

        } 

        

        // If no one win or lose from both player x and O. 

        // then here is the logic to print "draw". 

        if (winner.equalsIgnoreCase("draw")) { 

            System.out.println( 

                "It's a draw! Thanks for playing."); 

        } 

        

        // For winner -to display Congratulations! message. 

        else { 

            System.out.println( 

                "Congratulations! " + winner 

                + "'s have won! Thanks for playing."); 

        } 

    } 
}
