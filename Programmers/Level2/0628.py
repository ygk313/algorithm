#줄 서는 방법 - https://school.programmers.co.kr/learn/courses/30/lessons/12936
def solution(n, k):
    answer = []

    # 숫자 저장하기 - 팩토리얼 값
    d = [0 for _ in range(21)]
    d[1] = 1

    for i in range(2, n):
        d[i] = d[i-1]*i
    nums = [i for i in range(1, n+1)]
    s = n - 1

    #계산하기
    while s != 0 :
        idx = k // d[s]
        k %= d[s]

        if k == 0:
            answer.append(nums.pop(idx-1))
        else:
            answer.append(nums.pop(idx))

        s-=1

    answer.append(nums.pop())
    return answer
