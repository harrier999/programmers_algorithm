#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*프로그래머스 1단계 해시*/
/*https://programmers.co.kr/learn/courses/30/lessons/42576*/
/*find()와 erase()로 구현하였으나 시간초과. */
/*해시로도 구현 가능하니 sort를 이용하면 훨씬 편하다*/
/*
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	auto target = find(participant.begin(), participant.end(), completion.back());
	int dist;
	int SIZE = completion.size();
	for (int i = 0; i < SIZE; i++) {
		target = find(participant.begin(), participant.end(), completion.back());
		dist = distance(target, participant.begin());
		participant[dist] = "";
		//completion.pop_back();
		//participant.erase(target);
		//for (int j = 0; j < completion.size(); j++) {
		//	cout << completion[j];
		//}
		//cout << endl;
	}
	for (int i = 0; i < SIZE; i++) {
		if (participant[i] != "")
			return participant[i];
	}
	return "hello";
}
*/
string solution(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < completion.size(); i++) {
		if (completion[i] != participant[i])
			return participant[i];
	}
	return participant.back();
}

// int main() {
// 	cout<<solution({ "leo", "kiki", "eden" }, { "leo", "kiki" });
// 	cout<<"hello";
// 	system("pause");
// }