-- Programmers Lv 4. 주문량 많은 아이스크림들 조회하기.
-- https://school.programmers.co.kr/learn/courses/30/lessons/133027

WITH J AS (
    SELECT FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER
    FROM JULY
    GROUP BY FLAVOR )

SELECT F.FLAVOR
FROM J JOIN FIRST_HALF F ON J.FLAVOR = F.FLAVOR
ORDER BY  F.TOTAL_ORDER + J.TOTAL_ORDER DESC
LIMIT 3;