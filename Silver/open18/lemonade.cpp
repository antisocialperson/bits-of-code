#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool comp(int a, int b){
  
  return a > b;
  
}

int main(){
  
  freopen("lemonade.in", "r", stdin);
  freopen("lemonade.out", "w", stdout);
  
  int N;
  cin >> N;
  
  int A[N];
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  
  sort(A, A+N, comp);
  
  int inl = 0;
  int best = 0;
  for(int i = 0; i < N; i++){
    if(A[i] >= inl){
      best++;
      inl++;
    }
  }
  cout << best << endl;
  
}
