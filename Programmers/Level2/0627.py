# 뒤에 있는 큰 수 찾기 - https://school.programmers.co.kr/learn/courses/30/lessons/154539

def solution(numbers):
    
    d = [-1 for _ in range(len(numbers))]
    
    for i in range(len(numbers)-2, -1, -1):
        if numbers[i] >= numbers[i+1]:
            for j in range(i+1, len(numbers)):
                if d[j] > numbers[i]: d[i] = d[j]; break
                if d[j] == -1: break
        else:
            d[i] = numbers[i+1]
                    
    return d