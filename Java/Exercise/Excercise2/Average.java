package Array;

import java.util.Scanner;

public class Average {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the size of the array: ");
		int size = sc.nextInt();
		
		int[] arr = new int [size];
		System.out.println("Enter" + size + " Numbers: ");
		
		for(int i = 0; i < size; i++) {
			arr[i] = sc.nextInt();
		}
		
		int sum = 0;
		
		for(int i = 0; i < size; i++) {
			sum = sum + arr[i];
		}
		
		double average = (double) sum / size;
		System.out.println("The average of the values of the array is: " + average);
	}

}
