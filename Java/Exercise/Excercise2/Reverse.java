package Array;
import java.util.*;

public class Reverse {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the size of the array: ");
		int size = sc.nextInt();
		
		int[] arr = new int[size];
		System.out.println("Enter " + size + " Number");
		for(int i = 0; i < size; i++) {
			arr[i] = sc.nextInt();
		}
		
		for(int i = 0; i < size/2; i++) {
			int temp = arr[i];
			arr[i] = (arr[size-1-i]);
			(arr[size-1-i]) = temp;		
		}
		
		
		System.out.println("*****Reversed Array*****");
		for(int i = 0; i < size; i++) {
			System.out.println(arr[i] + " ");
		}
		
		
	}
	

}
