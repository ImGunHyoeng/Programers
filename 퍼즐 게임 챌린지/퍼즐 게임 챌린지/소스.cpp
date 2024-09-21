#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// diffs_len�� �迭 diffs�� �����Դϴ�.
// times_len�� �迭 times�� �����Դϴ�.
int solution(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit) {
    int answer = 0;
    int top = 1;
    int low = 0;
    int mid;
    long long n = diffs_len;

    long long sumCurTime = 0;//���ڰ� �Ѿ�� ó���� �ȵǾ��� ���̴�.
    int curNum = 0;
    bool condition;//���� ������ ��

    //top setting
    for (long long i = 0; i < diffs_len; i++)
    {
        if (top < diffs[i])
            top = diffs[i];
    }
    //binary search

    while (low + 1 < top)
    {
        sumCurTime = 0;
        condition = true;
        mid = (low + top) / 2;

        //���� Ȯ��
        for (long long i = 0; i < n; i++)
        {
            if (diffs[i] <= mid)
            {
                sumCurTime += times[i];
            }
            else
            {
                int count = diffs[i] - mid;//�����ϴ� Ƚ��
                if (i == 0)
                    sumCurTime += times[i] * count;
                else
                    sumCurTime += (times[i - 1] + times[i]) * count;//���������� ���� �ð�
                sumCurTime += times[i];//������ ����Ƚ��
            }

            if (sumCurTime <= limit)
                continue;
            condition = false;
            break;
        }
        if (condition)
        {
            top = mid;
        }
        else
        {
            low = mid;
        }
    }
    return top;
}