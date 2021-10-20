#include <string>
#include <vector>

using namespace std;

int absolute(int number) {
	if (number < 0)
		number = -number;
	return number;
}

int x_position(int number) {
	if (number == 0)
		return 1;
	number--;
	return number % 3;
}
int y_position(int number) {
	if (number == 0)
		return 3;
	number--;
	return number / 3;
}

int distance(int current_thumb, int number) {
	int result = 0;
	if (current_thumb == 0)
		current_thumb = 11;
	if (number == 0)
		number = 11;
	result += absolute(x_position(current_thumb) - x_position(number));
	result += absolute(y_position(current_thumb) - y_position(number));
	return result;
}

char decideLR(int number, string hand, int current_L, int current_R) {
	char ret = hand[0] + 'A' - 'a';
	if (distance(current_L, number) == distance(current_R, number))
		return ret;
	if (distance(current_L, number) > distance(current_R, number))
		return 'R';
	if (distance(current_L, number) < distance(current_R, number))
		return 'L';
}
string solution(vector<int> numbers, string hand) {
	string answer;
	int size_numbers = numbers.size();
	int current_L = 10, current_R = 12;
	int i;
	answer.reserve(1005);
	for (i = 0; i < size_numbers; i++) {
		if (numbers[i] == 0)
			numbers[i] = 11;
		if (numbers[i] % 3 == 1)
			answer.push_back('L');
		if (numbers[i] % 3 == 0)
			answer.push_back('R');
		if (numbers[i] % 3 == 2)
			answer.push_back(decideLR(numbers[i], hand, current_L, current_R));
		if (answer.back() == 'L')
			current_L = numbers[i];
		if (answer.back() == 'R')
			current_R = numbers[i];
	}
	return answer;
}