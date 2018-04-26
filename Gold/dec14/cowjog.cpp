/*******************************************************
 * December 2014, USACO Gold, Question 1 (Cow Jog):
 * 
 * Two cows will be in different lanes if one
 * passes through the other at any point in time, quite
 * obviously. 
 * 
 * We'll know when a cow passes another cow. That's if
 * the speed of one cow is more than the speed of
 * another, and the position of the faster cow is less
 * than the position of the slower cow.
 * 
 * Assign all cows to a lane, and a cow that isn't fast
 * enough will go to a new lane. This can be considered
 * a greedy algorithm.
 * 
 * We can use Longest Increasing Subsequence to solve
 * this question.
*******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");
    
    // number of cows, duration of jog
    int N, T;
    fin >> N >> T;
    
    // lanes
    vector<int> lanes;
    for(int i = 0; i < N; i++){
        // position, speed
        int p, s;
        fin >> p >> s;
        // position to final position. negative to reverse the order and keep it as increasing
        p = -(p + s*T);
        
        // first lane or cow overtaken
        if(lanes.empty() || p >= lanes.back()){
            lanes.push_back(p);
        } 
        // normal scenario
        else{
            *upper_bound(lanes.begin(), lanes.end(), p) = p;
        }
    }

    // lanes.size() ends up as the number of lanes
    fout << lanes.size() << endl;
    
}
