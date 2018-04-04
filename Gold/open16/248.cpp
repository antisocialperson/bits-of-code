#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int N;
int game[248];
int dp[248][248];

int main(){
    
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> game[i];
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = 0;
        }
    }
    
    // only needs to be <= 0
    int max_val = -53;
    
    for(int len = 1; len <= N; len++){
        for(int start = 0; start <= N - len; start++){
            int end = start + len - 1;
            
            if(len == 1){
                dp[start][end] = game[start];
            }
            
            for(int i = start; i < end; i++){
                if(dp[start][i] == dp[i+1][end] && dp[start][i] > 0){
                    dp[start][end] = max(dp[start][end], dp[start][i]+1);
                }
            }
            
            max_val = max(max_val, dp[start][end]);
        }
    }
    
    cout << max_val << endl;
    
}
