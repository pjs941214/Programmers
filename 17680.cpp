#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int size = cities.size();
    queue<string> cache;
    queue<string> tc; // temp cache
    
    for(int i = 0; i < size; i++){
        
        // Transform low to up
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
        
        // Find
        string compare;
        bool flag = false;
        while(!cache.empty()){
            string str = cache.front();
            cache.pop();
            
            if(cities[i] == str) {
                compare = str;
                flag = true;
            }
            else tc.push(str);
        }
        
        if(flag){
            answer++;
            tc.push(compare);
        }
        else{
            answer += 5;
            tc.push(cities[i]);
        }
        
        int cs = 0;
        while(!tc.empty()){
                cs++;
                cache.push(tc.front());
                tc.pop();
        }
        
        if(cs > cacheSize){
            for(int j = 0; j < cs - cacheSize; j++){
                cache.pop();
            }
        }
        
    }
    
    return answer;
}