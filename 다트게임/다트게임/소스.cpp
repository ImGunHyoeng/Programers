#include <string>
#include <stack>
//#include <cmath>
#include <cctype>
using namespace std;

stack<int> st;
int solution(string dartResult) {
    int answer = 0;
    int num = 0;
    for (char chr : dartResult)
    {
        //(chr<48||chr>57)//문자 판별
        if (!isdigit(chr))
        {
            int temp = 0;
            st.push(num);//숫자 등록
            num = 0;//숫자 초기화
            if (chr == 'S')
            {
                continue;
                //할거 없음
            }
            if (chr == 'D')
            {
                temp = st.top();
                st.pop();
                // st.push((int)(pow(temp,2)));
                st.push(temp * temp);
            }
            if (chr == 'T')
            {
                temp = st.top();
                st.pop();
                st.push(temp * temp * temp);
                //st.push((int)(pow(temp,3)));
            }
            if (chr == '#')
            {
                temp = st.top();
                st.pop();
                temp *= -1;
                st.push(temp);
            }
            if (chr == '*')
            {
                if (st.size() >= 2)
                {
                    temp = st.top();
                    st.pop();

                    int pre;
                    pre = st.top();
                    st.pop();
                    pre *= 2;
                    temp *= 2;

                    st.push(pre);
                    st.push(temp);

                }
                else
                {
                    temp = st.top();
                    st.pop();

                    temp *= 2;
                    st.push(temp);
                }
            }

        }
        else
        {
            num = num * 10 + (chr - 48);//10을 받기 위함.
        }
    }

    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    return answer;
}