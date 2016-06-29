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

bool breadthLocked = false;
bool lengthLocked = false;
vector< vector<int> > localArea;
int agentCurrentLocationLength;
int agentCurrentLocationBreadth;


class agent{
public:
    void turnLeft();
    void moveForward();
private:
};


void agent::turnLeft(){
    
}

void agent::moveForward(){
    
}



class target{
public:
    
private:
};

class environment{
public:
     void createEnvironment(int length, int breadth);
    void fixTargets(int targetLocationLength, int targetLocationBreadth, int homeAgentLength, int homeAgentBreadth);
    void print(int length,int breadth);
    void createRoadBlocks(int roadblocksLocation[][2],int length,int breadth);
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

void environment::fixTargets(int targetLocationLength, int targetLocationBreadth, int homeAgentLength, int homeAgentBreadth){
    localArea.at(targetLocationBreadth).at(targetLocationLength)=2;
    localArea.at(homeAgentBreadth).at(homeAgentLength)=2;
}

void environment::createRoadBlocks(int roadblocksLocation[][2],int length,int breadth){
    int num = (sizeof(roadblocksLocation)/2);
    for (int i=0; i<num; i++) {
        localArea.at(roadblocksLocation[i][0]).at(roadblocksLocation[i][1]) = -1;
        //print(length, breadth);
    }
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
    /*
     Below code creates environment
     It creates start location of agent
     It creates goal location for agent
     */
    int length = 10;
    int breadth = 10;
    environment envi;
    envi.createEnvironment(length, breadth);
    agent agentMovement;
    //targetLocationLength will be required location-1
    //targetLocationBreadth will be required location-1
    int targetLocationLength = 9;
    int targetLocationBreadth = 5;
    int homeAgentLength = 0;
    int homeAgentBreadth = 0;
    agentCurrentLocationLength = homeAgentLength;
    agentCurrentLocationBreadth = homeAgentBreadth;
    
    envi.print(length, breadth);
    envi.fixTargets(targetLocationLength,targetLocationBreadth,homeAgentLength,homeAgentBreadth);
    cout<<"\n\n\n"<<endl;
    envi.print(length, breadth);
    cout<<"\n\n\n"<<endl;
    
    /*
     Creates roadblocks
     */
    int roadblocksLocation[4][2]={{1,2},{2,3},{4,5},{6,7}};
    envi.createRoadBlocks(roadblocksLocation, length, breadth);
    envi.print(length, breadth);
    cout<<"\n\n\n"<<endl;
    /*
     Below code navigates the agent
     For now movement is Grid
     
    //Check if we can take one step in length
     */
    
//    while ((agentCurrentLocationLength != targetLocationLength) || (agentCurrentLocationBreadth != targetLocationBreadth)) {
//        if (((agentCurrentLocationLength+1) == length)||(agentCurrentLocationLength)<=0) {
//            lengthLocked =true;
//        }
//        if(((agentCurrentLocationBreadth+1) == breadth)||(agentCurrentLocationBreadth<=0)){
//            breadthLocked=true;
//        }
//        if(lengthLocked == false && (localArea.at(agentCurrentLocationBreadth).at(agentCurrentLocationLength+1)) == 0){
//            agentMovement.moveForward();
//        }
//        if (lengthLocked == true && breadthLocked == true) {
//            
//        }
//    }
    return 0;
}
