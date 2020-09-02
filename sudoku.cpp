#include "sudoku.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

Sudoku::Sudoku() {};

int Sudoku::Ans = 0;
vector < int > Sudoku::ans(81);

Sudoku::Sudoku(vector<int> ques, int A) {
    map = ques;
    for (int i = 0; i<81; i++) {
        count[i] = 0;
    }
    for (int i = 0; i<81; i++) {
        for (int j=0; j<9; j++) {
            exist[i][j] = false;
        }
    }
    found = 0;
    zero = 0;
    setAns(A);
    solve();
}
void Sudoku::validator() {
    int check;
    for (int i=0; i<81; i++) {
        if (map.at(i) != 0) {
            found++;
        } else {
            for (int j=0; j<9; j++) {
                if (map.at((i/9)*9+j) != 0 && !exist[i][map.at((i/9)*9+j)-1]) {
                    count[i]++;
                    exist[i][map.at((i/9)*9+j)-1] = true;
                }
                if (map.at(j*9+i%9) != 0 && !exist[i][map.at(j*9+i%9)-1]) {
                    count[i]++;
                    exist[i][map.at(j*9+i%9)-1] = true;
                }
                check = map.at(((i/(9*3))*3+j/3)*9 + ((i%9)/3)*3+j%3) - 1;
                if (map.at(((i/(9*3))*3+j/3)*9 + ((i%9)/3)*3+j%3) != 0 && !exist[i][check]) {
                    count[i]++;
                    exist[i][check] = true;
                }
            }
            zero ++;
        }
    }
}
void Sudoku::fill() {
    int check;
    for (int i=0; i<81; i++) {
        if (map.at(i) == 0 && count[i]==8) {
            count[i] = 0;
            found++;
            for (int j=0; j<9; j++) {
                if(!exist[i][j]) {
                    map.at(i) = j+1;
                    for (int k=0; k<9; k++) {
                        if (map.at((i/9)*9+k) == 0 && !exist[(i/9)*9+k][j]) {
                            count[(i/9)*9+k]++;
                            exist[(i/9)*9+k][j] = true;
                        }
                        if (map.at(k*9+i%9) == 0 && !exist[k*9+i%9][j]) {
                            count[k*9+i%9]++;
                            exist[k*9+i%9][j] = true;
                        }
                        check = ((i/(9*3))*3+k/3)*9 + ((i%9)/3)*3+k%3;
                        if (map.at(check) == 0 && !exist[check][j]) {
                            count[check]++;
                            exist[check][j] = true;
                        }
                    }
                }
            }
            i = -1;
        }
    }
}
void Sudoku::solve() {
    int max, zeroNeed;
    validator();
    if (zero > 66) {
        count[0] = 8;
        cout<<"2"<<endl;
        exit(0);
    }
    fill();
    if (found == 81) {
        setAns(Ans+1);
        if(Ans == 1) {
            for(int i = 0; i < 81; i++) {
                ans.push_back(i);
            }
            for (int i=0; i<81; i++)
                ans.at(i) = map.at(i);
        }
    } else {
        max = 0;
        zeroNeed = -1;
        for (int i=0; i<81; i++) {
            if (map.at(i) == 0 && count[i] > max) {
                max = count[i];
                zeroNeed = i;
            }
        }
        //cout<<"zero : "<<zeroNeed<<endl;
        for (int j=0; j<9; j++) {
            //cout<<"j is : "<<j<<endl;
            if(exist[zeroNeed][j] == false) {
                map.at(zeroNeed) = j+1;
                Sudoku *tmp = new Sudoku(getMap(),getAns());
                delete tmp;
            }
        }
    }
}
vector < int > Sudoku::getMap() {
    return map;
}
int Sudoku::getAns() {
    return Ans;
}
void Sudoku::setAns(int A) {
    Ans = A;
}
