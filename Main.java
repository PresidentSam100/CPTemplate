import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
	    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	    StringBuilder ans = new StringBuilder();
	    int t = Integer.parseInt(in.readLine());
	    while (t-->0) {
	        StringTokenizer st = new StringTokenizer(in.readLine());
	        int n = Integer.parseInt(st.nextToken());
	        out.println(ans.toString());
	    }
	    out.flush();
	    out.close();
	}
}
