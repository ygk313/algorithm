# 프로그래머스 Lv 2. 점 찍기 - https://school.programmers.co.kr/learn/courses/30/lessons/140107

def solution(k, d):
    answer = 0
    
    a = 0
    
    while a*k <= d:
        y = (d**2 - (a*k)**2) ** (1/2)
        y = int(y)
        answer += (y//k)+1
        a+=1

        
    return answer