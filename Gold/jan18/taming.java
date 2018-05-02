import java.util.*;
import java.io.*;

public class taming {

	private static int n;
	private static int[] log;
	private static int[][][] dp;
	
	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(new File("taming.in"));
		n = sc.nextInt();
		log = new int[n];
		for(int i = 0; i < n; i++) {
			log[i] = sc.nextInt();
		}
		sc.close();
		
		dp = new int[n][n][n+1];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k <= n; k++) {
					dp[i][j][k] = 65535;
				}
			}
		}
		
		if(log[0] == 0)
			dp[0][0][1] = 0;
		else
			dp[0][0][1] = 1;
		
		for(int i = 1; i < n; i++) {
			for(int j = 0; j <= i; j++) {
				for(int k = 1; k <= i+1; k++) {
					if(j < i)
						dp[i][j][k] = dp[i-1][j][k];
					else
						for(int j0 = 0; j0 < j; j0++) {
							dp[i][j][k] = Math.min(dp[i][j][k], dp[i-1][j0][k-1]);
						}
					//BUT...
					if(log[i] != i-j)
						dp[i][j][k]++;

					// System.out.println(dp[i][j][k]);
				}
			}
		}
		PrintWriter pw = new PrintWriter(new File("taming.out"));
		
		for(int k = 1; k <= n; k++) {
			int best = Integer.MAX_VALUE;
			for(int j = 0; j < n; j++) {
				best = Math.min(best, dp[n-1][j][k]);
			}
			pw.println(best);
		}
		
		pw.flush();
		pw.close();
		
	}
	
}
