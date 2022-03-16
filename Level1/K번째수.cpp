#include <vector>
#include <algorithm>

/*https://programmers.co.kr/learn/courses/30/lessons/42748*/
/*프로그래머스 1단계 정렬*/

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp; // Array will be copied to here for maintaining original
    for (int i =0;i<commands.size();i++){
        tmp.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]); //Copy subset of array
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp.at(commands[i][2] - 1));
    }
    return answer;
}