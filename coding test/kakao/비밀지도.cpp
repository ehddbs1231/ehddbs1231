#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<n; i++){
        int a = arr1[i] | arr2[i];
        string s = ""; 
        for(int j=0; j<n; j++){
            if (a & 1) s += "#";
            else s += " ";
            a >>= 1;
        }
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }
    return answer;
}
