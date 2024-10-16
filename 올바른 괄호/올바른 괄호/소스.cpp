#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    vector<char> stack;

    for (auto i = s.begin(); i != s.end(); i++)
    {
        if (*i == '(')
        {
            stack.push_back(*i);
            //cout<<"push"<<'\n';
        }
        if (*i == ')')
        {
            if (stack.size() == 0)
            {
                answer = false;
                break;
            }
            //cout<<"pop"<<'\n';
            stack.pop_back();
        }
        //cout<<stack.size()<<'\n';
    }
    //cout<<stack.size();
    if (answer)
    {
        if (stack.size() == 0)
            answer = true;
        if (stack.size() > 0)
            answer = false;
    }
    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    //cout << "Hello Cpp" << endl;

    return answer;
}