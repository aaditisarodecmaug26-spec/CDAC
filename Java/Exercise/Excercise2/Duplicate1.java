package Array;

import java.util.Arrays;
import java.util.Scanner;

public class Duplicate1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the size of the array: ");
		int size = sc.nextInt();
		int[] arr = new int[size];
		System.out.println("Enter " + size + " Number: ");
		for(int i = 0; i < size; i++) {
			arr[i] = sc.nextInt();
		}
		
		System.out.println("*****Duplicate Value*****");
		Arrays.sort(arr);
		boolean foundDuplicate = false;
		
		for(int i = 0; i < size - 1; i++) {
			if (arr[i] == arr[i+1]) {
				System.out.println("Duplicate values: " + arr[i]);
				foundDuplicate = true;
			}
		}
		
		if(foundDuplicate == false) {
			System.out.println("No Duplicate found in this array.");
		}
	}

}
