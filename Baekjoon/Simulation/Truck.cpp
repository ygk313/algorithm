// 백준 시뮬레이션 - 트럭
// https://www.acmicpc.net/problem/13335

#include <bits/stdc++.h>

using namespace std;

int cur_time = 0;
int weight = 0;
int passed_in = 0;

int chk_time[1001];
int trucks[1001];
queue<int> bridge;


int main(){
    
    int n, w, L;
    cin>>n>>w>>L;
    
    for(int i=0; i<n; i++){
        cin>>trucks[i];
    }
    
    while (passed_in < n){
        
        if (!bridge.empty() && cur_time - chk_time[bridge.front()] == w){
            weight -= trucks[bridge.front()];
            bridge.pop();
        }
        
        if ((weight + trucks[passed_in] <= L) && bridge.size() < w){
            bridge.push(passed_in);
            weight += trucks[passed_in];
            chk_time[passed_in] = cur_time;
            passed_in++;
        }
        cur_time++;
        
    }
    
    cout<<cur_time+w;
    return 0;
}