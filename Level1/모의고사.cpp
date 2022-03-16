#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*프로그래머스 1단계 완전탐색*/
/*https://programmers.co.kr/learn/courses/30/lessons/42840*/

vector<int> solution(vector<int> answers) {
	vector<int> a1 = { 1, 2, 3, 4, 5 };
	vector<int> a2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> a3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	vector<int> correct(3, 0);

	for (int i = 0; i < answers.size(); i++) {
		if (answers.at(i) == a1.at(i % 5))
			correct.at(0)++;
		if (answers.at(i) == a2.at(i % 8))
			correct.at(1)++;
		if (answers.at(i) == a3.at(i % 10))
			correct.at(2)++;
	}
	vector<int> answer;
	vector<int> origin = correct;
	sort(correct.begin(), correct.end());
	if (correct.at(2) == origin.at(0))
		answer.push_back(1);
	if (correct.at(2) == origin.at(1))
		answer.push_back(2);
	if (correct.at(2) == origin.at(2))
		answer.push_back(3);
	return answer;
}

// int main()
// {
// 	vector<int> aa;
// 	aa = solution({1, 2, 3, 4, 5});
// 	for (int i = 0; i < aa.size(); i++) {
// 		cout << aa.at(i);
// 	}
// }