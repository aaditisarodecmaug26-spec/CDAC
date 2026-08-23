import java.util.Scanner;
import java.util.Arrays;

  public class LargestElement {
       
   public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int[] numbers = new int[5];

    System.out.println("Enter 5 inetgers: ");
    
    for(int i = 0; i < 5; i++) {
     numbers[i] = sc.nextInt();
    }

    Arrays.sort(numbers);

    int largest = numbers[4];
    System.out.println("The Largest Element is: " + largest);

   }
}