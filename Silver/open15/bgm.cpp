#include <iostream>
#include <cstdio>

using namespace std;

int N;
long long ns[256][7];

int main(){
    
    freopen("bgm.in", "r", stdin);
    freopen("bgm.out", "w", stdout);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        char k;
        int v;
        cin >> k >> v;
        ns[k][(v%7+7)%7]++; // add 1 for the residue
    }
    
    // count up the number of possibilities
    long long k = 0;
    
    for(int B = 0; B < 7; B++)
    for(int E = 0; E < 7; E++)
    for(int S = 0; S < 7; S++)
    for(int I = 0; I < 7; I++)
    for(int G = 0; G < 7; G++)
    for(int O = 0; O < 7; O++)
    for(int M = 0; M < 7; M++) {
        if (((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O)) % 7 == 0) {
            k += ns['B'][B] * ns['E'][E] * ns['S'][S] * ns['I'][I] *
                ns['G'][G] * ns['O'][O] * ns['M'][M];
        }
    }
    
    // ehh
    cout << k << "\n";
    
}
