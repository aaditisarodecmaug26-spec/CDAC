package Array;
import java.util.*;

public class Common {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the size of the first array: ");
		int size1 = sc.nextInt();
		int[] arr1 = new int[size1];
		
		System.out.println("Enter " + size1 + " Numbers: ");
		for(int i = 0; i < size1; i++) {
			arr1[i] = sc.nextInt();	
		}
		
		System.out.println("Enter the size of the Second array: ");
		int size2 = sc.nextInt();
		int[] arr2 = new int[size2];
		
		System.out.println("Enter " + size2 + " Numbers: ");
		for(int i = 0; i < size2; i++) {
			arr2[i] = sc.nextInt();
	   }
		
		System.out.println("*****Common Elements*****");
		boolean foundCommon = false;
		
		for(int i = 0; i < size1; i++) {
			for(int j = 0; j < size2; j++) {
				if(arr1[i] == arr2[j]) {
					System.out.println("Common element found: " + arr1[i]);
					foundCommon = true;
					break;
				}
			}
			
			if (foundCommon == false) {
				System.out.println("No common element found.");
			}
		}
	}
		
		

}
