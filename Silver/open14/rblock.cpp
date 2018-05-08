#include <bits/stdc++.h>

using namespace std;

const int MAXN = 250;
int connections[MAXN][MAXN];
int wts[MAXN];
bool vis[MAXN];
int last[MAXN];

int best(int N){
	// start is always 0, end is always N-1
	// distance is always infinity
	memset(wts, 63, sizeof(wts));
	memset(vis, false, sizeof(vis));
	memset(last, -1, sizeof(last));
	
	// the starting vertex is 0
	wts[0] = 0;
	
	while(true){
		// no vertex yet
		int next = -1;
		for(int i = 0; i < N; i++){
			if(!vis[i] && (next == -1 || wts[i] < wts[next])){
				next = i;
			}
		}
		// if there is no vertex reachable
		if(next == -1){
			break;
		}
		
		vis[next] = true;
		
		for(int i = 0; i < N; i++){
			int dist = wts[next] + connections[next][i];
			if(dist < wts[i]){
				wts[i] = dist;
				last[i] = next;
			}
		}
	}
	
	return wts[N-1];
	
}

int main() {
	
	freopen("rblock.in", "r", stdin);
	freopen("rblock.out", "w", stdout);
	
	memset(connections, 63, sizeof(connections));
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int f, s, d;
		cin >> f >> s >> d;
		f--;
		s--;
		// the distance between each
		connections[f][s] = d;
		connections[s][f] = d;
	}
	
	/*
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << connections[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	/*
	spaces are ^ better than tabs
	          not
	*/
	
	// find shortest path with no double
	int orig = best(N);
	
	vector<int> path;
	
	for(int i = N-1; i >= 0; i = last[i]){
		// cout << i << endl;
		path.push_back(i);
	}
	
	// the most time that the cows can waste
	int most_damage = -1;
	
	for(int i = 0; i < path.size()-1; i++){
		int p = path[i];
		int q = path[i+1];
		// 2 consecutive stops: p, q
		// double it and see the results
		connections[p][q] *= 2;
		connections[q][p] *= 2;
		most_damage = max(best(N), most_damage);
		connections[p][q] /= 2;
		connections[q][p] /= 2;
	}
	
	cout << most_damage-orig<< endl;
	
}
