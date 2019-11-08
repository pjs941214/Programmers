#include <bits/stdc++.h>
using namespace std;

vector<int> answer;
map<string, int> m;
int value = 27;

void cal(string msg){
    if(msg == "") return;
    
    int idx = 1, output;
    for(;;){
        if(idx > msg.length()) break;
        string s = msg.substr(0, idx);
        if(m.find(s) == m.end()){
            m.insert(make_pair(s, value++));
            break;
        }
        else {
            idx++;
            output = m[s];
        }
    }
    answer.push_back(output);
    idx--;
    msg = msg.substr(idx, msg.length() - idx);
    cal(msg);    
}

vector<int> solution(string msg) {
    // 65 ~ 90
    for(int i = 1; i <= 26; i++){
        char num = 64 + i;
        string key(1, num);
        m.insert(make_pair(key, i));
    }
    
    cal(msg);
    
    
    return answer;
}