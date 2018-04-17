#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    
    freopen("buffet.in", "r", stdin);
    freopen("buffet.out", "w", stdout);
    
    int N, E;
    cin >> N >> E;
    
    int q[N], dist[N];
    int dp[N];
    vector<int> neighbors[N];
    
    for(int i = 0; i < N; i++){
        int D;
        cin >> q[i] >> D;
        for(int j = 0; j < D; j++){
            int v;
            cin >> v;
            neighbors[i].push_back(--v);
        }
    }
    
    int inds[N];
    
    for(int i = 0; i < N; i++){
        inds[i] = i;
    }
    
    sort(inds, inds+N, [&](int x, int y){
        return q[x] < q[y];
    });
    
    fill(dp, dp+N, 0);
    
    int ans = 0;
    for(int i = N-1; i >= 0; i--){
        int ind = inds[i];
        
        queue<int> que;
        for(int i = 0; i < N; i++){
            dist[i] = -1;
        }
        dist[ind] = 0;
        que.push(ind);
        
        while(!que.empty()){
            int top = que.front();
            que.pop();
            for(int next : neighbors[top]){
                if(dist[next] < 0){
                    dist[next] = dist[top]+1;
                    que.push(next);
                }
            }
        }
        int tmp = 0;
        for(int j = 0; j < N; j++){
            if(dist[j] != -1){
                tmp = max(tmp, q[ind] + dp[j] - E * dist[j]);
            }
        }
        dp[ind] = tmp;
        ans = max(ans, dp[ind]);
    }
    
    cout << ans << '\n';
    
}
