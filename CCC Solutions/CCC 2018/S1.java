import java.io.*;
import java.util.*;
import java.math.BigDecimal;

public class VoronoiVillages {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException{
		int m = Integer.parseInt(br.readLine());
		double all[] = new double[m];
		for (int i = 0; i < m; i++) {
			all[i] = Double.parseDouble((br.readLine()));
		}
		Arrays.sort(all);
		double minn = Double.MAX_VALUE;
		for (int j = 1; j < m-1; j++) {
			double a = ((all[j] - all[j-1])/2);
			double b = ((all[j+1] - all[j])/2);
			minn = Math.min(a+b, minn);
		}
		String remainder = "";
		BigDecimal o = new BigDecimal(minn);
		if (o.remainder(new BigDecimal(1)).equals(new BigDecimal(0))) {
			remainder = ".0";
		}
		System.out.println(o.toString() + remainder);
	}
