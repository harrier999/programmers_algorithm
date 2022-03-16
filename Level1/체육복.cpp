#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> students(n, 1);
	int a = 0;
	int b = 0;

	for (int i = 0; i < lost.size(); i++) {
		students[lost.at(i) - 1]--;
	}
	for (int i = 0; i < reserve.size(); i++) {
		students[reserve.at(i) - 1]++;
	}
	for (int i = 0; i < students.size(); i++) {
		if (students.at(i) < 1) {
			if (((i - 1) >= 0) && (students.at(i - 1) > 1)) {
				students[i]++;
				students[i - 1]--;
			}
			else if (((i + 1) < students.size()) && (students.at(i + 1) > 1)) {
				students[i]++;
				students[i + 1]--;
			}
		}
	}
	for (int i = 0; i < students.size(); i++) {
		if (students.at(i) > 0) {
			answer++;
		}
	}
	return answer;
}

// #include<iostream>
// int main() {
// 	cout<< solution(12, { 1, 2, 3, 4, 8, 9, 10, 12}, { 1 });

// }