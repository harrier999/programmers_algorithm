#include <string>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

/*https://programmers.co.kr/learn/courses/30/lessons/42898*/
/*프로그래머스 고득점 kit 동적계획법 level3*/
void print_vector(vector<vector<int>> map) { //for testing only
	const int n = map.size();
	const int m = map.front().size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return;
}
int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int tmp;
	vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));  //initialize to n+1 by m+1 vector. 
                                                            //this vector has margin to avoid reference -1th element of vector.
	map[0][1] = 1; //by setting an marginal element 1, [1][1] element is set to 1. cause of adding upper element and left element
	for (int i = 0; i < puddles.size(); i++)    //set puddles to map
		map[puddles[i][1]][puddles[i][0]] = -1;
	//print_vector(map);
	//cout << "------------ -" << endl;
	//return 1;
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			tmp = map[j][i];
			//cout << "tmp:" << tmp << endl;;
			map[j][i] = (map[j][i - 1] + map[j - 1][i]) % 1000000007; //current element = upper element + left element
			if (tmp == -1)
				map[j][i] = 0; //if it is puddle, set 0
			//print_vector(map);
			//cout << endl;
		}
	}
	//print_vector(map);
	return map[n][m];
}

int main() {
	int m = 4;
	int n = 3;
	vector<vector<int>> puddles;
	vector<int> tmp;
	tmp.push_back(2);
	tmp.push_back(2);
	puddles.push_back(tmp);
	puddles.push_back(tmp);
	print_vector(puddles);
	cout<< solution(m, n, puddles);
}