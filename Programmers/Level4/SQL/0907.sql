-- Programmers Lv 4. 오프라인/온라인 판매 데이터 통합하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131537

-- 문제를 차근히 다시 읽고 파악하는 것이 중요하다.
-- OFFLINE과 ONLINE 테이블"에서" 2022년 03월의 오프라인/온라인 상품 판매 데이터의 판매 날짜, 상품ID, 유저ID, 판매량을 출력하는 SQL문을 출력하시오.
-- OFFLINE 테이블의 판매 데이터의 USER_ID 값은 NULL로 표시해주세요. -> OFFLINE에는 USER_ID라는 필드가 없고, 문제 자체가 데이터 통합이다. 여기서 힌트를 얻어야 할 듯..

-- LEFT OUTER JOIN을 활용하는 문제가 아닌 UNION ALL을 활용하는 문제 였음.


SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') AS SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
FROM ONLINE_SALE
WHERE DATE_FORMAT(SALES_DATE, '%Y-%m') = "2022-03"

UNION ALL 

SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') AS SALES_DATE, PRODUCT_ID, NULL AS USER_ID, SALES_AMOUNT
FROM OFFLINE_SALE
WHERE DATE_FORMAT(SALES_DATE, '%Y-%m') = "2022-03"

ORDER BY SALES_DATE, PRODUCT_ID, USER_ID;