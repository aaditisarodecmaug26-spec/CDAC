package Classes;

public class Employee2 {
	double salary;
	int hours;
	
	public void getInfo(double sal, int hr) {
		salary = sal;
		hours = hr;
	}
	
	public void addSal() {
		if(salary < 500) {
			salary = salary + 10;
		}
	}
	
	public void addWork() {
		if(hours > 6) {
			salary = salary + 5;
		}
	}
	
	public static void main(String[] args) {
		Employee2 e1 = new Employee2();
		e1.getInfo(600, 5);
		e1.addSal();
		e1.addWork();
		
		System.out.println("Final Salary for Employee1: $" + e1.salary);
		
		Employee2 e2 = new Employee2();
		e2.getInfo(400, 8);
		e2.addSal();
		e2.addWork();
		
		System.out.println("Final Salary for Employee2: $" + e2.salary);
	}

}
