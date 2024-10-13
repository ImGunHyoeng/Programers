//버킷 정렬+ 퀵정렬
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//int partition(vector<int>& temp, int p, int r, int standard);
//void quicksort(vector<int>& temp, int p, int r, int standard)
//{
//    if (p < r)
//    {
//        int q = partition(temp, p, r, standard);
//        quicksort(temp, p, q - 1, standard);
//        quicksort(temp, q + 1, r, standard);
//    }
//}
//int partition(vector<int>& temp, int p, int r, int standard)
//{
//    int x = temp[r] % standard;
//    int q = p - 1;
//    for (int i = p; i < r; i++)//내림차순으로 정리
//    {
//        int y = temp[i] % standard;
//        if (x == y)
//        {
//            if (y % 10 != 0)//이렇게 되면 자신보다 큰값
//            {
//                int t;
//                q += 1;
//                t = temp[q];
//                temp[q] = temp[i];
//                temp[i] = t;
//                continue;
//            }
//        }
//
//        if (x < y && x != 0)
//        {
//            int t;
//            q += 1;
//            t = temp[q];
//            temp[q] = temp[i];
//            temp[i] = t;
//            continue;
//        }
//    }
//    int t = temp[q + 1];
//    temp[q + 1] = temp[r];
//    temp[r] = t;
//    return q + 1;
//
//}
//void selectBucket(vector<vector<int>>& temp, int num,int realnum)
//{
//    switch (num)
//    {
//    case 1:
//        temp[1].push_back(realnum);
//        break;
//    case 2:
//        temp[2].push_back(realnum);
//        break;
//    case 3:
//        temp[3].push_back(realnum);
//        break;
//    case 4:
//        temp[4].push_back(realnum);
//        break;
//    case 5:
//        temp[5].push_back(realnum);
//        break;
//    case 6:
//        temp[6].push_back(realnum);
//        break;
//    case 7:
//        temp[7].push_back(realnum);
//        break;
//    case 8:
//        temp[8].push_back(realnum);
//        break;
//    case 9:
//        temp[9].push_back(realnum);
//        break;
//    }
//}
//
//string solution(vector<int> numbers) {
//    string answer = "";
//    vector<vector<int>> buckets(10);
//    //버킷에 값 채우기
//    for (int i = 0; i < numbers.size(); i++)
//    {
//        int index = 0;
//        if (numbers[i] % 1000 == 0)
//        {
//            buckets[1].push_back(1000);
//            continue;
//        }
//        if (numbers[i] == 0)
//        {
//            buckets[0].push_back(0);
//            continue;
//        }
//
//        if ((numbers[i] / 100) >= 1)
//        {
//            selectBucket(buckets, numbers[i] / 100, numbers[i]);
//            continue;
//        }
//        if ((numbers[i] / 10) >= 1)
//        {
//            selectBucket(buckets, numbers[i] / 10, numbers[i]);
//            continue;
//        }
//        selectBucket(buckets, numbers[i], numbers[i]);
//    }
//
//    for (int i = 1; i <= 9; i++)//0은 어차피 하나의 경우밖에 없다.
//    {
//        //sort(buckets[i],buckets[i]+buckets[i].size(),)compare에는 번호를 못 붙이기에 사용 불가능
//        quicksort(buckets[i], 0, buckets[i].size() - 1, i);
//    }
//
//    for (int i = 9; i >= 0; i--)//정렬된 값을 뒤에서 부터 출력
//    {
//        for (int j = 0; j < buckets[i].size(); j++)
//        {
//            answer += to_string(buckets[i][j]);
//        }
//    }
//    return answer;
//}
//int main()
//{
//    
//    vector<int> temp;
//    temp.push_back(6);
//    temp.push_back(10);
//    temp.push_back(2);
//    cout<<solution(temp);
//}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
    }
    if (answer[0] == '0') return "0";
    return answer;
}