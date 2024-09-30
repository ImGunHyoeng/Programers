//���� �ۼ��� �ڵ�
//#include <string>
//#include <vector>
//#include <map>
//#include <sstream>
//#include <iostream>
//
//using namespace std;
//
//struct Record
//{
//    string name;
//    string purpose;
//    int sequencenum;
//};
//vector<string> solution(vector<string> record) {
//    vector<string> answer;
//
//    map<string, vector<Record>> useridmap;
//    vector<pair<string, string>> change;
//    int count = 0;
//    for (auto it = record.begin(); it != record.end(); it++)
//    {
//        string id = "";
//        string purpose = "";
//        string name = "";
//        string temp = "";
//
//        istringstream iss(*it);
//        iss >> purpose >> id >> name;
//        //getline(it,purpose,' ');
//        //getline(it,id,' ');
//        //getline(it,name,' ');
//
//
//        useridmap[id].push_back(Record{ name,purpose,count });
//
//        if (purpose.compare("Change") == 0)//0�� �����̶�� ���� �򰥸�
//        {
//            change.push_back(make_pair(id, name));
//            count--;
//        }
//        if (purpose.compare("Enter") == 0)
//        {
//            if ((useridmap[id][0].name.compare(name)) != 0)
//                change.push_back(make_pair(id, name));
//            //count;
//        }
//
//        count++;
//    }
//
//    answer.resize(count);
//    for (auto it = change.begin(); it != change.end(); it++)
//    {
//        for (int i = 0; i < useridmap[it->first].size(); i++)
//            useridmap[it->first][i].name = it->second;
//        //name,id
//    }//�� ����
//
//    int j = 0;
//    for (auto it = useridmap.begin(); it != useridmap.end(); it++)
//    {
//        if (j >= count)
//            break;
//        const std::vector<Record>& records = it->second; // ���� pair�� value(vector)�� ����
//
//        for (const Record& record : records)
//        {
//            string temp;
//
//            if (record.purpose == "Enter") { // ���ڿ� �񱳴� == ������ ���
//                temp += "���Խ��ϴ�.";
//            }
//            else if (record.purpose == "Leave") {
//                temp += "�������ϴ�.";
//            }
//            else {
//                continue;
//            }
//            answer[record.sequencenum] = string(record.name + "���� " + temp);
//        }
//        j++;
//    }
//
//    return answer;
//}

//����ڵ�
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> action;
    vector<string> id;
    map<string, string> name;

    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string temp;
        if (ss >> temp) action.push_back(temp);
        if (ss >> temp) id.push_back(temp);
        if (ss >> temp) {
            name[id.back()] = temp;
        }
    }
    for (int k = 0; k < action.size(); k++) {
        string temp = name[id[k]];
        if (action[k] == "Enter") temp += "���� ���Խ��ϴ�.";
        else if (action[k] == "Leave") temp += "���� �������ϴ�.";
        else if (action[k] == "Change") continue;
        answer.push_back(temp);

    }

    return answer;
}