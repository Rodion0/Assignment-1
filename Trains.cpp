//--------------------------------------------------------------------
//				CS315-001  Assignment 1 
//--------------------------------------------------------------------
// Author: Justin Hamilton
// Date: 2/12/2021
// Description: Train Switching Simulation  
// Assistance: I reviewed some code previously written for another course and class notes
//--------------------------------------------------------------------

//TODO: FIX DELETE METHODS 
// FIX PRINTING 
// ADD BOUNDRY CASES
#include <iostream>
#include <string>
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
public:
    car * front; 
    car * rear;  
    //car * dummy; 
    train(int numCar);
    //train * makeTrain(int numberofCars);
    void insertFront(int value);  
    void insertRear(int value);
    int deleteFront();
    int deleteRear();
    int valueofTrain();
};

train::train(int numCar){
    front = NULL; 
    rear = NULL;
    for (int i = 1; i <= numCar; i++){
        insertRear(i);
    }
}

void train::insertFront(int value){ 
    car * carro = new car(); 
    if(front == NULL && rear == NULL){
        carro->data = value; 
        front = carro;
        rear = carro; 
    }
    else{
        carro->data = value;
        carro->next = front->next;
        front->prev = carro; 
        front = carro;
    } 
}

void train::insertRear(int value){
    car * carro = new car();   
    if(front == NULL && rear == NULL){
        front = carro; 
        rear = carro; 
    }
    else{
        carro->data = value;
        carro->prev = rear;
        rear->next = carro; 
        rear = carro;
    }
}

int train::deleteFront(){ 
    if(front == rear){
        return -1;
    } 
    int data = front->data;
    front= front->next;
    delete front->prev;
    front->prev = NULL; 
    return data; 
}

int train::deleteRear(){
    if(front == rear){
        return -1;
    } 
    int data = rear->data; 
    rear = rear->prev; 
    delete rear->next; 
    rear->next = NULL; 
    return data; 
}

int train::valueofTrain(){
    car * temp = new car(); 
    temp = front;
    int value = 1;
    int counter = 1;
    while(temp != NULL){
        value = (temp->data * counter) + value;
        counter = counter + 1;
        //cout << "Value is: " << value << " Count is at "  << counter <<endl; 
        temp = temp->next; 
    }
    return value;
}

/* train * train::makeTrain(int numberofCars){ //Make Train when given number of cars
    train * answer = new train();  
    if(numberofCars == 0){ //return dummy node 
        return answer; 
    }
    else{
        for (int i = 1; i <= numberofCars; i++){
            answer.insertRear(i);
        }
        return answer;
    }            
} */

//Misc Methods

//Dice Roll Method
// Mode 1 is 2 sided dice 
//Mode 2 is n sided dice
/* int diceRoll(int mode, int range, int random_number){
    int answer = 0;
    if(mode == 1){
        answer = (random_number % 2) +1;
        return answer; 
    }
    else{
        answer = (random_number % range) + 1;
        return answer;
    }
} */

//Print Trains Mth
void printTrains(train * trains[], int length){
    for (int i = 1; i <= length; i++){ 
            if(trains[i-1]->valueofTrain() == 0){
                for(int j = i; j <= length; j++){
                     cout << "train " << i << " : value " << trains[j-1]->valueofTrain() <<endl;
                }
                cout << "Simulation is over; train " << i << " has no cars left." <<endl;
                break;
            }
            cout << "train " << i << " : value " << trains[i-1]->valueofTrain() <<endl;
        }
}




//Main Method 

int main(int argc, char const *argv[])
{
    int big_random; 
    int numberofTrains = stoi(argv[1]), numberofCars = stoi(argv[2]), turns = stoi(argv[3]);
    int sending, receiving, positon;
    string random_number; 
    train * train_station[numberofTrains];
    cout << "Number of Trains: " << numberofTrains << " number of turns: " << turns << " number of cars: " << numberofCars <<endl; 
    cin >> big_random;

    //cout << big_random; 

    //Loop to fill up Trains with Cars 
    for (int i = 0; i < numberofTrains; i++){
        train_station[i] = new train(numberofCars);
    }

    //For Loop to do switching/printing 
    for(int i = 1; i <= turns; i++){
        positon = (big_random % 2) + 1;
        sending = (big_random % numberofTrains) + 1; 
        cin >> big_random; 
        receiving = (big_random % numberofTrains) + 2; 
        //cout << "Position is " << positon << " Sending is " << sending << " Receving is " << receiving <<endl; 
        if(positon == 1){
            cout << "turn " << i << ": train " << sending << " sends a car to train " << receiving << ", from front"  << endl;
            int deleted = train_station[sending]->deleteFront();
            //Loop for when Delete Returns a negative Number
            train_station[receiving]->insertFront(deleted);  
            //cout << "I am deleting from the front" <<endl; 
        }
        if(positon == 2){
            cout << "turn " << i << ": train " << sending << " sends a car to train " << receiving << ", from end"  << endl;
            int deleted = train_station[sending]->deleteRear();
            train_station[receiving]->insertFront(deleted);
            //cout << "I am deleting from the rear" << endl; 
        }
         
        printTrains(train_station,numberofTrains);
        cin.clear(); 
        cin >> big_random; 
        
        //cout << " I have done a turn" <<endl; 
    }

    return 0;
}



