//���� ���� �뿩 ��� ���ϱ� LV1
--�ڵ带 �Է��ϼ���
SELECT ROUND(AVG(DAILY_FEE), 0) AS AVERAGE_FEE FROM CAR_RENTAL_COMPANY_CAR WHERE CAR_TYPE = 'SUV';

//�籸�Ű� �Ͼ ��ǰ�� ȸ������Ʈ ���ϱ�(GROUP BY, ORDER BY) LV2
SELECT USER_ID, PRODUCT_ID FROM ONLINE_SALE
GROUP BY USER_ID, PRODUCT_ID
HAVING COUNT(*) > 1
ORDER BY USER_ID ASC, PRODUCT_ID DESC;

//���� �����ϱ�(ORDER BY)SELECT LV 1
--�ڵ带 �Է��ϼ���
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY ANIMAL_ID DESC;

//����� ũ�⿡ ���� �з��ϱ�(IF�� ���) Ư�� ���� LV3 IF
SELECT ID, IF(SIZE_OF_COLONY <= 100, 'LOW',
    IF(SIZE_OF_COLONY <= 1000, 'MEDIUM', 'HIGH')) AS SIZE
    FROM ECOLI_DATA
    ORDER BY ID

//����յ��� �ڽ��� �� ���ϱ� lv3 join,left join
//-- �ڵ带 �ۼ����ּ���
//Select IDPARENT_ID from ECOLI_DATA; #GROUP BY ID, PARENT_ID HAVING ID = PARENT_ID;
//(Select ID, PARENT_ID from ECOLI_DATA as gd where temp.ID = gd.PARENT_ID);
//�׷����� temp id�� �����ش�.
//(Select temp.ID, COUNT(temp.ID) as CHILD_COUNT from ECOLI_DATA as temp, ECOLI_DATA AS GD WHERE temp.ID = GD.PARENT_ID GROUP BY temp.ID)
//select og.ID, ct.CHILD_COUNT from ECOLI_DATA og,
//(Select temp.ID, COUNT(temp.ID) as CHILD_COUNT from ECOLI_DATA as temp, ECOLI_DATA AS GD GROUP BY temp.ID) as ct;
//select og.ID, ct.CHILD_COUNT from ECOLI_DATA og, (Select temp.ID, COUNT(temp.ID) as CHILD_COUNT from ECOLI_DATA as temp, ECOLI_DATA AS GD WHERE temp.ID = GD.PARENT_ID GROUP BY temp.ID)as ct where og.ID = ct.ID;
//
//Select temp.ID, COUNT(temp.ID) as CHILD_COUNT from ECOLI_DATA as temp, ECOLI_DATA AS GD WHERE temp.ID = GD.PARENT_ID GROUP BY temp.ID;
//select og.ID, ct.CHILD_COUNT from ECOLI_DATA og LEFT OUTER JOIN(Select temp.ID, COUNT(temp.ID) as CHILD_COUNT from ECOLI_DATA as temp, ECOLI_DATA AS GD WHERE temp.ID = GD.PARENT_ID GROUP BY temp.ID)as ct ON og.ID = ct.ID;
select og.ID, IF(ISNULL(ct.CHILD_COUNT), 0, ct.CHILD_COUNT) AS CHILD_COUNT from ECOLI_DATA as og LEFT OUTER JOIN(Select temp.ID, COUNT(temp.ID) as CHILD_COUNT from ECOLI_DATA as temp, ECOLI_DATA AS GD WHERE temp.ID = GD.PARENT_ID GROUP BY temp.ID)as ct ON og.ID = ct.ID;