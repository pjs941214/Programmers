#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 9999;
    int size = s.length();
    int cnt = 1;
    
    string compress = "";
    
    if(size == 1) answer = 1;
    else{
        for(int x = size / 2; x > 0; x--){
            vector<string> v;
            vector<bool> isSelect;
        
            for(int i = 0; i < size; i = i + x){
                string token = s.substr(i, x);
                v.push_back(token);
                isSelect.push_back(false);
            }
        
            for(int i = 0; i < v.size(); i++){
                if(isSelect[i]) continue;
                isSelect[i] = true;
                
                for(int j = i + 1; j < v.size(); j++){
                    if(v[i] == v[j]) {
                        cnt++;
                        isSelect[j] = true;
                    }
                    else break;
                }
            
                if(cnt != 1) compress += (to_string(cnt) + v[i]);
                else compress += v[i];
                cnt = 1;
            }
            int length = compress.length();
            answer = min(length, answer);
            compress = "";
        }
    }
    return answer;
}