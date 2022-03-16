#include <vector>

using namespace std;

int is_prime(int n) {                       //check if 'n' is prime
	int max;
	if (n % 2 == 0)                         //minimun value of 'n' is 6 (cause it's sum of 3 different natural numbers)
		return 0;
	for (max = 1; max * max < n; max++);    // approximation of square root 
	for (int i = 3; i <= max; i = i + 2) {  // don't care about under 6
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int solution(vector<int> nums) {
	int answer = 0;
	const int SIZE = nums.size();

	for (int i = 0; i < SIZE - 2; i++) {     //nCr, combination
		for (int j = i + 1; j < SIZE - 1; j++) {
			for (int k = j + 1; k < SIZE; k++) {
				answer += is_prime(nums.at(i) + nums.at(j) + nums.at(k));
			}
		}
	}
	return answer;
}