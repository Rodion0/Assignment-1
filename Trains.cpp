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
public:
    car();
    int data; 
    car * next; 
    car * prev;
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
    bool isEmptyTrain(train * input);
    void insertFront(car * n); 
    void insertRear(car * n); 
    void deleteFront();
    void deleteRear();
    int valueofTrain();
    //void printTrains(train * input);
};

void train::makeEmptyTrain(){
    
}

bool train::isEmptyTrain(train * input){
    return(input->front == input->rear);
}

void train::insertFront(car * n){

}

void train::deleteFront(){

}

void train::deleteRear(){

}

/*void train::printTrains(train * input){ //Instead of having a method inside the train object itself
    car * temp = new car;                 //Maybe make method that takes array of trains and turn number 
    int value                             // For loop to increment turn in main 
    while(temp->next != input->rear){
        
    }
}*/

int train::valueofTrain(){
    car * temp = front;
    int value = 0;
    while(temp->next != rear){
        value = temp->data + value;
    }
    return value;
}


//Misc Methods

//Generate Random Number within bounds
int generateRandomNumber(){
     srand(time(0)); 
     return rand(); 
}

//Dice Roll Method
// Mode 1 is 2 sided dice 
//Mode 2 is n sided dice
int diceRoll(int mode, int range){
    int answer = 0;
    if(mode == 1){
        answer = (generateRandomNumber() % 2) +1;
        return answer; 
    }
    else{
        answer = (generateRandomNumber() % range) + 1;
        return answer;
    }
}

void printTrains(train * trains[], int length){
    for(int i = 0; i < length; i++){
        int train_counter = 1
        cout << "train " << train_counter << " value: " << trains[i].valueofTrain() <<endl;
    }
}


