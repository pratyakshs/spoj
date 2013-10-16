import java.util.Scanner;
import java.math.BigInteger;

class may99_4{
	public static BigInteger binomial(int n, int r)
	{
		BigInteger ans = new BigInteger(String.valueOf(1));
		BigInteger term = new BigInteger(String.valueOf(n));
		for(int i=1; i<=r; i++)
		{
			ans=(ans.multiply(term)).divide(new BigInteger(String.valueOf(i)));
			term=term.subtract(new BigInteger(String.valueOf(1)));
		}
		return ans;
	}
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		int n = scan.nextInt();
		int r = scan.nextInt();
		if(n < r)
			System.out.println(-1);
		else
			System.out.println(binomial(n-1, r-1).mod(new BigInteger(String.valueOf(10000007))));
	}

}