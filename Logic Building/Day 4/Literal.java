public class Literal {

  public static void main(String[] args) {
  
    String str1 = "hello";
    String str2 = "hello";

    Boolean result = (str1 == str2);

   System.out.println("Both variables point to the same object: " + result);
 }
}