#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> nickname;
    
    for (vector<string>::iterator it = record.begin(); it < record.end(); it++){
        vector<string> result = split(*it, ' ');
        if (result[0] == "Enter"){
            nickname[result[1]] = result[2];
            answer.push_back(result[1] + " 님이 들어왔습니다.");
        }
        else if (result[0] == "Leave"){
            answer.push_back(result[1] + " 님이 나갔습니다.");
        }
        else if (result[0] == "Change"){
            nickname[result[1]] = result[2];
        }
    }

    vector<string>::iterator ite = answer.begin();
    while (ite != answer.end()){
        vector<string> a = split(*ite, ' ');
        *ite = nickname[a[0]] + "님이 " + a[2];
        ite++;
    }

    return answer;
}
