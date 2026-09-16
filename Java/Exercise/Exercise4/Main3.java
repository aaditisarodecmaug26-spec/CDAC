package Inheritance;

class Shape2 {
    public void printShape() {
        System.out.println("This is shape");
    }
}

class Rectangle2 extends Shape2 {
    public void printRectangle() {
        System.out.println("This is rectangular shape");
    }
}

class Circle2 extends Shape2 {
    public void printCircle() {
        System.out.println("This is circular shape");
    }
}

class Square2 extends Rectangle2 {
    public void printSquare() {
        System.out.println("Square is a rectangle");
    }
}

public class Main3 {
    public static void main(String[] args) {
        Square2 sq = new Square2();
        sq.printShape();
        sq.printRectangle();
    }
}
