#프로그래머스 Lv 1. 아픈동물찾기- https://school.programmers.co.kr/learn/courses/30/lessons/59036

SELECT animal_id, name
from animal_ins
where intake_condition LIKE 'Sick'
order by animal_id;
