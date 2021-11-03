#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*프로그래머스 2단계 정렬*/
/*https://programmers.co.kr/learn/courses/30/lessons/42747*/
int solution(vector<int> citations) {
    int answer = 0;
    int i;
    sort(citations.begin(), citations.end(), greater<int>());
    for (i = 0; i<citations.size(); i++){
        if (citations.at(i) < i + 1)
            return i;
    }
    return i;
}