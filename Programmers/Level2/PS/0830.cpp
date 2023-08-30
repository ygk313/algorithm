// Programmers Lv 3. 디펜스 게임
// https://school.programmers.co.kr/learn/courses/30/lessons/142085?language=cpp#
// 조건 값과 같은 변경을 줄 수 있는 곳에서 반례를 떠올리기.
// 반례: 7, 3, [5,5,5,5,2,3,1]

#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;
int pq_tot = 0;

int solution(int n, int k, vector<int> enemy) {
    int idx = 0;
    int answer = 0;
    
    while (idx < enemy.size()) {
        
        if (enemy[idx] + pq_tot <= n){
            pq.push(enemy[idx]);
            pq_tot += enemy[idx];
            
        }
        else{
            if (k == 0){
                cout<<idx;
                break;
            }
            k--;
            if (!pq.empty() && (pq.top() > enemy[idx])){
                    pq_tot -= pq.top();
                    pq.pop();
                    pq.push(enemy[idx]);
                    pq_tot += enemy[idx];
                }
            }
         idx++;
    }
    
    answer = idx;
    return answer;
}

// 이외에 참고하면 좋은 답안 - 최소힙 (힙 내에는 무적권에 해당하는 것만 두기)
// import heapq

// def solution(n, k, enmey):
//     if k >= len(enemey):
//         return len(enemy)

//     pq = []

//     for i in range(len(enemy)):
//         heapq.heappush(pq, enemy[i])

//         if len(pq) > k:
//             last = heapq.heappop(pq)
//             if last > n: return i 
//             n -= last

//     return len(enemy)
