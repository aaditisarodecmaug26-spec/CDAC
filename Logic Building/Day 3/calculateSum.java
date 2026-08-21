public class calculateSum {
     
public static int calculateSum(int n) {

  int sum = 0;

  for (int i = 1; i <= n; i++) {
         sum = sum + i;
    } 
     return sum;
}

  public static void main(String[] args) {



    int n = 5;
 
    int result = calculateSum(n);

    System.out.println("The sum of numbers from 1 to " + n + " is: " + result);
    }
}