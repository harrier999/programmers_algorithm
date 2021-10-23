#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	const int size = times.size();
	vector<long long> total_time;
	int i, j, min = 0;
	total_time.clear();

	total_time.assign(times.begin(), times.end());

	for (i = 0; i < n; i++) {
		for (j = 0; j < size; j++) {
			if (total_time[j] < total_time[min]) {
				min = j;
			}
		}
		total_time[min] += times[min];

	}
	for (i = 0; i < size; i++) {
		total_time[i] -= times.at(i);
	}
	long long max = 0;
	for (i = 0; i < total_time.size(); i++) {
		if (max < total_time.at(i)) {
			max = total_time.at(i);
		}
	}
	answer = max;
	return answer;
}

 int main(){
	 vector<int> times = { 7, 10 };
	 int n = 60000000;
	 cout << solution(n, times);

 }