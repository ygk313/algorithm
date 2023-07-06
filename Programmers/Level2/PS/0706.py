# Programmers Lv 2. 호텔 대실
# https://school.programmers.co.kr/learn/courses/30/lessons/155651/

import heapq

def solution(book_time):
    answer = 0
    
    for i in range(len(book_time)):
        book = book_time[i]
        for i in range(2):
            h, m  = map(int, book[i].split(":"))
            book[i] = h*60 + m
            if i == 1: book[i] += 10
    
    book_time.sort()
    
    pq = []
    for book in book_time:
        if pq and pq[0] <= book[0]:
            heapq.heappop(pq)
        heapq.heappush(pq, book[1])

    answer = len(pq)
    return answer

# 참고하면 좋은 풀이
# 중복되는 경우 만큼의 객실이 필요하다는 점을 이용.

# def solution(book_time):
#     time_table = [0 for _ in range(60 * 24)]
#     for start, end in book_time:
#         start_minutes = 60 * int(start[:2]) + int(start[3:])
#         end_minutes = 60 * int(end[:2]) + int(end[3:]) + 10

#         if end_minutes > 60 * 24 - 1:
#             end_minutes = 60 * 24 - 1

#         for i in range(start_minutes, end_minutes):
#             time_table[i] += 1
#     return max(time_table)