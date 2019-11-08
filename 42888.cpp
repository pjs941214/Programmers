#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    
    for(int i = 0; i < record.size(); i++){
        string origin = record[i];
        string type = "";
        string id = "";
        string nickname = "";
        
        int idx = origin.find(" ");
        type = origin.substr(0, idx);
        origin = origin.substr(idx + 1, origin.length() - (idx + 1));
        idx = origin.find(" ");
        id = origin.substr(0, idx);
        if(type != "Leave") nickname = origin.substr(idx + 1, origin.length() - (idx + 1));
        
        if(type == "Change") m[id] = nickname;
        else if(type == "Enter"){
            if(m.find(id) == m.end()) m.insert(make_pair(id, nickname));
            else m[id] = nickname;
        }
    }
    
    for(int i = 0; i < record.size(); i++){
        string origin = record[i];
        string type = "";
        string id = "";
        string nickname = "";
        
        int idx = origin.find(" ");
        type = origin.substr(0, idx);
        origin = origin.substr(idx + 1, origin.length() - (idx + 1));
        idx = origin.find(" ");
        id = origin.substr(0, idx);
        if(type != "Leave") nickname = origin.substr(idx + 1, origin.length() - (idx + 1));
        
        if(type == "Enter"){
            string msg = m[id] + "님이 들어왔습니다.";
            answer.push_back(msg);
        }
        else if(type == "Leave"){
            string msg = m[id] + "님이 나갔습니다.";
            answer.push_back(msg);
        }
    }
    
    return answer;
}