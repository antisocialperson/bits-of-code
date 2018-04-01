// https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/monk-takes-a-walk/
// Problem Statement

using System;

class Loser {
    
    public static void Main(string[] args){
        string s = Console.ReadLine();
        int T = Convert.ToInt32(s);
        int i, j, k = 0;
        for(i = 0; i < T; i++){
          k = 0;
          s = Console.ReadLine();
          for(j = 0; j < s.Length; j++){
            if(s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U' || s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
              k++;
            }
          }
          Console.WriteLine(k);
        }
        
    }
    
}
