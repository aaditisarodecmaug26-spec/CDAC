import java.util.Scanner;

  public class PositiveNegative {
       
   public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int[] numbers = new int[6];

    int positive = 0;
    int negative = 0;

    System.out.println("Enter 6 Integers: ");

    for(int i = 0; i < 6; i++) {
     numbers[i] = sc.nextInt();

     if (numbers[i] > 0) {
       positive++;
     }
     else if (numbers[i] < 0) {
       negative++;
     }
   }
   
     System.out.println("Positive Numbers: " + positive);
      System.out.println("Negative Numbers: " + negative);

  }
}


