-- Programmers Lv 2. 자동차 평균 대여 기간 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/157342
-- 두 날짜 간의 차이를 구하는 것이 중요한 문제! 
-- to_days는 %Y-%m-%d로 된 형식을 일수로 바꾸어 줌. DATE_DIFF라는 함수도 존재함. 
-- 그리고 빌린 날도 하루 더해야 함.

SELECT CAR_ID, ROUND(AVG(to_days(END_DATE)-to_days(START_DATE)+1), 1) AS AVERAGE_DURATION
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
HAVING AVERAGE_DURATION >= 7
ORDER BY AVERAGE_DURATION DESC, CAR_ID DESC;