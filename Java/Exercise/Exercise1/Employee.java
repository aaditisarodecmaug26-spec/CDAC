package Classes;

public class Employee {
	String name;
    int yearOfJoining;
    double salary;
    String address;
    
    public Employee(String n, int year, double sal, String add) {
        name = n;
        yearOfJoining = year;
        salary = sal;
        address = add;
    }

    public static void main(String[] args) {
        
        Employee emp1 = new Employee("Robert", 1994, 50000.0, "64C- WallsStreat");
        Employee emp2 = new Employee("Sam", 2000, 60000.0, "68D- WallsStreat");
        Employee emp3 = new Employee("John", 1999, 55000.0, "26B- WallsStreat");

        System.out.println("Name\t\tYear of joining\t\tAddress");
        System.out.println(emp1.name + "\t\t" + emp1.yearOfJoining + "\t\t\t" + emp1.address);
        System.out.println(emp2.name + "\t\t" + emp2.yearOfJoining + "\t\t\t" + emp2.address);
        System.out.println(emp3.name + "\t\t" + emp3.yearOfJoining + "\t\t\t" + emp3.address);
    }
}
	
	
	
	

