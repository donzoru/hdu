import java.util.*;
import java.math.*;
public class hdu1023 {
	public static void main(String[] args){
		BigInteger a[]=new BigInteger[102];
		a[1]=BigInteger.ONE;
		for(int i=2;i<=101;++i)
			a[i]=a[i-1].multiply(BigInteger.valueOf(4*i-2)).divide(BigInteger.valueOf(i+1));
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext())
			System.out.println(a[sc.nextInt()]);
	}
}
