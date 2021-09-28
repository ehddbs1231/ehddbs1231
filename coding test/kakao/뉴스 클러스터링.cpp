#include <string>
#include <algorithm>
#include <map>
using namespace std;

bool check_alp(char a) {
    return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'));
}

string capital_to_small(string s) {
    for (int i=0;i<s.length(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
    return s;
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m1, m2;
    
    for (int i=0; i<str1.length()-1; i++){
        if (check_alp(str1[i]) && check_alp(str1[i+1])) {
            string s = capital_to_small(str1.substr(i, 2));
            if (m1.find(s) == m1.end()) m1[s] = 1;
            else m1[s]++;
        }
    }
    for (int i=0; i<str2.length()-1; i++){
        if (check_alp(str2[i]) && check_alp(str2[i+1])) {
            string s = capital_to_small(str2.substr(i, 2));
            if (m2.find(s) == m2.end()) m2[s] = 1;
            else m2[s]++;
        }
    }
    
    map<string, int> m_intersec(m1), m_union(m1);
    for(auto it = m_intersec.begin(); it != m_intersec.end();){
        if (m2.find(it->first) == m2.end())
            m_intersec.erase(it++);
        else
            ++it;
    }
    
    for(auto it = m2.begin(); it != m2.end(); it++) {
        if (m_intersec.find(it->first) != m_intersec.end())
            m_intersec[it->first] = min(m_intersec[it->first], it->second);
        
        if (m_union.find(it->first) != m_union.end())
            m_union[it->first] = max(m_union[it->first], it->second);
        else
            m_union[it->first] = it->second;
    }
    
    int num_intersec = 0;
    int num_union = 0;
    
    for (auto it = m_intersec.begin(); it != m_intersec.end(); it++)
        num_intersec += it->second;
    for (auto it = m_union.begin(); it != m_union.end(); it++)
        num_union += it->second;
    
    if (num_union == 0) 
        answer = 65536;
    else
        answer = (int)(((double)num_intersec/num_union) * 65536);

    return answer;
}
