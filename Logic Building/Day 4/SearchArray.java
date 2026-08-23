import java.util.Scanner;
import java.util.Arrays;

  public class SearchArray {
       
   public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    Integer[] numbers = new Integer[5];

    System.out.println("Enter 5 inetgers: ");
    
    for(int i = 0; i < 5; i++) {
     numbers[i] = sc.nextInt();
    }
  
    System.out.println("Enter the number to serach: ");
    int num = sc.nextInt();

    if (Arrays.asList(numbers).contains(num)) {
     System.out.println("Found");
   }
    else {
   System.out.println("Not Found");
 }
}
}