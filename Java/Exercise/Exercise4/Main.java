package Inheritance;

class Parent {
 public void printParent() {
     System.out.println("This is parent class");
 }
}

class Child extends Parent {
 public void printChild() {
     System.out.println("This is child class");
 }
}

public class Main { 
 public static void main(String[] args) {
     Parent parentObj = new Parent();
     Child childObj = new Child();
     
     System.out.println("Call 1: ");
     parentObj.printParent();
     
     System.out.println("Call 2: ");
     childObj.printChild();
     
     System.out.println("Call 3: ");
     childObj.printParent();
 }
}
