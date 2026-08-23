import java.util.Scanner;

  public class SumOfArray {
       
   public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int[] numbers = new int[5];
    int sum = 0;

    System.out.println("Enter 5 Integers: ");

    for(int i = 0; i < 5; i++) {
      numbers[i] = sc.nextInt();
    }

    for(int number : numbers) {
    sum = sum + number;
    }
      System.out.println("Sum of all numbers is : " + sum);
  }
}