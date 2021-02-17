//--------------------------------------------------------------------
//				CS315-001  Assignment 1 
//--------------------------------------------------------------------
// Author: Justin Hamilton
// Date: 2/12/2021
// Description: Train Switching Simulation  
// Assistance: I reviewed some code previously written for another course,
// class notes and tutoring from Tau Beta Pi
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std; 



// Node/Car Class
class car
{
public:
    car();
    int data; 
    car * next; 
    car * prev;
};

//--------------------------------------------------------------------------------------
//                                      car()
//--------------------------------------------------------------------------------------
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
    train(int numCar);
    void insertFront(int value);  
    void insertRear(int value);
    int deleteFront();
    int deleteRear();
    int valueofTrain();
};

//--------------------------------------------------------------------------------------
//                                      train()
//--------------------------------------------------------------------------------------
// Given: number of Cars
// This Constructor fills a train with the given number of cars 
//--------------------------------------------------------------------------------------
train::train(int numCar){ 
    front = NULL; 
    rear = NULL;
    for (int iter = 1; iter <= numCar; iter++){ 
        insertRear(iter);
    }
}

//--------------------------------------------------------------------------------------
//                                      insertFront()
//--------------------------------------------------------------------------------------
// Given: some int 
// Inserts car with given int at front of train
//--------------------------------------------------------------------------------------
void train::insertFront(int value){  
    car * carro = new car();  
    carro->data = value;
    if(front == NULL && rear == NULL){
        front = carro;
        rear = carro; 
    }
    else{
        carro->next = front;
        front->prev = carro; 
        front = carro;
    } 
}

//--------------------------------------------------------------------------------------
//                                      insertRear()
//--------------------------------------------------------------------------------------
// Given: some int 
// Inserts car with given int at rear of train
//--------------------------------------------------------------------------------------
void train::insertRear(int value){
    car * carro = new car(); 
    carro->data = value;  
    if(front == NULL && rear == NULL){
        front = carro; 
        rear = carro; 
    }
    else{
        carro->prev = rear;
        rear->next = carro; 
        rear = carro;
    }
}

//--------------------------------------------------------------------------------------
//                                      deleteFront()
//--------------------------------------------------------------------------------------
// Returns: value of deleted car 
// Deletes front car and moves rest down one space
//--------------------------------------------------------------------------------------
int train::deleteFront(){ 
    if((front == NULL && rear == NULL) || (front == rear)){
        return -1;
    } 
    int data = front->data;
    front = front->next;
    delete front->prev;
    front->prev = NULL; 
    return data; 
}

//--------------------------------------------------------------------------------------
//                                      deleteRear()
//--------------------------------------------------------------------------------------
// Returns: value of deleted car 
// Deletes rear car and moves rest down one space
//--------------------------------------------------------------------------------------
int train::deleteRear(){
    if((front == NULL && rear == NULL) || (front == rear)){
        return -1;
    } 
    int data = rear->data; 
    rear = rear->prev; 
    delete rear->next; 
    rear->next = NULL; 
    return data; 
}

//--------------------------------------------------------------------------------------
//                                     valueofTrain()
//--------------------------------------------------------------------------------------
// Returns: Value of train
// Calculates value of train by adding cars whose value is defined as data * position 
//--------------------------------------------------------------------------------------
int train::valueofTrain(){
    car * temp = new car(); 
    temp = front;
    int value = 0;
    int counter = 1;
    while(temp != NULL){
        value = (temp->data * counter) + value;
        counter = counter + 1;
        temp = temp->next; 
    }
    return value;
}


//--------------------------------------------------------------------------------------
//                                      printTrains()
//--------------------------------------------------------------------------------------
// Given: train array, length of array
// Returns: control int to tell whether or not any trains are empty  
// Prints values of trains in a given train array 
//--------------------------------------------------------------------------------------
int printTrains(train * trains[], int length){
    int deleted = 0; 
    for(int iter = 1; iter <= length; iter ++){
        if(trains[iter-1]->valueofTrain() == 0){
            deleted = iter; 
        }
        cout <<setw(13) << "train " << iter << ": value: " << trains[iter-1]->valueofTrain() <<endl;
    }
    if(deleted > 0){
        cout << "Simulation is over; train " << deleted << " has no more cars left. " <<endl; 
    }
    return deleted; 
}




//--------------------------------------------------------------------------------------
//                                      main()
//--------------------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
    int big_random = 0;  //Random number to be passed in
    int deleted = 0; //Value of Deleted Car 
    int numberofTrains = stoi(argv[1]), numberofCars = stoi(argv[2]), turns = stoi(argv[3]); //input parameters 
    int sending, receiving; //Position of train sending car, position of train receiving,
    int positon;  //control int for whether car is sent from front or back  
    train * train_station[numberofTrains]; //Representation of Train Station 
    cin >> big_random;

    //Loop to fill up Trains with Cars 
    for (int iter = 0; iter < numberofTrains; iter++){
        train_station[iter] = new train(numberofCars);
    }

    //For Loop to do switching/printing 
    for(int iter = 1; iter <= turns || (deleted == -1); iter++){
        positon = (big_random % 2) + 1;
        sending = (big_random % numberofTrains) + 1; 
        cin >> big_random; 
        receiving = (big_random % numberofTrains) + 1;  
        if(positon == 1){ //Sent from the front 
            cout << "turn " << iter << ":train " << sending << " sends a car to train " << receiving << ", from front"  << endl;
            deleted = train_station[sending-1]->deleteFront();
            train_station[receiving-1]->insertFront(deleted);  
        }
        if(positon == 2){ // Sent from the back 
            cout << "turn " << iter << ":train " << sending << " sends a car to train " << receiving << ", from end"  << endl;
            deleted = train_station[sending-1]->deleteRear();
            train_station[receiving-1]->insertFront(deleted);
        }
         
        if(printTrains(train_station,numberofTrains) > 0 ){ //If any trains are empty 
            break;
        }
        cin.clear(); 
        cin >> big_random; 
    }

    return 0;
}



