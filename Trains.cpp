//--------------------------------------------------------------------
//				CS315-001  Assignment 1 
//--------------------------------------------------------------------
// Author: Justin Hamilton
// Date: 2/12/2021
// Description: Train Switching Simulation  
// Assistance: I reviewed some code previously written for another course 
//--------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
using namespace std; 


//Construtor for Nodes/Cars

class car
{
private:
    int data; 
    car * next; 
    car * prev;
public:
    car();
};

car::car()
{
    data = 0; 
    next = NULL; 
    prev = NULL; 
}




// Methods for Doubly Linked List/Train  

class train
{
private:
    car * front; 
    car * rear; 
public:
    void makeEmptyTrain();
    bool isEmptyTrain();
    void insertFront(car * n); 
    void insertRear(car * n); 
    void deleteFront();
    void deleteRear();
    void printTrains();
};

void train:makeEmptyTrain(){
    
}

bool train:is_EmptyTrain(){
    return(this->front == this->rear)
}

void train:insertFront(car * n){

}

void deleteFront(){

}

void deleteRear(){

}

void printTrains(){

}


//Misc Methods

//Generate Random Number within bounds
int generateRandomNumber(){
     
}


