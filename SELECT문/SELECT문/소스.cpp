//평일 일일 대여 요금 구하기 LV1
--코드를 입력하세요
SELECT ROUND(AVG(DAILY_FEE), 0) AS AVERAGE_FEE FROM CAR_RENTAL_COMPANY_CAR WHERE CAR_TYPE = 'SUV';

//재구매가 일어난 상품과 회원리스트 구하기(GROUP BY, ORDER BY) LV2
SELECT USER_ID, PRODUCT_ID FROM ONLINE_SALE
GROUP BY USER_ID, PRODUCT_ID
HAVING COUNT(*) > 1
ORDER BY USER_ID ASC, PRODUCT_ID DESC;

//역순 정렬하기(ORDER BY)SELECT LV 1
--코드를 입력하세요
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY ANIMAL_ID DESC;

//대장균 크기에 따라서 분류하기(IF문 사용) 특이 문법 LV3 IF
SELECT ID, IF(SIZE_OF_COLONY <= 100, 'LOW',
    IF(SIZE_OF_COLONY <= 1000, 'MEDIUM', 'HIGH')) AS SIZE
    FROM ECOLI_DATA
    ORDER BY ID
