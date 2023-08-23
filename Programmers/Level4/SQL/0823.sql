-- Programmers Lv 4. 우유와 요거트가 담긴 장바구니
-- https://school.programmers.co.kr/learn/courses/30/lessons/62284

SELECT DISTINCT A.CART_ID
FROM CART_PRODUCTS A JOIN CART_PRODUCTS B ON A.CART_ID = B.CART_ID
WHERE (A.NAME = 'Milk' AND B.NAME = 'Yogurt') OR (A.NAME = 'Yogurt' AND B.NAME = 'Milk')
ORDER BY A.CART_ID;

-- Better Answer
-- SELECT CART_ID
-- FROM CART_PRODUCTS
-- WHERE NAME IN ('Milk', 'Yogurt')
-- GROUP BY CART_ID
-- HAVING COUNT(DISTINCT NAME)=2;
