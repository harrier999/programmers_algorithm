#include <string>
#include <vector>

using namespace std;


/*https://programmers.co.kr/learn/courses/30/lessons/12945#*/
int solution(int n) {
    int prev = 0;
    int curr = 1;
    int tmp;
    for(int i = 1; i<n; i++){
        tmp = (curr)%1234567;
        curr = (prev + curr)%1234567;
        prev = (tmp)%1234567;
    }
    return curr%1234567;
}