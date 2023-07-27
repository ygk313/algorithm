# Programmers Lv 2. 시소짝궁
# https://school.programmers.co.kr/learn/courses/30/lessons/152996?language=python3
# O(N^2)을 어떻게 O(N)으로 줄일지 관건이었던 문제

import collections

def solution(weights):
    answer = 0
    
    c = collections.Counter(weights)
    
    for x,v in c.items():
        if v >= 2: answer += ((v-1)*v / 2)
    
    weights = set(weights)
    
    for w in weights:
        if w*2 in weights:
            answer += (c[w] * c[w*2])
        if w*3/2 in weights:
            answer += (c[w] * c[w*3/2])
        if w*4/3 in weights:
            answer += (c[w] * c[w*4/3])
    
    return answer