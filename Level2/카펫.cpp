#include <string>
#include <vector>

using namespace std;
/*프로그래머스 2단계 완전탐색*/
/*https://programmers.co.kr/learn/courses/30/lessons/42842*/

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    const int AREA = brown + yellow; 
    for (int y = 3; y< 2500; y++){
        for (int x = y; x<2500; x++){
            if (x * y == AREA){
                if ( 2*x + 2*y == brown + 4)
                    return {x, y};
            }
        }
    }
    return answer;
}