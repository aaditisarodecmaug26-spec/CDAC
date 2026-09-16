package Array;
import java.util.*;

public class Copy {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the size of the array: ");
		int size = sc.nextInt();
		
		int[]  originalArray = new int[size];
		
		System.out.println("Enter" + size + " number: ");
		for(int i = 0; i < size ; i++) {
			originalArray[i] = sc.nextInt();
		}
		
          int[] copiedArray = new int[size];
          
          System.out.println("Enter" + size + " number: ");
          for(int i = 0; i < size; i++) {
        	  copiedArray[i] = originalArray[i];
          }
          
          System.out.println("****Original Array****");
          for(int i = 0; i < size; i++) {
        	  System.out.println(originalArray[i] + " ");
          }
          System.out.println("****Copied Array****");
          for(int i = 0; i < size; i++) {
        	  System.out.println(copiedArray[i] + " ");
          }
          
          
	}

}
