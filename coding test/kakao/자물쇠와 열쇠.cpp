#include <string>
#include <vector>
#include <iostream>
using namespace std;

void clock_rotate(vector<vector<int>> &key){
    int n = key.size();
    vector<vector<int>> tmp(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            tmp[i][j] = key[n-j-1][i];
    }
    key = tmp;
}

bool open(vector<vector<int>> key, vector<vector<int>> lock, vector<vector<int>> board){   
    for(int i=0; i<lock.size() + key.size() - 1; i++){
        for (int j=0; j<lock.size() + key.size() - 1; j++){

            //board 초기화
            for (int k=0; k<lock.size(); k++){
                for(int l=0; l<lock.size(); l++)
                    board[key.size()-1+k][key.size()-1+l] = lock[k][l];
            }   
            //key 더하기
            for(int k=0; k<key.size(); k++){
                for(int l=0; l<key.size(); l++)
                    board[i+k][j+l] += key[k][l];
            }
            
            // check
            bool check = true;
            for(int k=0; k<lock.size(); k++){
                for(int l=0; l<lock.size(); l++){
                    if(board[key.size()-1+k][key.size()-1+l] != 1){
                        check = false;
                        break;
                    }
                }
                if(!check)
                    break;
            }
            if (check)
                return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int boardsize = lock.size() + 2 * (key.size() - 1);
    vector<vector<int>> board(boardsize);
    for (int i=0; i<boardsize; i++)
        board[i].assign(boardsize, 0);
    
    for (int i=0; i<4; i++){
        if (open(key, lock, board))
            return true;
        clock_rotate(key);
        
    }

    return answer;
}
