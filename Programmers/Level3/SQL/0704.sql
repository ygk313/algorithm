-- Programmers Level 3 : 즐겨찾기가 가장 많은 식당 정보 출력하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131123

-- GROUP BY는 해당 컬럼을 기준으로 그룹 연산
-- 주의할 점: GROUP BY로 묶으면 가장 상단에 있는 데이터를 임의로 가져온다. 우연의 일치로 가장 큰 레코드를 가져올 수도 있지만 이는 그냥
-- 우연의 일치이다.


SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM REST_INFO
WHERE (FOOD_TYPE, FAVORITES) IN (SELECT FOOD_TYPE, MAX(FAVORITES)
                                FROM REST_INFO
                                GROUP BY FOOD_TYPE)
ORDER BY FOOD_TYPE DESC;