#include <bits/stdc++.h>

#define x first
#define y second
#define INF 2147483640

using namespace std;

typedef pair<int, int> pii;

int solve() {
    
    freopen("trapped.in", "r", stdin);
    freopen("trapped.out", "w", stdout);
    
    int N, B;
    cin >> N >> B;
    
    pii bales[N];
    
    for(int i = 0; i < N; i++) {
        cin >> bales[i].y >> bales[i].x;
    }
    
    sort(bales, bales+N);
    
    int mn = INF;
    int bale = lower_bound(bales, bales+N, make_pair(B, 0)) - bales;
    
    int tmp = bale; // bale to the left
    for(int i = bale - 1; i >= 0; i--) {
        // should have been "i", not "tmp"
        while(tmp < N && bales[tmp].x <= bales[i].x + bales[i].y) {
            // cout << "the mineshaft with the diamonds is really cool" << endl;
            mn = min(mn, bales[tmp].x-bales[i].x-bales[tmp].y);
            tmp++;
        }
    }
    tmp = bale-1; // bale to the right
    for(int i = bale; i < N; i++) {
        while(tmp >= 0 && bales[i].x - bales[i].y <= bales[tmp].x) {
            // cout << "ain't nothin' gonna break my mine" << endl;
            // cout << bales[i].x-bales[tmp].x-bales[tmp].y << endl;
            // cout << i << " " << tmp << endl;
            mn = min(mn, bales[i].x-bales[tmp].x-bales[tmp].y);
            tmp--;
        }
    }
    
    if(mn == INF) {
        return -1;
    } else {
        return max(mn, 0);
    }
    
}

int main() {
    
    cout << solve() << endl;
    return 0;
    
}
