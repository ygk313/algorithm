-- Programmers Lv 3. 대여횟수가 많은 자동차들의 월별 대여 횟수 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/151139

-- <<문제를 이해하는 것이 어려웠던 문제>>
-- 대여 시작일을 기준으로 2022년 8월부터 2022년 10월까지 총 대여 횟수가 5회 이상인 자동차들에 대해서 해당 기간 동안의 월별 자동차 ID별
-- 총 대여 횟수 리스트를 출력. 특정 월의 총 대여 횟수가 0인 경우에는 결과에서 제외하기.

-- 1. 먼저 대여횟수가 5회 이상인 자동차 고르기.
-- 2. 월별, 자동차별에 대해 대여횟수 구하기

WITH CAR_ID_CHECK_LIST AS (
    SELECT CAR_ID
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE START_DATE >= '2022-08-01' AND START_DATE <= '2022-10-30'
    GROUP BY CAR_ID
    HAVING COUNT(CAR_ID) >= 5
)

SELECT MONTH(START_DATE) AS MONTH, CAR_ID, COUNT(HISTORY_ID) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE CAR_ID IN (SELECT * FROM CAR_ID_CHECK_LIST) AND START_DATE >= '2022-08-01' AND START_DATE <= '2022-10-31'
GROUP BY MONTH, CAR_ID
HAVING RECORDS > 0
ORDER BY MONTH, CAR_ID DESC;