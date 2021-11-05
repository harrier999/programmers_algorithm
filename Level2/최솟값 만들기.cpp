#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 프로그래머스 2단계 연습문제*/
/*https://programmers.co.kr/learn/courses/30/lessons/12941*/
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for(int i =0; i<A.size(); i++){
        answer+= A.at(i) * B.at(i);
    }
    return answer;
}