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
public:
    car * front; 
    car * rear;
    train * makeTrain(int numberofCars);
    bool isEmptyTrain(train * input);
    void insertFront(car * n); 
    void insertRear(car * n); 
    void deleteFront();
    void deleteRear();
    int valueofTrain();
    //void printTrains(train * input);
};

train * train::makeTrain(int numberofCars){ //Make Train when given number of cars
    train * answer; 
    if(numberofCars == 0){ //return dummy node 
        answer->front = answer->rear;
        return answer; 
    }
    else if(numberofCars == 1){
        car * temp; 
        temp ->data = 1; 
        answer->front = temp; 
        answer->rear = temp;
        return answer
    }
    else{
        car * first; 
        answer->front = first; 
        answer->rear = first;
        first->data = 1; 
        for(int i = 2; i < numberofCars; i++){
            car * filler; 
            filler->data = i * i;
            answer->rear = filler;
            
        }
        return answer;
    }            

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
    int value = 1;
    int counter = 1;
    while(temp != rear){
        value = (temp->data * counter) + value;
        counter += 1;
        temp = temp->next; 
    }
    return value;
}


//Misc Methods

//Dice Roll Method
// Mode 1 is 2 sided dice 
//Mode 2 is n sided dice
int diceRoll(int mode, int range, int random_number){
    int answer = 0;
    if(mode == 1){
        answer = (random_number % 2) +1;
        return answer; 
    }
    else{
        answer = (random_number % range) + 1;
        return answer;
    }
}

void printTrains(train * trains[], int length){
    for(int i = 0; i < length; i++){
        int train_counter = 1;
        cout << "train " << train_counter << " value: " << trains[i]->valueofTrain() <<endl;
    }
}




//Main Method 

int main(int argc, char const *argv[])
{
    int big_random; 
    int numberofTrains = stoi(argv[1]), turns = stoi(argv[2]), numberofCars = stoi(argv[3]);
    train * train_station[numberofTrains];
    
    cin >> big_random;
    //Fill up the Train Station
    for(int i = 0; i < numberofTrains; i++){
        car * temp;
        temp = train_station[i]->front;
        int j = 1; 
        while(temp != train_station[i]->rear){
            temp->data = j * j; 
            j+=1;
            temp = temp->next;
        }
    }

    return 0;
}



