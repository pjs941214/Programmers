#include <bits/stdc++.h>
using namespace std;

string transform(int n, int num){
    string t = "";
    if(n < 10){
        for(;;){
            if(num / n == 0){
                t += to_string(num);
                break;
            }
            int mod = num % n;
            t += to_string(mod);
            num /= n;
        }
    }
    else{
        for(;;){
            if(num / n == 0){
                string str16 = "";
                if(num == 0) str16 = to_string(0);
                else if(num == 1) str16 = to_string(1);
                else if(num == 2) str16 = to_string(2);
                else if(num == 3) str16 = to_string(3);
                else if(num == 4) str16 = to_string(4);
                else if(num == 5) str16 = to_string(5);
                else if(num == 6) str16 = to_string(6);
                else if(num == 7) str16 = to_string(7);
                else if(num == 8) str16 = to_string(8);
                else if(num == 9) str16 = to_string(9);
                else if(num == 10) str16 = string(1, 'A');
                else if(num == 11) str16 = string(1, 'B');
                else if(num == 12) str16 = string(1, 'C');
                else if(num == 13) str16 = string(1, 'D');
                else if(num == 14) str16 = string(1, 'E');
                else if(num == 15) str16 = string(1, 'F');
                t += str16;
                break;
            }
            int mod = num % n;
            string str16;
            if(mod == 0) str16 = to_string(0);
            else if(mod == 1) str16 = to_string(1);
            else if(mod == 2) str16 = to_string(2);
            else if(mod == 3) str16 = to_string(3);
            else if(mod == 4) str16 = to_string(4);
            else if(mod == 5) str16 = to_string(5);
            else if(mod == 6) str16 = to_string(6);
            else if(mod == 7) str16 = to_string(7);
            else if(mod == 8) str16 = to_string(8);
            else if(mod == 9) str16 = to_string(9);
            else if(mod == 10) str16 = string(1, 'A');
            else if(mod == 11) str16 = string(1, 'B');
            else if(mod == 12) str16 = string(1, 'C');
            else if(mod == 13) str16 = string(1, 'D');
            else if(mod == 14) str16 = string(1, 'E');
            else if(mod == 15) str16 = string(1, 'F');
            t += str16;
            num /= n;
        }
    }
    reverse(t.begin(), t.end());
    return t;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";
    
    int num = 0;
    for(;;){
        temp += transform(n, num);    
        num++;
        if(temp.length() >= t * m) break;
    }
    
    for(int i = p - 1; i < temp.length(); i = i + m){
        answer += string(1, temp[i]);
        if(answer.length() == t) break;
    }
    
    return answer;
}