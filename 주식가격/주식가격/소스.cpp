//ȿ�뼺���� Ż��
//#include <string>
//#include <vector>
//#include <list>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(vector<int> prices) {
//    vector<int> answer;
//    vector<bool> isSmall(prices.size(), false);//�� ���� ó��
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
//            //answer//���ͷ� ó��
//            //list.erase(j);
//        }
//
//    }
//
//    for (auto j = list.begin(); j != list.end(); j++)//ť�� �����ִ� ���� ó������.
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
    vector<int> answer(prices.size()); // prices ũ�⸸ŭ answer�� �ʱ�ȭ �Ѵ�.
    stack<int> s;

    for (int i = 0; i < prices.size() - 1; i++) { // ������ price�� ���ص� 0���̴� �����ϰ� �ݺ��� ����.
        while (!s.empty() && prices[i] < prices[s.top()]) { // �϶����̶��
            answer[s.top()] = i - s.top(); // �Ⱓ�� ���� �ε��� i�� top()�� �ε��� ���̰� �ȴ�.
            s.pop(); // top�� �Ⱓ�� �������� pop.
        }
        s.push(i); // i�� push. �ε��� i�� �ְ� ������ �ȴ�.
    }

    /* ���ÿ� ���� ���ҵ� ó�� */
    while (!s.empty()) { // ���ÿ� ���� �͵��� �׻� ��¸� �߱⿡
        answer[s.top()] = (prices.size() - 1) - s.top(); //�� �� ��ġ���� top�� ���༭ ������ ��±Ⱓ ����. 
        s.pop();
    }
    answer[prices.size() - 1] = 0; // ������ price�� �׻� 0�� ����.

    return answer;
}