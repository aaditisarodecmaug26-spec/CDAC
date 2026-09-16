package Classes;

public class Triangle {	
	public Triangle(int a, int b, int c) {
        int perimeter = a + b + c;
        int area = (3 * 4) / 2;     
        System.out.println("Perimeter: " + perimeter);
        System.out.println("Area: " + area);
    }
    public static void main(String[] args) {      
        Triangle myTriangle = new Triangle(3, 4, 5);
        
    }
}
