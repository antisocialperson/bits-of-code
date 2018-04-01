#include <iostream>
#include <cstdio>

using namespace std;

int sum(int num){
  int temp = 0;
  for(int i = 1; i * i <= num; i++){
    if(num % i == 0) {
      temp += i;
      if (num / i != i) temp += num/i;
    }
  }
  return temp-num;
}

int main(){
  freopen("cowpals.in", "r", stdin);
  freopen("cowpals.out", "w", stdout);
  int cow;
  cin >> cow;
  for(;;cow++){
    int pal = sum(cow);
    if(cow == pal) continue;
    if(cow == sum(pal)){
      cout << cow << " " << pal << endl;
      return 0;
    }
  }
}
