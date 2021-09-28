#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
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

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> timelist;
    
    // 문자열로 표현된 시간 숫자로 변환
    for(auto it = timetable.begin(); it != timetable.end(); it++){
        vector<string> x = split(*it, ':');
        int hour, minute;
        hour = stoi(x[0]); minute = stoi(x[1]);
        timelist.push_back(hour*60 + minute);
    }
    sort(timelist.begin(), timelist.end());
    
    // 버스 막차보다 늦게 오는 사람 삭제 (ex) 23:59)
    for(auto it = timelist.begin(); it != timelist.end(); it++){
        if (*it > 540 + (n-1)*t){
            timelist.erase(it, timelist.end());
            break;
        }
    }
    
    int max_people = n * m;
    int answer_time = 0;
    int cnt = 0;
    int bus;
    
    // 버스가 출발할때 빈 좌석의 수
    int empty = 0;
    
    for(bus=540; bus<540+n*t; bus+=t){
        
        // 모든 사람이 다 타고 남은 자리가 있을 때 막차를 탐
        if (cnt >= timelist.size()){           
            answer_time = 540 + (n-1)*t;
            goto EXIT;
        }
        int people = 0;
        while(people < m && cnt < timelist.size()){
            if(timelist[cnt] <= bus){
                cnt++;
                people++;
            }
            else{
                empty += m - people; 
                break;
            }
            
            if(cnt >= max_people - 1 - empty){
                answer_time = bus;

                if (cnt < timelist.size())
                    answer_time = timelist[cnt] - 1;
                    
                if (people == m)
                    answer_time = timelist[cnt - 1] - 1;
                goto EXIT;
            }
        }

    }
    
EXIT:
   
    int hour = answer_time/60, minute = answer_time%60;
    if (hour < 10) answer += "0";
    answer += to_string(hour) + ":";
    if (minute < 10) answer += "0";
    answer += to_string(minute);
    return answer;
}
