#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;



/*프로그래머스 3단계 연습문제  N-Queen*/
/*https://programmers.co.kr/learn/courses/30/lessons/12952*/
int answer = 0; 

bool is_possible(vector<int> map, int depth, const int n, int x) //
{
    for (int i = 0; i < depth; i++)
    {
        if (map[i] == x || depth - i == abs(x - map[i]))
            return false;
    }
    return true;
}

void set_queen(vector<int> map, int depth, const int n, int x)
{
    map[depth] = x;
    if (depth == n - 1)
    {
        answer = answer + 1;
        return;
    }

    for (int x = 0; x < n; x++)
    {
        if (is_possible(map, depth + 1, n, x)) 
        {
            set_queen(map, depth + 1, n, x);
        }
    }
}

int solution(int n)
{
    vector<int> map(n + 1, -1);
    for (int i=0; i<n; i++){
        set_queen(map, 0, n, i);
    }
    return answer;
}
int main()
{
    solution(4);
}