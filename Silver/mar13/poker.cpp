#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    
    int N;
    cin >> N;
    
    int A[N+2];
    fill(A, A+N+2, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    
    long long ans = 0;
    for(int i = 0; i <= N; i++){
        ans += abs(A[i+1]-A[i]);
    }
    ans /= 2;
    
    cout << ans << endl;
    
}
