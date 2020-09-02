#include "sudoku.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    int Ans = 0;
    vector < int > in(81);
    for(int i = 0; i < 81; i++) {
        cin>>in.at(i);
    }
    Sudoku ques(in, Ans);
    Ans = ques.getAns();
    vector < int > nowAns(81);
    for (int i=0; i<81; i++)
        nowAns.at(i) = ques.ans.at(i);
    if(Ans == 1) {
        cout<<Ans<<endl;
        for(int i = 0; i < 81; i++) {
            cout<<nowAns[i];
            if(i%9 == 8)
                cout<<endl;
            else
                cout<<" ";
        }
    } else
        cout<<"0\n";
    return 0;
}
