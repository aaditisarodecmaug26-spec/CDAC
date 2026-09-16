package Classes;

class Student {
	String name;
	int roll_no;
	String phone_no;
	String address;
}

public class Main {
	public static void main(String[] args) {
		Student sam = new Student();
		sam.name = "Sam";
		sam.roll_no = 1;
		sam.phone_no = "1112223334";
		sam.address = "123 Jweller Street, New York";
		
		Student john = new Student();
		john.name = "John";
		john.roll_no = 2;
		john.phone_no = "9998887776";
		john.address = "XYZ Binary Street, USA";
		
		System.out.println("*******Details Of Sam******");
		System.out.println("Name: " + sam.name);
		System.out.println("Roll No: " + sam.roll_no);
		System.out.println("Phone No: " + sam.phone_no);
		System.out.println("Address: " + sam.address);
		
		System.out.println("\n*******Details Of John******");
		System.out.println("Name: " + john.name);
		System.out.println("Roll No: " + john.roll_no);
		System.out.println("Phone No: " + john.phone_no);
		System.out.println("Address: " + john.address);
		
	}

}
