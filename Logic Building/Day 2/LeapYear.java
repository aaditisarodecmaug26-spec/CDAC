public class LeapYear{
 public static void main(String[] args){
  int year1 = 2024;
  int year2 = 1900;
 
  if((year1 % 400 == 0) || (year1 % 4 == 0 && year1 % 100 !=0)){
   System.out.println(year1 + " is a leap year.");
 }
  else{
   System.out.println(year1 + " is not a leap year.");
 }

  if((year2 % 400 == 0) || (year2 % 4 == 0 && year2 % 100 !=0)){
    System.out.println(year2 + " is a leap year.");
 }
  else{
   System.out.println(year2 + " is not a leap year.");
 }
}
}


