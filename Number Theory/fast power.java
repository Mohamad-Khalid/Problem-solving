import java.util.Scanner;

public class Rev {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int p, r, n;
		p = input.nextInt();
		r = input.nextInt();
		n = input.nextInt();

		// calculate m = ( p*r*(1+r)^n  /  (1+r)^n -1 )
		
		// first solution using built in pow() function
		System.out.println((p * r * Math.pow((1 + r), n)) / (Math.pow((1 + r), n) - 1));

		// second solution using my implementation of fast power function 
		System.out.println((p * r * myPower(1 + r, n) * 1.0) / (myPower(1 + r, n) - 1));
	}

	// Implementation of fast exponentiation function
	// Recursive approach
	public static int myPower(int x, int y) {
		if (y == 0)						// base case
			return 1;
		int ret = myPower(x, y / 2);	//divide the power
		if (y % 2 == 0)					
			return ret * ret;			// 2^10 = 2^5 * 2^5
		else
			return ret * ret * x;		// 2^11 = 2^5 * 2^5 * 2 
	}

}
