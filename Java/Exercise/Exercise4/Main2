package Inheritance;

class Rectangle {
    private double length;
    private double breadth;
    
    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }
    public void printArea() {
        double area = length * breadth;
        System.out.println("Area: " + area);
    }
    public void printPerimeter() {
        double perimeter = 2 * (length + breadth);
        System.out.println("Perimeter: " + perimeter);
    }
}
class Square extends Rectangle {
    public Square(double side) {
        super(side, side); 
    }
}

public class Main2 {
    public static void main(String[] args) {
        System.out.println("***Rectangle Details***");
        Rectangle rect = new Rectangle(5.0, 8.0);
        rect.printArea();
        rect.printPerimeter();
        System.out.println("\n*** Square Details***");
        Square sq = new Square(4.0);
        sq.printArea();
        sq.printPerimeter();
    }
}
