#include <string>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;
string my_itoa(long num) { //use to_string instead
	string str = "";
	string tmp_str = "";
	int sign = 1;
	if (num < 0)
		sign = -1;
	while (num != 0) {
		tmp_str.clear();
		tmp_str.push_back((num % 10) * sign + '0');
		num = num / 10;
		str = tmp_str + str;
	}
	if (sign < 0)
		str = "-" + str;
	return str;
}


string solution(string s) {
	string answer = "";
	string tmp_str = "";
	vector<int> numbers;
	const size_t SIZE = s.size();
	int sign = 1;

	for (int i = 0; i < SIZE + 1; i++) {
		if (s[i] == '-')
			sign = -1;
		if ('0' <= s[i] && s[i] <= '9') {
			tmp_str = tmp_str + s[i];
		}
		if (s[i] == ' ' || s[i] == '\0') {
			numbers.push_back(atoi(tmp_str.c_str()) * sign);
			tmp_str.clear();
			sign = 1;
		}

	}

	sort(numbers.begin(), numbers.end());
	char tmp[10000];
	answer = answer + my_itoa(numbers.front());
	answer = answer + " ";
	answer = answer + my_itoa(numbers.back());

	return answer;
}

// int main()
// {
// 	printf("%s", solution("-1 -1").c_str());
// }