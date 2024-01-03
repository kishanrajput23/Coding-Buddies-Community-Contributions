import java.util.Random;
import java.util.Scanner;

public class RockScissors {
    public static void main(String[] args) {
        
        int i = 0;
        int count=0;
        while (i < 5) {
            Random R = new Random();
            int min = 1;
            int max = 3;

            int a = min + R.nextInt(max);
            System.out.println(a);
            System.out.println("\nEnter your call\n For rock Enter 1\n For Scissor Enter 2\n For paper enter 3");
            Scanner user = new Scanner(System.in);
            System.out.println("Its your call");
            int call = user.nextInt();

            // Let assume 1=rock,2= scissor, 3=paper;
            String win = "You won";
            String loss = "Computer won";
            String draw = "Game draw!";

            /*if(win>3){
                System.out.println("you win");
        }
        else {System.out.println("Computer win");} */


            if (a==1) {
                if (call > 4) {
                    System.out.println("wrong Entry");
                } else {
                    System.out.println("Computer call is Scissor");
                    if (call == 1) {
                        System.out.println("Your call is Rock");
                        System.out.println(win);
                        count++;
                    } else if (call == 3) {
                        System.out.println("Your call is paper");
                        System.out.println(loss);
                    } else {
                        System.out.println("Your call is scissor");
                        System.out.println(draw);
                    }
                }
            } else if (a==2) {
                if (call > 4) {
                    System.out.println("wrong Entry");
                } else {
                    System.out.println("Computer call is rock");
                    if (call == 2) {
                        System.out.println("Your call is scissor");
                        System.out.println(loss);

                    } else if (call == 3) {
                        System.out.println("Your call is paper ");
                        System.out.println(win);
                        count++;
                    } else {
                        System.out.println("Your call is rock");
                        System.out.println(draw);
                    }
                }

            } else {
                if (call > 4) {
                    System.out.println("wrong Entry");
                } else {
                    System.out.println("Computer call is paper");
                    if (call == 1) {
                        System.out.println("Your call is rock");
                        System.out.println(loss);
                    } else if (call == 2) {
                        System.out.println("Your call is scissor");
                        System.out.println(win);
                        count++;
                    } else {
                        System.out.println("Your call is paper");
                        System.out.println(draw);
                    }
                }
            }
            i++;
        }
        if(count>=3)
        System.out.println("\nYou won");
        else
        System.out.println("\nYou loss");
    
    }
}