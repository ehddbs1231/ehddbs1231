#include <iostream>
#include <string>
#include <vector>

using namespace std;

int log_ten(int n) {
    if (n == 1)
        return 0;
    else if (n < 10)
        return 1;
    else if (n < 100)
        return 2;
    else if (n < 1000)
        return 3;
    else
        return 4;
}
int solution(string s) {
    int answer = 0;

    for (int len = 1; len <= s.length(); len++) {
        int a = 0;
        int cnt = 1;
        int p = 0;

        while (1) {
            string str = s.substr(p, len);
            p += len;
            if (p + len >= s.length()) {
                if (p + len == s.length()) {
                    if (str == s.substr(p, len))
                        cnt++;
                }

                a += len;
                a += log_ten(cnt);
                cnt = 1;

                if (str != s.substr(p, len)) {
                    a += (s.length() - p);
                }
                break;
            }
            else if (str == s.substr(p, len)) {
                cnt++;
            }
            else {
                a += len;
                a += log_ten(cnt);
                cnt = 1;
            }
        }

        if (a < answer || answer == 0)
            answer = a;
    }

    return answer;
}
