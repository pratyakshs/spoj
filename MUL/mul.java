import java.util.Scanner;
import java.math.BigInteger;

class mul{
	

	public static int power(BigInteger b1, BigInteger b2)
	{
		int m1=b1.bitLength(), m2=b2.bitLength();
		if(m1<m2)
			return m1;
		return m2;
	}
	public static BigInteger karatsuba(BigInteger x, BigInteger y)
	{
		int m=power(x, y);
		if(m<3)
			return x.multiply(y);

		BigInteger bM=new BigInteger(String.valueOf(1<<m));
		BigInteger b2M=new BigInteger(String.valueOf(1<<(2*m)));
		BigInteger x_[]=x.divideAndRemainder(bM);
		BigInteger y_[]=y.divideAndRemainder(bM);
		BigInteger z0=x_[1].multiply(y_[1]);
		BigInteger z2=karatsuba(x_[0], y_[0]);
		BigInteger z1=((x_[1].add(x_[0])).multiply(y_[1].add(y_[0]))).subtract(z0.add(z2));
		return (karatsuba(z2, b2M)).add(z0.add(karatsuba(z1, bM)));
	}

	public static void main(String args[])
	{

		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		for(int i=0; i<n; i++)
		{
			BigInteger x=scan.nextBigInteger(), y=scan.nextBigInteger();
			System.out.println(karatsuba(x,y));

		}



	}
}