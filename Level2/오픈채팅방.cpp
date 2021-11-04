#include <string>
#include <vector>
#include <map>
#include <iostream>
#include<cstring>

using namespace std;

// 2019 KAKAO BLIND RECRUITMENT
// https://programmers.co.kr/learn/courses/30/lessons/42888
//string stream을 이용하면 게 띄어쓰기를 제거할 수 있다.
void tokenize(string str, map<string, string> &uid_name, vector<pair<string, string>> &tmp) {
	char* c_string = (char*) str.c_str();
	char* instruction;
	char* uid;
	char* name;

	instruction = strtok(c_string, " ");
	uid = strtok(NULL, " ");
	name = strtok(NULL, " ");
	if (!strcmp("Enter", instruction)) {
		tmp.push_back({ uid, "님이 들어왔습니다." });
		uid_name[uid] = name;
	}
	else if (!strcmp("Leave", instruction)) {
		tmp.push_back({ uid, "님이 나갔습니다." });
	}
	else if (!strcmp("Change", instruction)) {
		uid_name[uid] = name;
	}
	return;
}
vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> uid_name;
	vector<pair<string, string>> tmp;
	string ans;
	cout << record.size() << endl;
	for (int i = 0; i < record.size(); i++) {
		tokenize(record[i], uid_name, tmp);
	}
	for (int i = 0; i < tmp.size(); i++) {
		ans = uid_name[tmp.at(i).first] + tmp.at(i).second;
		answer.push_back(ans);
	}
	return answer;
}