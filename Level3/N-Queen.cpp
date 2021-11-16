#include <string>
#include <vector>

using namespace std;


int answer = 0;

bool is_possible(vector<int> &map, int depth, const int n, int x){
    for (int i=0; i<depth; i++){
        if (map[i] == x)
            return false;
        if ((map[i] - depth) == x)
    }
    return true;
}

int set_queen(vector<int> &map, int depth, const int n, int x){
    int result = 0;

    if (depth == n)
        return answer++;
    else{
        
    }
    for (int x=0; x<n; x++){
        if (is_possible(map, depth, n + 1, x)){
            set_queen(map, depth + 1, n, x);
        }
    }
    
}

int solution(int n) {
    int answer = 0;
    vector<int> map(n, -1);
    int depth = 0;



    return answer;
}