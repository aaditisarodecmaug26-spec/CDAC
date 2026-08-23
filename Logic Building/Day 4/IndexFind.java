import java.util.Scanner;
import java.util.Arrays;

  public class IndexFind {
       
   public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    Integer[] numbers = new Integer[5];

    System.out.println("Enter 5 inetgers: ");
    
    for(int i = 0; i < 5; i++) {
     numbers[i] = sc.nextInt();
    }

    Arrays.sort(numbers);
  
    System.out.println("Enter the number to serach: ");
    int num = sc.nextInt();

    int index = Arrays.binarySearch(numbers,num);
    
    if(index >= 0) {
      System.out.println("The number " + num + " is found at index " + index);
     }
     else {
      System.out.println("Not Found");
    }
  }
}
