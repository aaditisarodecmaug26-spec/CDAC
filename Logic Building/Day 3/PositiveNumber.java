import java.util.Scanner;

  public class PositiveNumber {
  
      public static void askForPositiveNumber() {
      Scanner sc = new Scanner(System.in);
      int num;

      do  { 
            System.out.print("Enter Positive Number: ");
            num = sc.nextInt();
        } while (num <= 0);

          System.out.println("You entered a Positive Number: " + num);
          sc.close();
   } 

    public static void main(String[] args) {
      askForPositiveNumber();
  }
}


      

     
   