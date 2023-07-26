-- Programmers Lv 4. 년,월,성별 별 상품 구매 회원 수 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131532
-- 동일한 날짜, 회원 ID, 상품 ID 조합은 하나의 데이터만 존재 -> DISTINCT 조건 넣기
-- DISTINCT 조건이 필요한 이유는 한 회원이 여러번 들어있기 때문이다.

SELECT DATE_FORMAT(B.SALES_DATE, '%Y') AS YEAR, DATE_FORMAT(B.SALES_DATE, '%m') AS MONTH, A.GENDER , COUNT(DISTINCT B.USER_ID) AS USERS
FROM USER_INFO A JOIN ONLINE_SALE B ON A.USER_ID = B.USER_ID
WHERE A.GENDER IS NOT NULL
GROUP BY DATE_FORMAT(B.SALES_DATE, '%Y-%m'), A.GENDER
ORDER BY YEAR, MONTH, GENDER;