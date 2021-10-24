#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int is_possible(long long time, int n, vector<int> times) {
	long long i, num = 0;
	for (i = 0; i < times.size(); i++) {
		num += time / times.at(i);
	}
	if (num < n)
		return 0;
	if (n <= num)
		return 1;
}

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());
	long long max = (long long)times.at(0) * (long long)n;
	long long min = 0;
	long long mid = max / 2;	

	while (max > min) {
		if (is_possible(mid, n, times)) {
			max = mid;
			mid = (max + min) / 2;
		}
		if (!is_possible(mid, n, times)) {
			min = mid + 1;
			mid = (max + min) / 2;
		}
	}
	return mid;
}

 int main(){
	 vector<int> times = { 7, 10 };
	 int n = 6;
	 cout << solution(n, times);

 }




/*
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

 */