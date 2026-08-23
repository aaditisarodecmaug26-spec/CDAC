import java.util.Scanner;

 public class Vowels {
   
   public static void main(String[] args) {
     Scanner sc = new Scanner(System.in);

     System.out.println("Enter a String: ");
     String str = sc.nextLine();
     int count = 0;

     for(int i = 0; i < str.length(); i++) {
        char ch = str.charAt(i);

     if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
     {
        count++;
    }
  }
     System.out.println("The nuber of vowels in " + str + " is " + count);

 }
}
