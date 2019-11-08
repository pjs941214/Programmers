#include <bits/stdc++.h>

using namespace std;

typedef struct Stage{
    int stage;
    int clear = 0;
    int total = 0;
    float fail;
}Stage;

bool comp(Stage a, Stage b){
    if(a.fail == b.fail) return a.stage < b.stage;
    else return a.fail > b.fail;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<Stage> st;
    Stage dummy;
    st.push_back(dummy);
    
    for(int i = 1; i <= N; i++){
        Stage s; s.stage = i;
        st.push_back(s);
    }
    
    for(int i = 0; i < stages.size(); i++){
        // N : 5, stages[i] : 6
        if(stages[i] > N){
            for(int j = 1; j <= N; j++){
                st[j].clear++; st[j].total++;
            }
        }
        // N : 5, stages[i] : 3
        else{
            for(int j = 1; j <= stages[i]; j++){
                st[j].clear++; st[j].total++;
            }
            st[stages[i]].clear--;
        }
    }
    
    // erase dummy data
    st.erase(st.begin());
    for(int i = 0; i < N; i++){
        if(st[i].total == 0) st[i].fail = 0;
        else st[i].fail = float(st[i].total - st[i].clear) / float(st[i].total);
    }
    
    sort(st.begin(), st.end(), comp);
    
    for(int i = 0; i < N; i++){
        answer.push_back(st[i].stage);
    }
    
    return answer;
}