package Classes;

import java.util.Scanner;

public class Complex {
	int real;
	int imag;
	
	public Complex(int r, int i) {
		real = r;
		imag = i;
	}
	
	public void printSum(Complex other) {
		int sumReal = this.real + other.real;
		int sumImag = this.imag + other.imag;
		System.out.println("Sum: " + sumReal + " + " + sumImag + "i");
	}
	
	public void printDifference(Complex other) {
		int diffReal = this.real - other.real;
		int diffImag = this.imag - other.imag;
		System.out.println("Difference: " + diffReal + " + " + diffImag + "i");

	}
	public void printProduct(Complex other) {
		int prodReal = (this.real * other.real) - (this.imag * other.imag);
		int prodImag = (this.real * other.real) + (this.imag * other.real);
		System.out.println("Product: " + prodReal + " + " + prodImag + "i");

	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter 1st number of real:");
		int real1 = sc.nextInt();
		
		System.out.println("Enter 1st number of imaginary:");
		int imag1 = sc.nextInt();
		
		Complex c1 = new Complex(real1, imag1);

		
		System.out.println("Enter 2nd number of real:");
		int real2 = sc.nextInt();
		
		System.out.println("Enter 2nd number of imaginary:");
		int imag2 = sc.nextInt();
		
		Complex c2 = new Complex(real2, imag2);
		
		c1.printSum(c2);
		c1.printDifference(c2);
		c1.printProduct(c2);
		
		sc.close();
	
	}


}
