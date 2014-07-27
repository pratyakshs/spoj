import java.util.Scanner;
import java.math.BigInteger;

class pucmm{
	

	public static void main(String[] args) {

		
		Scanner scan=new Scanner(System.in);
		int t=scan.nextInt();
		for(int i=0; i<t; i++){
			BigInteger n=scan.nextBigInteger();


			System.out.println(calc(n, table));

		}
	}
}



// for(int i=1; i<800000; i++)
// 	calc(i);
