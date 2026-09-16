package ForLoop;

public class EvenNumber {
	public static void main(String[] args) {
		int num = 500;
		System.out.println("The list of Even number between 1 to " + num + ":");
		
		for(int i = 1; i <= num; i++) {
			if(i % 2 == 0) {
				System.out.println(i + " ");
			}
		}
	}

}
