public class Pattern15 {

  public static void main(String[] args) {

    for(int i = 1; i <= 5; i++) {
      for(int j = 1; j <= i; j++) {
        System.out.print(i + "*");
       }
         System.out.println();
      }

   for(int i = 4; i >= 2; i--) {
      for(int j = 1; j <= i; j++) {
        System.out.print(i + "*");
       }
         System.out.println();
      }
  }
}