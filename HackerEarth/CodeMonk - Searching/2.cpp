/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int mark, key;
        cin >> mark >> key;
        
        if(mark == 0){
            if(key > A[N-1]){
                cout << 0 << endl;
                continue;
            }
        } else if(mark == 1){
            if(key >= A[N-1]){
                cout << 0 << endl;
                continue;
            }
        }
        int lo = 0, hi = N-1;
        while(lo != hi){
            int mid = (lo + hi)/2;
            if((A[mid] > key && mark == 1) || A[mid] >= key && mark == 0){
                hi = mid;
            } else{
                lo = mid+1;
            }
        }
        cout << N-lo << endl;
    }
}
