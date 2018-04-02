#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

struct codebit{
    
    long ind;
    long val;
    
};

bool comp(codebit cb1, codebit cb2){
    
    return (cb1.val < cb2.val) || (cb1.val == cb2.val && cb1.ind < cb2.ind);
    
}

int main(){
    
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    
    long N;
    cin >> N;
    codebit A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i].val;
        A[i].ind = i;
    }
    
    sort(A, A+N, comp);
    
    long ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, A[i].ind - i);
    }
    
    cout << ans + 1 << endl;
    
}
