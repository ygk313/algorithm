// (다시 풀어볼 문제) Programmers Lv 2. 마법의 엘레베이터 - Greedy
// https://school.programmers.co.kr/learn/courses/30/lessons/148653?language=cpp#

// 현자리 수가 5이고 다음 자리수가 5보다 클 때 올려주는 것이 적게 이동함.
// 5일 때는 올리던 내리던 다음에는 자리수가 +1 이 되거나 그대로 이기 때문에 이를 고려해야 함.
// 0으로 내려가거나 10으로 올라가거나!!

#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0){
        int n = storey % 10;
        
        // 현 자리수가 5보다 큰 경우
        if (n > 5){
            // 위로 올려주기
            answer += 10 - n;
            // 다음 자리수를 1개 더 크게
            storey = (storey / 10) + 1;
        }
        // 현 자리수가 5인 경우
        else if (n == 5){
            // 다음자리수에 따라 결정되는데,
            // 5이상인 경우, 올려주기
            if ((storey/10)%10 >= 5){
                storey /= 10;
                storey += 1;
            }
            // 5미만인 경우 그대로 유지. -> 올리는 게 더 작업이 필요하기 때문에.
            else {
                storey /= 10;
            }
            answer += 5;
        }
        // 5보다 작은 경우, 현자리 수만큼 빼주고 그대로 유지.
        else{
            answer += n;
            storey /= 10;
        }
    }
    
    return answer;
}