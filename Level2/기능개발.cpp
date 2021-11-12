#include <string>
#include <vector>
using namespace std;

/*프로그래머스 2단계 기능개발 스택/큐*/
/*https://programmers.co.kr/learn/courses/30/lessons/42586*/

void proceed(vector<int> &progresses, vector<int> speeds) {
	for (int i = 0; i < progresses.size(); i++)
		progresses[i] += speeds[i];
	return;
}
int last_complete(vector<int> progresses) {
	int i;
	for (i = 0; i < progresses.size(); i++)
		if (progresses[i] < 100)
			return i;
	return i;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int completed = 0;
	while (last_complete(progresses) < progresses.size()) {
		proceed(progresses, speeds);
		if (last_complete(progresses) != completed) {
			answer.push_back(last_complete(progresses) - completed);
			completed = last_complete(progresses);
		}
	}
	return answer;
}