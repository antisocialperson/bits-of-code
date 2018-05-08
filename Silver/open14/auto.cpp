#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<string, int> psi;

// does the fragment have the same prefix as the word?
bool same_prefix(string frag, string comp){
    // cout << frag << " " << comp << endl;
    if(frag.size() > comp.size()){
        return false;
    } else{
        return comp.substr(0, frag.size()) == frag;
    }
}

int main() {
    
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);
    
    int W, N;
    cin >> W >> N;
    
    // all the words, indices of the words
    psi dict[W];
    
    for(int i = 0; i < W; i++){
        string s;
        cin >> s;
        dict[i] = make_pair(s, i);
    }
    
    // like sorting a char[]: sorts in lexicographical order
    sort(dict, dict+W);
    
    for(int i = 0; i < N; i++){
        int k;
        // fragment of a word
        string frag;
        cin >> k >> frag;
        k--;
        
        // cout << k << " " << frag << endl;
        
        // the first string's index.
        int lowest = lower_bound(dict, dict+W, make_pair(frag, 0))-dict;
        // cout << "moo" << endl;
        
        // if it has the same prefix
        if(lowest+k < W && same_prefix(frag, dict[lowest+k].first)){
            cout << dict[lowest+k].second + 1 << endl;
        } else{
            cout << -1 << endl;
        }
        
    }
    
}
