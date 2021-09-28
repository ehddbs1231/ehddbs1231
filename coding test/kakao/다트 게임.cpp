#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> v;
    
    int i = 0;
    while (i < dartResult.length()) {
        int num = stoi(dartResult.substr(i));
        if (num < 10) i++;
        else i+=2;
        
        if (dartResult[i] == 'D') num = num * num;
        else if (dartResult[i] == 'T') num = num * num * num;
        i++;
        
        if (i == dartResult.length()) {
            v.push_back(num);
            break;
        }
        else if (dartResult[i] == '*'){
            if (!v.empty())
                v.back() *= 2;
            num *= 2;
            i++;
        }
        else if(dartResult[i] == '#'){
            num *= -1;
            i++;
        }
        v.push_back(num);    
    }
    
    for(auto it = v.begin(); it != v.end(); it++)
        answer += *it;
    
    return answer;
}
