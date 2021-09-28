#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

bool cmp(const pair<int, double>& a, const pair<int, double>& b){
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int* challenge = new int[N];
    int* fail = new int[N];
    map <int, double> rate;
    
    fill_n(challenge, N, 0);
    fill_n(fail, N, 0);
    
    for (auto it = stages.begin(); it != stages.end(); it++){
        if (*it < N+1) {
            for(int i=1; i<=*it; i++)
                challenge[i - 1]++;
            fail[*it - 1]++;
        }
        else if (*it == N+1)
            for(int i=1; i<=N; i++)
                challenge[i - 1]++;     
    }

    for(int i=0; i<N; i++){
        if (challenge[i])
            rate[i] = static_cast<double>(fail[i]) / challenge[i]; 
        else
            rate[i] = 0.0;
    }
    
    vector<pair<int, double>> v(rate.begin(), rate.end());
    sort(v.begin(), v.end(), cmp);
    
    for(auto it = v.begin(); it != v.end(); it++){
        answer.push_back(it->first + 1);
    }
    
    return answer;
}
