package Array;
import java.util.*;

public class Duplicate {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the size of the array: ");
		int size = sc.nextInt();
		int[] arr = new int[size];
		System.out.println("Enter " + size + " Number: ");
		for(int i = 0; i < size; i++) {
			arr[i] = sc.nextInt();
		}
		
		System.out.println("*****Duplicate value*****");
		
		for(int i = 0; i < size; i++) {
			for(int j = i + 1; j < size; j++) {
				if(arr[i] == arr[j]) {
					System.out.println("Duplicate Values: " + arr[i]);
				}
			}
		}
	}

}
