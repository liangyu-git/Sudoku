#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

void changeNum(vector<int> &map, int x, int y) {
    int temp = y;
    for(int i = 0; i<81; i++) {
        if(map.at(i) == x)
            map.at(i) = -1;
    }
    for(int i = 0; i<81; i++) {
        if(map.at(i) == y)
            map.at(i) = x;
    }
    for(int i = 0; i<81; i++) {
        if(map.at(i) == -1)
            map.at(i) = y;
    }
}
void changeCol(vector<int> &map, int x, int y) {
    vector<int> copy(map);
    for(int i = 3*x, j = 3*y; i<3*x+3; i++, j++) {
        for(int k = 0; k<9; k++) {
            map.at(i+9*k) = copy.at(j+9*k);
            map.at(j+9*k) = copy.at(i+9*k);
        }
    }
}
void changeRow(vector<int> &map, int x, int y) {
    vector<int> copy(map);
    for(int i = 27*x, j = 27*y; i<27*x+27; i+=9, j+=9) {
        for(int k = 0; k<9; k++) {
            map.at(i+k) = copy.at(j+k);
            map.at(j+k) = copy.at(i+k);
        }
    }
}
void clockwiseRotate(vector<int> &map) {
    vector<int> copy(map);
    for(int i = 8; i>=0; i--) {
        for(int j = 0; j<9; j++) {
            map.at(i+9*j) = copy.at((8-i)*9+j);
        }
    }
}
void up_down(vector<int> &map) {
    vector<int> copy(map);
    for(int i = 0; i<4; i++) {
        for(int j = 0; j<9; j++) {
            map.at(9*i+j) = copy.at((8-i)*9+j);
            map.at(9*(8-i)+j) = copy.at(9*i+j);
        }
    }
}
void left_right(vector<int> &map) {
    vector<int> copy(map);
    for(int i = 0; i<4; i++) {
        for(int j = 0; j<9; j++) {
            map.at(i+9*j) = copy.at((8-i)+9*j);
            map.at((8-i)+9*j) = copy.at(i+9*j);
        }
    }
}
int main() {
    ofstream outfile("su_trans", ios::out);
    if(!outfile) {
        cerr<<"Failed opening"<<endl;
        exit(1);
    }
    vector<int> trans(81);
    for(int i = 0; i<81; i++) {
        cin>>trans.at(i);
        outfile<<trans.at(i);
    }/*
    for(int i = 0;i<81;i++){
        //infile>>trans.at(i);
        cout<<trans.at(i);
        if(i%9 == 8)
            cout<<endl;
        else
            cout<<" ";
    }*/
    char order[10];
    string str;
    int command = -1, x, y;
    while(command != 0) {
        /*for(int i = 0;i<81;i++){
            cout<<trans.at(i)<<" ";
            if(i%9 == 8)
                cout<<endl;
        }*/
        //cin.getline(order, 10);
        //str.assign(order);
        //command = str.at(0)-48;
        cin>>command;
        if(command == 1) {
            //x = str.at(2)-48;
            //y = str.at(4)-48;
            cin>>x;
            cin>>y;
            changeNum(trans, x, y);
        }
        if(command == 2) {
            //x = str.at(2)-48;
            //y = str.at(4)-48;
            cin>>x;
            cin>>y;
            changeRow(trans, x, y);
        }
        if(command == 3) {
            //x = str.at(2)-48;
            //y = str.at(4)-48;
            cin>>x;
            cin>>y;
            changeCol(trans, x, y);
        }
        if(command == 4) {
            //x = str.at(2)-48;
            cin>>x;
            for(int i = 0; i<x; i++)
                clockwiseRotate(trans);
        }
        if(command == 5) {
            //x = str.at(2)-48;
            cin>>x;
            if(x == 0)
                up_down(trans);
            if(x == 1)
                left_right(trans);
        }
    }
    for(int i = 0; i<81; i++) {
        cout<<trans.at(i);
        if(i%9 == 8)
            cout<<endl;
        else
            cout<<" ";
    }
    return 0;
}
