package MenuDriven;


public class Date {
	

	    private int day;
	    private int month;
	    private int year;

	    // Setter
	    public void setDate(int dd, int mm, int yy) {

	        year = yy;

	        // Check month
	        if (mm < 1 || mm > 12)
	            month = 1;
	        else
	            month = mm;

	        // Check days
	        if (month == 2) {

	            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {

	                if (dd < 1 || dd > 29)
	                    day = 1;
	                else
	                    day = dd;
	            }
	            else {

	                if (dd < 1 || dd > 28)
	                    day = 1;
	                else
	                    day = dd;
	            }
	        }

	        else if (month == 4 || month == 6 ||
	                 month == 9 || month == 11) {

	            if (dd < 1 || dd > 30)
	                day = 1;
	            else
	                day = dd;
	        }

	        else {

	            if (dd < 1 || dd > 31)
	                day = 1;
	            else
	                day = dd;
	        }
	    }


	    // Add days
	    public void addDays(int days) {

	        while (days > 0) {

	            day++;
	            days--;

	            int maxDays;

	            if (month == 2) {

	                if (year % 4 == 0 && year % 100 != 0 ||
	                    year % 400 == 0)
	                    maxDays = 29;
	                else
	                    maxDays = 28;
	            }

	            else if (month == 4 || month == 6 ||
	                     month == 9 || month == 11) {

	                maxDays = 30;
	            }

	            else {
	                maxDays = 31;
	            }

	            if (day > maxDays) {

	                day = 1;
	                month++;

	                if (month > 12) {
	                    month = 1;
	                    year++;
	                }
	            }
	        }
	    }


	    // Add months
	    public void addMonth(int months) {

	        month = month + months;

	        while (month > 12) {
	            month = month - 12;
	            year++;
	        }
	    }


	    // Add years
	    public void addYear(int years) {

	        year = year + years;
	    }


	    // Getters
	    public int getDay() {
	        return day;
	    }

	    public int getMonth() {
	        return month;
	    }

	    public int getYear() {
	        return year;
	    }


	    // Main method
	    public static void main(String[] args) {

	        Date objDate = new Date();

	        int choice;

	        do {

	            System.out.println("\n----- DATE MENU -----");
	            System.out.println("1. Set Date");
	            System.out.println("2. Add Days");
	            System.out.println("3. Add Month");
	            System.out.println("4. Add Year");
	            System.out.println("5. Display");
	            System.out.println("6. Exit");

	            System.out.println("Enter your choice:");
	            choice = ConsoleInput.getInt();


	            switch (choice) {

	                case 1:

	                    System.out.println("Enter the day:");
	                    int day = ConsoleInput.getInt();

	                    System.out.println("Enter the month:");
	                    int month = ConsoleInput.getInt();

	                    System.out.println("Enter the year:");
	                    int year = ConsoleInput.getInt();

	                    objDate.setDate(day, month, year);

	                    break;


	                case 2:

	                    System.out.println("Enter days to add:");
	                    int days = ConsoleInput.getInt();

	                    objDate.addDays(days);

	                    break;


	                case 3:

	                    System.out.println("Enter months to add:");
	                    int months = ConsoleInput.getInt();

	                    objDate.addMonth(months);

	                    break;


	                case 4:

	                    System.out.println("Enter years to add:");
	                    int years = ConsoleInput.getInt();

	                    objDate.addYear(years);

	                    break;


	                case 5:

	                    System.out.println(
	                        objDate.getDay() + "/" +
	                        objDate.getMonth() + "/" +
	                        objDate.getYear()
	                    );

	                    break;


	                case 6:

	                    System.out.println("Exit");

	                    break;


	                default:

	                    System.out.println("Invalid choice");
	            }

	        } while (choice != 6);
	    }
	}

