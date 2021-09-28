#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    answer = new_id;
    //step1
    for(int i=0; i<answer.size(); i++)
        answer[i] = tolower(answer[i]);
    //step2
    for (int i=0; i<answer.size(); i++){
        if (answer[i] >= 'a' && answer[i] <= 'z')
            continue;
        else if (answer[i] >= '0' && answer[i] <= '9')
            continue;
        else if (answer[i] == '-')
            continue;
        else if (answer[i] == '_')
            continue;
        else if (answer[i] == '.')
            continue;
        answer.erase(answer.begin()+i);
        i--;
    }
    //step3
    while (answer.find("..") != string::npos){
        answer.replace(answer.find(".."), 2, ".");
    }
    //step4
    if (*answer.begin() == '.')
        answer.erase(answer.begin());
    if (*(answer.end() - 1) == '.')
        answer.erase(answer.end() - 1);
    //step5
    if (answer.empty())
        answer = "a";
    //step6
    if (answer.length() >= 16)
        answer = answer.substr(0, 15);
    if (*(answer.end() - 1) == '.')
        answer.erase(answer.end() - 1);
    //step7
    if (answer.length() <= 2) {
        while(answer.length() <= 2)
            answer.push_back(*(answer.end() - 1));
    }
    return answer;
}
