#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    vector<vector<bool>> visited;
    for(int i = 0; i < m; i++){
        vector<bool> temp;
        for(int j = 0; j < n ; j++){
            temp.push_back(false);
        }
        visited.push_back(temp);
    }
    
    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] != 0 && !visited[i][j]){
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                answer[0]++;
                
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    cnt++;
                    
                    for(int it = 0; it < 4; it++){
                        int X = x + dx[it], Y = y + dy[it];
                        
                        if(0 <= X && X < m && 0 <= Y && Y < n && picture[x][y] == picture[X][Y] && !visited[X][Y]){
                            visited[X][Y] = true;
                            q.push(make_pair(X, Y));
                        }
                    }
                }
                answer[1] = max(answer[1], cnt);
                cnt = 0;
            }
        }
    }
   
    return answer;
}