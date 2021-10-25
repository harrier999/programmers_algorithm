#include <string>
using namespace std;

string solution(int num) {
		string ret;
	char tmp;
	ret.clear();
	for (int i = 0; num > 0; i++) {
		if (num % 3 == 0){
			ret.push_back('4');
            num = num / 3 - 1;
            continue;
        }
		if (num % 3 != 0)
			ret.push_back('0' + num % 3);
		num = num / 3;
	}
	for (int i = 0; i < (ret.size() / 2); i++) {
		tmp = ret[i];
		ret[i] = ret[ret.size() - i - 1];
		ret[ret.size() - i - 1] = tmp;
	}
	return ret;
}