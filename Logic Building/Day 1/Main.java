public class Main{
    public static void main(String[] args){
    
    // check positive number
     int num1 = 10;
     if (num1 > 0){
     System.out.println("Positive Number");
     }
     else{
     System.out.println("Not Positive Number");
     }


    // check negative number
     int num2 = -4;
     if (num2 < 0){
     System.out.println("Negative Number");
     }
     else{
     System.out.println("Not Negative Number");
     }

    // Odd or Even
     int num3 = 6;
     if (num3 % 2 == 0){
     System.out.println("Even Number");
     }
     else{
     System.out.println("Odd Number");
     }

    // Good morning message
     int time = 9;
     if(time >= 5 && time < 12){
     System.out.println("Good Morning");
     }
     else{
     System.out.println("Good Day");
     }
  
    // Area of square
     int side = 5;
     int areaSquare = side * side;
     System.out.println("Area of square = " + areaSquare);


   // Area of Rectangle
    int length = 12;
    int width = 6;
    int areaRectangle = length * width;
    System.out.println("Area of rectangle = " + areaRectangle);

  //Largest of three number
   int a = 25;
   int b = 35;
   int c = 30;
   if(a >= b && a >= c){
   System.out.println("Largest = " + a);
   }
   else if(b >= a && b>= c){
   System.out.println("Largest = " + b);
   }
   else{
   System.out.println("Largest = " + c);
   }
     
   }

}
