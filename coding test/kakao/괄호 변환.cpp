#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool balance(string s) {
    if (s.length() == 0) return 1;
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') left++;
        else right++;
    }
    return left == right;
}
bool correct (string s){
    if (s.length() == 0) return 1;
    if (balance(s)){
        int left = 0;
        int right = 0;
        for (int i=0; i<s.length(); i++){
            if (s[i] == '(') left++;
            else right++;
            if (left < right) return 0;
        }
        return 1;
    }
    return 0;
}
string solution(string p) {
    string answer = "";
    //step 1
    if (correct(p)) return p;
    string u, v;
    //step 2
    for (int i=1; i<p.length(); i+=2){
        u = p.substr(0, i+1);
        if (balance(u)){
            v = p.substr(i+1);
            break;
        }
    }
    //step 3-1
    if (correct(u)) return u + solution(v);
    //step 4
    else{
        answer = "(" + solution(v) + ")";
        u = u.substr(1, u.length() - 2);
        for (int i=0; i<u.length(); i++){
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;
        return answer;
    }
}
