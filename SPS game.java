
import java.util.Scanner;
import java.util.Random;
public class Exercise_2 {
    public static void main(String[] args) {
        System.out.println("Welcome to this Rock,Paper and Sissor game and enjoy this game.");
        System.out.println("choose: 0. for Rock \n  \t  1. for Paper \n  \t  3. for Scissor");
        Scanner sc=new Scanner(System.in);
        Random ran=new Random();
        System.out.print("It's your turn:");
        int player=sc.nextInt();

        switch (player) {
            case 0 -> System.out.println("you choose the Rock.");
            case 1 -> System.out.println("you choose the Paper.");
            case 2 -> System.out.println("you choose the Scissor.");
        }
        System.out.print("computer it your turn:");
         int rand=ran.nextInt(3);
        System.out.println(rand);
        switch(rand) {
            case 0 -> System.out.println("Computer choose the rock.");
            case 1 -> System.out.println("Computer  choose the paper.");
            case 2 -> System.out.println("Computer  choose the scissor.");

        }
        if(player==rand){
            System.out.println("The match is draw.");
        }
        else if((player==0 && rand==2)|| (player==1&& rand==0) || (player==2&& rand==1)  ){
            System.out.println("congratulation,you win the game.");
        }
        else{
            System.out.println("The computer have win the game and you loose the game.");
        }
    }
}
