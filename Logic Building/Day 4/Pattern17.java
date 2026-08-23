public class Pattern17 {

  public static void main(String[] args) {

    for(int i = 1; i <= 5; i++) {
        int num = 1;
      for(int j = 1; j <= i; j++) {
        System.out.print(num + "*");
         num = num + 2;
       }
         System.out.println();
      }

   }
}