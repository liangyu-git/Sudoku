#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>

using namespace std;

class Sudoku {
  public:
    Sudoku();
    Sudoku(vector<int>,int);
    vector < int > getMap();
    void solve();
    int getAns();
    static int Ans;
    static vector < int > ans;
  private:
    vector<int> map;
    int count[81], found, zero;
    bool exist[81][9], flag;
    void setAns(int A);
    void fill();
    void validator();
};
#endif