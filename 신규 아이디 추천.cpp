#include <string>	
#include <iostream>
#include <vector>

using namespace std;
/*프로그래머스 1단계 [2021 KAKAO BLIND RECRUITMENT] 단순구현*/
/*40라인 이하로 줄일것*/
/*https://programmers.co.kr/learn/courses/30/lessons/72410*/

vector<char> string_to_vec(string str) {// 사용하지 말 것
	vector<char> vec_str(str.begin(), str.end());
	return vec_str;
}
string vec_to_string(vector<char> vec) { //사용하지 말 것
	string str = "";
	for (int i = 0; i < vec.size(); i++) {
		str.push_back(vec[i]);
	}
	return str;
}
vector<char> step1(vector<char> str) { //str에 바로 집어넣기
	vector<char> ret;
	for (int i = 0; i < str.size(); i++) {
		ret.push_back(str[i]);
		if ('A' <= ret[i] && ret[i] <= 'Z')
			ret[i] = ret[i] - 'A' + 'a';
	}
	return ret;
}

vector<char> step2(vector<char> str) { // -._ 부분 더 빠르게도 가능하나 충분
	vector<char> ret;
	for (int i = 0; i < str.size(); i++) {
		if ('a' <= str[i] && str[i] <= 'z' || str[i] == '-' || str[i] == '.' || str[i] == '_' || (str[i] <= '9' && str[i] >= '0'))
			ret.push_back(str[i]);
	}
	return ret;
}
vector<char> step3plus_4(vector<char> str) {// 훨씬 빠르게 가능.
	vector<char> ret;
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.')
			count++;
		if (str[i] != '.') {
			if (count > 1) {
				for (int k = 0; k < count - 1; k++)
					ret.pop_back();
			}
			count = 0;
		}
		ret.push_back(str[i]);
	}
	if (ret.front() == '.' && ret.size() > 1) {
		vector<char> tmp(ret.begin() + 1, ret.end());
		ret.clear();
		ret = tmp;
	}
	while (true) {
		if (!ret.empty() && ret.back() == '.')
			ret.pop_back();
		else
			break;
	}
	return ret;
}
vector<char> step5(vector<char> str) {
	vector<char> ret;
	if (str.empty()) {
		str.push_back('a');
		return str;
	}
	return str;
}
vector<char> step6(vector<char> str) {//substr 함수 사용하면 빠르게 가능
	vector<char> ret;
	if (str.size() > 15) {
		for (int i = 0; i < 15; i++) {
			ret.push_back(str[i]);
		}
		if (ret.back() == '.')
			ret.pop_back();
		return ret;
	}
	return str;
}
vector<char> step7(vector<char> str) {
	while (str.size() < 3) {
		str.push_back(str.back());
	}
	return str;
}




string solution(string new_id) {


	vector<char> str = string_to_vec(new_id);
	str = step1(str);
	str = step2(str);
	str = step3plus_4(str);
	str = step5(str);
	str = step6(str);
	str = step7(str);
	return vec_to_string(str);

}

int main() {
	cout << solution("A.0123456789..A");
}