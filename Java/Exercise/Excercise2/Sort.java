package Array;
import java.util.*;

public class Sort {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the size of the array: ");
		int size = sc.nextInt();
		
		int[] arr = new int [size];
		System.out.println("Enter" + size + " Numbers: ");
		
		for(int i = 0; i < size; i++) {
			arr[i] = sc.nextInt();
		}
		
		Arrays.sort(arr);
		
		System.out.println("\n******Sorted Array******");
		for(int i = 0; i < size; i++) {
			System.out.println(arr[i] + " ");
		}
	}

}
