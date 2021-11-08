#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*프로그래머스 2단계 해시. (실제론 해시 사용 x)*/
/*https://programmers.co.kr/learn/courses/30/lessons/42577*/

// bool comp(string a, string b) {//sort()에서 인자로 사용될 함수
// 	return a.size() < b.size();
// }
bool is_started(string starter, string full) {
	for (int i = 0; (i < starter.size()) && (i < full.size()); i++) {
		if (starter[i] != full[i])
			return false;
	}
	return true;
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
    //sort(phone_book.begin(), phone_book.end(), comp); // 마지막 인자로 함수를 넣어주면 해당 함수의 결과값을 기준으로 비교한다.
    //true면 그대로 false면 뒤바꿈

	for (int i = 0; i < phone_book.size() - 1; i++) {
		/*for (int j = i + 1; j < phone_book.size(); j++) { //이중 반복문 필요 없이 i와 i+1 인덱스만 비교하면 됨.
			if (is_started(phone_book[i], phone_book[j])) {
				return false;
			}
		}*/
		if (is_started(phone_book[i], phone_book[i + 1]))
			return false;
	}
	return true;
}