import java.util.Scanner;

  public class AverageArray {
       
   public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int[] numbers = new int[5];
    int sum = 0;

    System.out.println("Enter 5 Integers: ");

    for(int i = 0; i < 5; i++) {
      numbers[i] = sc.nextInt();
      sum = sum + numbers[i];
    }

      double average = (double) sum / 5;
      System.out.println("Average of the numbers is: " + average);
 
  }
}