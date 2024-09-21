#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// diffs_len은 배열 diffs의 길이입니다.
// times_len은 배열 times의 길이입니다.
int solution(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit) {
    int answer = 0;
    int top = 1;
    int low = 0;
    int mid;
    long long n = diffs_len;

    long long sumCurTime = 0;//숫자가 넘어가서 처리가 안되었던 것이다.
    int curNum = 0;
    bool condition;//조건 나누기 용

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

        //조건 확인
        for (long long i = 0; i < n; i++)
        {
            if (diffs[i] <= mid)
            {
                sumCurTime += times[i];
            }
            else
            {
                int count = diffs[i] - mid;//도전하는 횟수
                if (i == 0)
                    sumCurTime += times[i] * count;
                else
                    sumCurTime += (times[i - 1] + times[i]) * count;//이전도전과 현재 시간
                sumCurTime += times[i];//마지막 도전횟수
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