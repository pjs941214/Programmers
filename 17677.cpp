#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2){
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

	int answer = 0;
	long long j = 0;

	vector<pair<string, bool> > A, B;
	for (int i = 0; i < str1.length() - 1; i++) {
		string str = str1.substr(i, 2);
		int ascii1 = int(str[0]), ascii2 = int(str[1]);
		if (65 <= ascii1 && ascii1 <= 90 && 65 <= ascii2 && ascii2 <= 90) A.push_back(make_pair(str, false));
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		string str = str2.substr(i, 2);
		int ascii1 = int(str[0]), ascii2 = int(str[1]);
		if (65 <= ascii1 && ascii1 <= 90 && 65 <= ascii2 && ascii2 <= 90) B.push_back(make_pair(str, false));
	}

	int intersection = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i].second) continue;
		for (int j = 0; j < B.size(); j++) {
			if (A[i].first == B[j].first && !A[i].second && !B[j].second) {
				intersection++;
				A[i].second = true;
				B[j].second = true;
				break;
			}
		}
	}
    
    if(A.size() != intersection && B.size() != intersection) j = (intersection * 65536) / (A.size() + B.size() - intersection);
    else if(A.size() == B.size() && B.size() == intersection) j = 65536;
    else if(intersection == 0) j = 0;
    else if(A.size() == intersection || B.size() == intersection) j = (intersection * 65536) / (A.size() + B.size() - intersection);
	answer = int(j);

	return answer;
}