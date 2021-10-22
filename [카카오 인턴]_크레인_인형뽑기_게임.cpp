#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int pick(vector<vector<int>> &board, int col) //get the object at the top of the specific column
{
	int size = board.size();
	int i;
	int ret;

	for (i = 0; i < size; i++)
	{
		if (board[i][col] != 0) {
			ret = board[i][col];
			board[i][col] = 0;
			return ret;
		}
	}
	return 0;
}
int destroy(stack <int> &tower) {
	int top;

	if (tower.empty())
		return 0;
	top = tower.top();
	if (top == 0)
		return 0;
	tower.pop();

	if (tower.empty()) {
		tower.push(top);
		return 0;
	}
	if (top == tower.top()) {
		tower.pop();
		return 2;
	}
	tower.push(top);
	return 0;
}
int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	stack <int> tower;
	int i;
	int top;
	int picked;
	for (i = 0; i < moves.size(); i++) {
		picked = pick(board, moves[i] - 1);/*
		cout << "고른 수:"<<picked << endl;*/
		tower.push(picked);
		answer += destroy(tower);
	}
	//for (i = 0; i < 5; i++) {
	//	cout << tower.top() << endl;
	//	tower.pop();
	//}

	return answer;
}

/*  test code, answer = 4   */

//  int main(){
//      vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};

//      vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
//      cout<< solution(board, moves);

//  }