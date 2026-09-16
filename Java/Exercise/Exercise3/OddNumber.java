package ForLoop;

public class OddNumber {
	public static void main(String[] args) {
		int num = 1000;
		
		System.out.println("The list of an odd Number between 1 to " + num + ": ");
		
		for(int i = 1; i <= num; i++) {
			if(i % 2 != 0) {
				System.out.println(i + " " );
			}
		}
	}


}
