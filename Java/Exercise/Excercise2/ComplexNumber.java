package Array;
import java.util.*;

public class ComplexNumber {
	int num1;
	int num2;
	
	public void setNumber1(int n) {
		num1 = n;
	}
	
	public int getNumber1() {
		return num1;
	}
	
	public void setNumber2(int n) {
		num2 = n;
	}
	
	public int getNumber2() {
		return num2;
	}
	
	public int computeComplexNumber() {
		return num1 * num2;
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ComplexNumber[] arr = new ComplexNumber[5];
		
		for(int i = 0; i < 5; i++) {
			arr[i] = new ComplexNumber();
			
			System.out.println("Enter number1 " + (i+1) + ":");
			int n1 = sc.nextInt();
			arr[i].setNumber1(n1);
			
			System.out.println("Enter number2 " + (i+1) + ":");
			int n2 = sc.nextInt();
			arr[i].setNumber2(n2);
		}
		
		System.out.println("\n*****Results****");
		
		for(int i = 0; i < 5; i++) {
			int result = arr[i].computeComplexNumber();
			System.out.println("Result " + (i+1) + ":" + result);
			
			
		}
		
	}

}
