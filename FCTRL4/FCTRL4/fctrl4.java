import java.util.Scanner;
import java.math.BigInteger;

class fctrl4{
	
	public static BigInteger D(BigInteger n)
	{
		BigInteger t=(n.divide(new BigInteger(String.valueOf(10)))).mod(new BigInteger(String.valueOf(10)));
		if(n.compareTo(new BigInteger(String.valueOf(10))) == -1)//have to check
		{
			switch(n.intValue())
			{
				case 1: return new BigInteger(String.valueOf(1));
				case 2: return new BigInteger(String.valueOf(2));
				case 3: return new BigInteger(String.valueOf(6));
				case 4: return new BigInteger(String.valueOf(4));
				case 5: return new BigInteger(String.valueOf(2));
				case 6: return new BigInteger(String.valueOf(2));
				case 7: return new BigInteger(String.valueOf(4));
				case 8: return new BigInteger(String.valueOf(2));
				case 9: return new BigInteger(String.valueOf(8));
				case 0: return new BigInteger(String.valueOf(1));
			}
		}
		if((t.mod(new BigInteger(String.valueOf(2)))).compareTo(new BigInteger(String.valueOf(1)))==0)
		{
			return ((D(n.divide(new BigInteger(String.valueOf(5)))).multiply(D(n.mod(new BigInteger(String.valueOf(10)))))).multiply(new BigInteger(String.valueOf(4)))).mod(new BigInteger(String.valueOf(10)));
		}
		else
			return ((D(n.divide(new BigInteger(String.valueOf(5)))).multiply(D(n.mod(new BigInteger(String.valueOf(10)))))).multiply(new BigInteger(String.valueOf(6)))).mod(new BigInteger(String.valueOf(10)));	
	}
	
	public static void main(String args[])
	{
		/*while(true){

			Scanner sc = new Scanner(System.in);
			BigInteger bi = sc.nextBigInteger();
			System.out.println(D(bi)+"\n");
		}*/

		Scanner scan=new Scanner(System.in);
		try{
			while(scan.hasNextBigInteger()){
				BigInteger bi=scan.nextBigInteger();
				System.out.println(D(bi));
			}
		}
		finally{
			scan.close();
		}
		//if (scan.nextLine().equals("")) System.exit(0);  
	}

	/*

int main()
{
	unsigned long long x;
	while(scanf("%llu", &x)!=EOF)
	{
		printf("%i\n", D(x));
	}
}
 */
}
