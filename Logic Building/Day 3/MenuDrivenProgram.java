import java.util.Scanner;

public class MenuDrivenProgram {
  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int choice;

   do {

       System.out.println(" Menu ");
       System.out.println(" 1. Grade Evaluation System");
       System.out.println(" 2. Leap Year Check");
       System.out.println(" 3. Day of the Week");
       System.out.println(" 5.Exit");
       System.out.println("Enter your choice: ");

       choice = sc.nextInt();

       switch (choice) {

         case 1:
             System.out.print("Enter marks: ");
             int marks = sc.nextInt();

             if(marks >= 90){
               System.out.println("Grade: A");
              }
             else if(marks >= 70){
                System.out.println("Grade: B");
              }
             else if(marks >= 50){
                System.out.println("Grade: C");
              }
            else if(marks >= 30){
                System.out.println("Grade: D");
             }
            else{
                System.out.println("Fail");
             }
            break;

        case 2:
            System.out.print("Enter year: ");
            int year = sc.nextInt();

                if((year % 400 == 0) || (year % 4 == 0 && year % 100 !=0)){
                  System.out.println(year + " is a leap year.");
                 }
                else{
                   System.out.println(year + " is not a leap year.");
                 }
               break;

        case 3:
           System.out.print("Enter Day Number: ");
           int day = sc.nextInt();

           switch (day) {
              case 1:
                  System.out.println("Monday");
                  break;
              case 2:
                  System.out.println("Tuesday");
                  break;
              case 3:
                  System.out.println("Wednesday");
                  break;
              case 4:
                  System.out.println("Thursday");
                  break;
              case 5:
                  System.out.println("Friday");
                  break;
              case 6:
                  System.out.println("Saturday");
                  break;
              case 7:
                  System.out.println("Sunday");
                  break;
               default:
                  System.out.println("Invalid Day.");
       }
          break;

        case 4:
             System.out.println("Default values of instance variables:");
     
             byte b = 0;
             short s = 0;
             int n = 0;
             long l = 0L;
             float f = 0.0f;
             double d = 0.0;
             char c = 'A';
             Boolean e = false;

            System.out.println("byte: " + b);
            System.out.println("short: " + s);
            System.out.println("int: " + n);
            System.out.println("long: " + l);
            System.out.println("float: " + f);
            System.out.println("double: " + d);
            System.out.println("char: " + c);
            System.out.println("boolean: " + e);
            break;

        default:
            System.out.println("Invalid Choice....");
         }
    }  while (choice != 5);
       
  }
} 


                 
