import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.*;

class TestClass {
    public static void main(String args[] ) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int i = 0; i < t; i++){
            int n = sc.nextInt();
            int q = sc.nextInt();
            String str = sc.next();
            for(int j = 0; j < q; i++){
                int x = sc.nextInt();
                int y = sc.nextInt();
                // clockwise run
                int ptr = x;
                int cnt = 0;
                while(ptr != y){
                    int optr = ptr;
                    if(ptr == n-1){
                        ptr = 0;
                    } else{
                        ptr++;
                    }
                    if(str.charAt(optr) != str.charAt(ptr)){
                        cnt++;
                    }
                }
                ptr = x;
                int cnt2 = 0;
                // counter-clockwise run
                while(ptr != y){
                    int optr = ptr;
                    if(ptr == n-1){
                        ptr = 0;
                    } else{
                        ptr++;
                    }
                    if(str.charAt(optr) != str.charAt(ptr)){
                        cnt2++;
                    }
                }
                System.out.println(Math.min(cnt, cnt2));
            }
        }
    }
}
