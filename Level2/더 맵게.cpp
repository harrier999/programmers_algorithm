#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


int solution(vector<int> scoville, int K) {
	int answer = 0;
	vector<long> foods;
	foods.assign(scoville.begin(), scoville.end());
	for (int i = 0; i < foods.size(); i++) {
		//cout << foods.at(i)<<endl;
	}
	sort(foods.begin(), foods.end(), greater<long>());
	long new_food;
	//cout << "size: " << foods.size() << endl;
	//cout << "back: " << foods.back() << endl;
	while (foods.size() > 1 && foods.back() < K) {
		sort(foods.begin(), foods.end(), greater<long>());
		new_food = foods.back();
		foods.pop_back();
		new_food += 2 * foods.back();
		foods.pop_back();
		foods.push_back(new_food);
		answer++;

	}
	if (foods.back() < K)
		return -1;
	return answer + 2;
}