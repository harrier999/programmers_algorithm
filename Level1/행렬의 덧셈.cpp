#include <string>
#include <vector>

using namespace std;


/*https://programmers.co.kr/learn/courses/30/lessons/12950*/

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size(), 0));
    for(int row=0; row<arr1.size(); row++){
        for (int col=0; col<arr1[0].size(); col++){
            answer[row][col] = arr1[row][col] + arr2[row][col];
        }
    }
    return answer;
}