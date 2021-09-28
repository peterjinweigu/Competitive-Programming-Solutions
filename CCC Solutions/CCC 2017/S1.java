import java.io.*;
import java.util.StringTokenizer;

public class SumGame {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException {
		int up = 0;
		int low = 0;
		int cur = 0;
		int n = Integer.parseInt(br.readLine());
	    StringTokenizer s = new StringTokenizer(br.readLine());
	    StringTokenizer k = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			low += Integer.parseInt(s.nextToken());
			up += Integer.parseInt(k.nextToken());
			if (low == up) {
				cur = i+1;
			}
		}
		System.out.println(cur);
		
	}
}
