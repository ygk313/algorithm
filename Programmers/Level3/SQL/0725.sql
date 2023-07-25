-- Programmers Lv 3. 자동차 대여 기록에서 대여 중 / 대여 가능 여부 구분하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/157340
-- 2022-10-16이 포함된 날짜 중 가장 최근을 골라내야 함. 그래서 MAX 사용.

SELECT CAR_ID, 
        MAX(IF (DATE_FORMAT(START_DATE, '%Y-%m-%d') <= '2022-10-16' AND DATE_FORMAT(END_DATE, '%Y-%m-%d') >= '2022-10-16', '대여중', '대여 가능')) AS 'AVAILABILITY'
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
ORDER BY CAR_ID DESC, HISTORY_ID DESC;
