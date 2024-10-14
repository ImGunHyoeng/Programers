//효용성에서 탈락
//#include <string>
//#include <vector>
//#include <list>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(vector<int> prices) {
//    vector<int> answer;
//    vector<bool> isSmall(prices.size(), false);//불 변수 처리
//    list<pair<int, int>> list;
//    //list.push_back({prices[0],1});
//
//    for (int i = 0; i < prices.size() - 1; i++)
//    {
//        int count = 0;
//        list.push_back({ prices[i],0 });
//        for (auto j = list.begin(); j != list.end(); j++)
//        {
//            if (isSmall[count])
//            {
//                count++;
//                continue;
//            }
//
//            if (j->first > prices[i+1])
//            {
//                isSmall[count] = true;
//                j->second++;
//            }
//
//            if (j->first <= prices[i+1] && !isSmall[count])
//            {
//                j->second++;
//            }
//            count++;
//            //answer//벡터로 처리
//            //list.erase(j);
//        }
//
//    }
//
//    for (auto j = list.begin(); j != list.end(); j++)//큐에 남아있는 값을 처리해줌.
//    {
//        answer.push_back(j->second);
//        //list.pop_front();
//    }
//    answer.push_back(0);
//    return answer;
//}
//
//int main()
//{
//  vector<int> temp=solution(vector<int>{1, 2, 3, 2, 3});
//  for (auto it= temp.begin(); it != temp.end(); it++)
//      cout << *it<<' ';
//}

#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size()); // prices 크기만큼 answer을 초기화 한다.
    stack<int> s;

    for (int i = 0; i < prices.size() - 1; i++) { // 마지막 price는 뭘해도 0초이니 제외하고 반복문 실행.
        while (!s.empty() && prices[i] < prices[s.top()]) { // 하락장이라면
            answer[s.top()] = i - s.top(); // 기간은 현재 인덱스 i와 top()의 인덱스 차이가 된다.
            s.pop(); // top의 기간을 구했으니 pop.
        }
        s.push(i); // i를 push. 인덱스 i는 최고 가격이 된다.
    }

    /* 스택에 남은 원소들 처리 */
    while (!s.empty()) { // 스택에 남은 것들은 항상 상승만 했기에
        answer[s.top()] = (prices.size() - 1) - s.top(); //맨 끝 위치에서 top을 빼줘서 끝까지 상승기간 구함. 
        s.pop();
    }
    answer[prices.size() - 1] = 0; // 마지막 price는 항상 0이 나옴.

    return answer;
}