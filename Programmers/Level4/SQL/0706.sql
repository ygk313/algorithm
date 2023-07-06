--Programmers Lv 4. 식품분류별 가장 비싼 식품의 정보 조회
--https://school.programmers.co.kr/learn/courses/30/lessons/131116

--Programmers Lv 3. 즐겨찾기가 가장 많은 식당 정보 출력과 유사한 문제 

SELECT CATEGORY, PRICE AS MAX_PRICE, PRODUCT_NAME
FROM FOOD_PRODUCT
WHERE CATEGORY IN ('식용유', '과자', '국', '김치') AND 
                (CATEGORY, PRICE) IN (
                                SELECT CATEGORY, MAX(PRICE)
                                FROM FOOD_PRODUCT
                                GROUP BY CATEGORY)
ORDER BY PRICE DESC;