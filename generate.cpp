#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    int gen[81] = {
        3, 0, 2, 0, 0, 5, 6, 9, 0,
        0, 4, 0, 0, 9, 6, 0, 3, 0,
        0, 5, 0, 0, 0, 8, 0, 0, 0,
        1, 9, 0, 0, 8, 0, 7, 0, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        5, 0, 7, 0, 3, 0, 0, 6, 1,
        0, 0, 0, 8, 0, 0, 0, 2, 0,
        0, 8, 0, 9, 6, 0, 0, 7, 0,
        0, 6, 5, 7, 0, 0, 3, 0, 9
    };
    /*
    ofstream outfile("su_question", ios::out);
    if(!outfile){
        cerr<<"Failed opening"<<endl;
        exit(1);
    }
    */
    for(int i = 0; i<81; i++) {
        cout<<gen[i];
        //outfile<<gen[i];
        if(i%9 == 8) {
            cout<<endl;
            //outfile<<endl;
        } else {
            cout<<" ";
            //outfile<<" ";
        }
    }
    return 0;
}
