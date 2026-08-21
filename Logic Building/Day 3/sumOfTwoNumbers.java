import java.util.Scanner;
 
  public class sumOfTwoNumbers {

      public static int sumOfTwoNumbers(int a, int b) {
             return a + b;
      }

           public static void main(String[] args){
           Scanner sc = new Scanner(System.in);

           System.out.println(" Enter First Number: ");
           int num1 = sc.nextInt();

           System.out.println(" Enter Second Number: ");
           int num2 = sc.nextInt();

           int sum = sumOfTwoNumbers (num1, num2);

           System.out.println(" The sum of " + num1 + " and " + num2 + " is " + sum);

           sc.close();
     }
}





  

