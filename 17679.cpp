#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int> > q;
vector<vector<char>> arr;

void cal(int m, int n){
    bool flag = false;
    for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(arr[i][j] != '0' && (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i + 1][j + 1] && arr[i + 1][j + 1] == arr[i +1][j])){
                flag = true;
                q.push(make_pair(i,j));
                q.push(make_pair(i,j + 1));
                q.push(make_pair(i + 1,j));
                q.push(make_pair(i + 1,j + 1));
            }
        }
    }
    
    if(!flag) return; 
    
    while(!q.empty()){
        arr[q.front().first][q.front().second] = '0';
        q.pop();
    }
    
    for(int i = m - 2; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(arr[i][j] != '0'){
                int idx = i;
                for(int idx = i; idx < m - 1; idx++){
                    if(arr[idx + 1][j] == '0'){
                        swap(arr[idx][j], arr[idx+1][j]);
                    }
                }
            }
        }
    }
    cal(m,n);
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    for(int i = 0; i < m; i++){
        vector<char> temp;
        for(int j = 0; j < n; j++){
            temp.push_back(board[i][j]);
        }
        arr.push_back(temp);
    }
    cal(m,n);
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == '0') answer++;
        }
    }
    
    return answer;
}