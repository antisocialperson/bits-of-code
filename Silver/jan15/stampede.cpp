#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

// (y, t-r, t)
typedef pair<int, pair<int, int> > piii;
// lower_bound
typedef set<int>::iterator iter;

int main() {
    
    freopen("stampede.in", "r", stdin);
    freopen("stampede.out", "w", stdout);
    
    int N;
    cin >> N;
    
    piii v[N];
    // points of interest
    set<int> pois;
    for(int i = 0; i < N; i++){
        int x, y, r;
        cin >> x >> y >> r;
        
        int t = -x*r;
        v[i] = make_pair(y, make_pair(t-r, t));
        
        // all points of interest: (t-r-1, t-r, t-r+1, t-1, t, t+1)
        pois.insert(t-r-1);
        pois.insert(t-r);
        pois.insert(t-r-+1);
        pois.insert(t-1);
        pois.insert(t);
        pois.insert(t+1);
    }
    
    // sort y's so that we know there is a blind spot when we see one
    sort(v, v+N);
    
    int c = 0;
    for(int i = 0; i < N; i++){
        iter it = pois.lower_bound(v[i].second.first);
        iter it2 = pois.lower_bound(v[i].second.second);
        
        if(it != it2){
            // it's not entirely in an "invisible zone"
            // in the beginning there are no invisible zones, c > 1
            c++;
            pois.erase(it, it2);
        }
    }
    
    cout << c << endl;
    
}
