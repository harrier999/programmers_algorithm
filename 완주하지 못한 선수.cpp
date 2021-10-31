#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	auto target = find(participant.begin(), participant.end(), completion.back());
	int SIZE = completion.size();
	for (int i = 0; i < SIZE; i++) {
		target = find(participant.begin(), participant.end(), completion.back());
		completion.pop_back();
		participant.erase(target);
		//for (int j = 0; j < completion.size(); j++) {
		//	cout << completion[j];
		//}
		//cout << endl;
	}
	return participant[0];
}

int main() {
	cout<<solution({ "leo", "kiki", "eden" }, { "leo", "kiki" });
}