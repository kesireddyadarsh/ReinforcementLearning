//
//  main.cpp
//  reinforcement
//
//  Created by ak on 6/27/16.
//  Copyright © 2016 ak. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

bool errorMode = true;
vector< vector<int> > localArea;

class agent{
public:
    void turnLeft();
    void turnRight();
    void moveForward();
    void moveBack();
private:
};

class target{
public:
    
private:
};

class environment{
public:
     void createEnvironment(int length, int breadth);
    void fixTargets(int locationLength, int locationBreadth, int homeAgentLength, int homeAgentBreadth);
    void print(int length,int breadth);
private:
   
};

void environment::createEnvironment(int length, int breadth){
    vector<int> temp;
    for (int i = 0 ; i<breadth; i++) {
        for (int j=0 ; j<length; j++ ) {
            temp.push_back(0);
        }
        localArea.push_back(temp);
        temp.clear();
    }
}

void environment::fixTargets(int locationLength, int locationBreadth, int homeAgentLength, int homeAgentBreadth){
    localArea.at(locationBreadth).at(locationLength)=2;
    localArea.at(homeAgentBreadth).at(homeAgentLength)=2;
}

void environment::print(int length,int breadth){
    for (int i=0; i<breadth; i++) {
        for (int j=0; j<length; j++) {
            cout<<localArea.at(i).at(j);
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    int length = 10;
    int breadth = 10;
    environment envi;
    envi.createEnvironment(length, breadth);
    //locationLength will be required location-1
    //locationBreadth will be required location-1
    int locationLength = 9;
    int locationBreadth = 5;
    int homeAgentLength = 0;
    int homeAgentBreadth = 0;
    envi.print(length, breadth);
    envi.fixTargets(locationLength,locationBreadth,homeAgentLength,homeAgentBreadth);
    envi.print(length, breadth);
    return 0;
}
