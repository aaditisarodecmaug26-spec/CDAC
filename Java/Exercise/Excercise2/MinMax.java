package Array;

import java.util.Scanner;

public class MinMax {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the size of the array: ");
		int size = sc.nextInt();
		
		int[] arr = new int [size];
		System.out.println("Enter " + size + " Numbers: ");
		
		for(int i = 0; i < size; i++) {
			arr[i] = sc.nextInt();
		}
		
		int min = arr[0];
		int max = arr[0];
		
		for (int i = 0; i < size; i++) {
			if(arr[i] > max) {
				max = arr[i];
			}
			if(arr[i] < min) {
				min = arr[i];
			}
		}
		
		System.out.println("Maximum value is: " + max);
		System.out.println("Minimum value is: " + min);
	}

}
