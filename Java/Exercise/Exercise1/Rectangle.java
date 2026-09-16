package Classes;

public class Rectangle {
	int length;
	int breadth;
	
	public Rectangle(int l, int b) {
		length = l;
		breadth = b;
	}
	public int area() {
		return length * breadth;
	}
	public static void main(String[] args) {
		Rectangle rect1 = new Rectangle(4 ,5);
		Rectangle rect2 = new Rectangle(5, 8);
		
		System.out.println("Area of Rectangle(4,5): " + rect1.area());
		System.out.println("Area of Rectangle(5,8): " + rect2.area());

	}
	

}
