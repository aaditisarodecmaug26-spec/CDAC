package Inheritance;

class Member {
    private String name;
    private int age;
    private String phoneNumber;
    private String address;
    private float salary; 

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public int getAge() { return age; }
    public void setAge(int age) { this.age = age; }

    public String getPhoneNumber() { return phoneNumber; }
    public void setPhoneNumber(String phoneNumber) { this.phoneNumber = phoneNumber; }

    public String getAddress() { return address; }
    public void setAddress(String address) { this.address = address; }

    public float getSalary() { return salary; }
    public void setSalary(float salary) { this.salary = salary; }

    // 3. Method to print only salary
    public void printSalary() {
        System.out.println("Salary: $" + salary);
    }
}

class PrimeMembers extends Member {
    private int joiningYear;
    private float joiningFees;
    private boolean isActive;

    public int getJoiningYear() { return joiningYear; }
    public void setJoiningYear(int joiningYear) { this.joiningYear = joiningYear; }

    public float getJoiningFees() { return joiningFees; }
    public void setJoiningFees(float joiningFees) { this.joiningFees = joiningFees; }

    public boolean isActive() { return isActive; }
    public void setActive(boolean isActive) { this.isActive = isActive; }

    public void display() {
        System.out.println("\n--- Prime Member Details ---");
        System.out.println("Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Phone: " + getPhoneNumber());
        System.out.println("Address: " + getAddress());
        System.out.println("Salary: $" + getSalary());
        System.out.println("Joining Year: " + joiningYear);
        System.out.println("Joining Fees: $" + joiningFees);
        System.out.println("Active Status: " + (isActive ? "Yes" : "No"));
    }
}

public class Main1 {
    public static void main(String[] args) {
        PrimeMembers memberObj = new PrimeMembers();

        System.out.println("Enter details for the Prime Member:");

        System.out.print("Enter Name: ");
        memberObj.setName(ConsoleInput.getString());

        System.out.print("Enter Age: ");
        memberObj.setAge(ConsoleInput.getInt());

        System.out.print("Enter Phone Number: ");
        memberObj.setPhoneNumber(ConsoleInput.getString());

        System.out.print("Enter Address: ");
        memberObj.setAddress(ConsoleInput.getString());

        System.out.print("Enter Salary: ");
        memberObj.setSalary(ConsoleInput.getFloat());

        System.out.print("Enter Joining Year: ");
        memberObj.setJoiningYear(ConsoleInput.getInt());

        System.out.print("Enter Joining Fees: ");
        memberObj.setJoiningFees(ConsoleInput.getFloat());

        System.out.print("Is Active (true/false): ");
        memberObj.setActive(Boolean.parseBoolean(ConsoleInput.getString())); 

        memberObj.display();
      
        memberObj.printSalary();
    }
}
