#include <string>
#include <vector>

using namespace std;


int is_included(vector<int> lottos, int win_num){
    int i;
    int win = 0;

    for(i=0;i<6;i++){
        if (lottos.at(i) == win_num)
            win++;
    }
    return win;
}

int nuumber_of_zero(vector<int> lottos){
    return is_included(lottos, 0);
}


int number_of_coincide(vector<int> lottos, vector<int> win_nums){
    int i;
    int win = 0;

    for(i=0;i<6;i++){
        if (is_included(lottos, win_nums.at(i)))
            win++;
    }
    return win;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int max, min;

    min = number_of_coincide(lottos, win_nums);
    max = min + nuumber_of_zero(lottos);

    if (max < 2)
        max = 1;
    if (min < 2)
        min = 1;

    answer.push_back(7-max);
    answer.push_back(7-min);
    return answer;
}
