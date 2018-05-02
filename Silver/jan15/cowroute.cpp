#include <bits/stdc++.h>

using namespace std;

// i don't wanna copy paste
#define INF 0x3F

typedef pair<long long, int> pii;

int a, b, x;

// shortest distance between 2 points
pii cost[1010][1010];
// shortest path from src to vertex in array
pii best[1010];

pii dijkstra() {
    // src = a
    // target = b
    
    bool vis[1010];
    for(int i = 0; i < 1010; i++){
        vis[i] = false;
    }
    
    // source to source = 0, 0
    best[a] = make_pair(0, 0);
    
    // cout << best[b].first << " " << best[b].second << endl;    
    
    for(int i = 0; i < 1010; i++){
        // closest that hasn't been visited before.
        int u = -1;
        for(int j = 0; j < 1010; j++){
            // shouldn't be visited
            if(vis[j]){
                continue;
            }
            // shorter distance
            if(u == -1 || best[j] < best[u]){
                u = j;
            }
        }
        // cout << u << endl;
        
        // update cost
        vis[u] = true;
        for(int j = 0; j < 1010; j++){
            // current min
            pii next = best[u];
            // add cost
            next.first += cost[u][j].first;
            next.second += cost[u][j].second;
            // update best[j]
            best[j] = min(best[j], next);
        }
        
        // cout << cost[u][4].first << " " << cost[u][4].second << endl;
    }
    
    if(best[b].second <= 1010){
        return best[b];
    }
    return make_pair(-1, -1);
    
}

int main() {
    
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    
    // cout << INF << endl;
    
    cin >> a >> b >> x;
    
    memset(cost, INF, sizeof(cost));
    memset(best, INF, sizeof(best));
    
    // distance between same point is 0. debate??
    for(int i = 0; i < 1010; i++){
        cost[i][i] = make_pair(0, 0);
    }
    
    for(int i = 0; i < x; i++){
        long long expense;
        int len;
        // expense, length of route sequence
        cin >> expense >> len;
        
        int route[len];
        for(int j = 0; j < len; j++){
            // stop on route
            cin >> route[j];
            for(int k = 0; k < j; k++){
                // rethink all prior routing
                cost[route[k]][route[j]] = min(cost[route[k]][route[j]], make_pair(expense, j-k));
            }
        }
    }
    
    // printing out end product
    pii done = dijkstra();
    cout << done.first << " " << done.second << endl;
    
}
