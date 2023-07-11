# Programmers Lv 1. 숫자 짝꿍
# https://school.programmers.co.kr/learn/courses/30/lessons/131128

def solution(X, Y):
    answer = ''
    x_num , y_num = [0 for _ in range(10)], [0 for _ in range(10)]
    
    for x in X:
        x_num[int(x)] +=1
    for y in Y:
        y_num[int(y)] +=1
    
    for i in range(9, -1, -1):
        if x_num[i] != 0 and y_num[i] != 0 and abs(x_num[i] - y_num[i]) >= 0:
            answer += (str(i) * min(x_num[i], y_num[i]))
    
    if answer == '':
        return '-1'
    else:
        if answer == '0' * min(x_num[i], y_num[i]):
            return '0'
        else:
            return answer