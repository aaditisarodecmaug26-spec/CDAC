import java.util.Scanner;
import java.util.Arrays;

  public class SortArray {
       
   public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int[] numbers = new int[5];

    System.out.println("Enter 5 inetgers: ");
    
    for(int i = 0; i < 5; i++) {
     numbers[i] = sc.nextInt();
    }

    Arrays.sort(numbers);
    System.out.print("Sorted Array:" );

    for(int number : numbers) {
       System.out.println(number + " ");
    }
 }
}








