import java.util.Scanner;

     public class ageChecker {
       
     public static void checkAgeCategory(int age) {
        String result = (age < 18) ? "You are a Minor."
                      : (age >= 60) ? " You are a Senior Citizen."
                      : " You are an Adult.";
      
          System.out.println(result);
   }

 public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

   System.out.print("Enter your age: ");
   int age = sc.nextInt();

   checkAgeCategory(age);

   sc.close();
 }
}





