//--------------------------------------------------------------------
//				CS315-001  Assignment 1 
//--------------------------------------------------------------------
// Author: Justin Hamilton
// Date: 2/12/2021
// Description: Train Switching Simulation  
// Assistance: I reviewed some code previously written for another course and class notes
//--------------------------------------------------------------------
#include <iostream>
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
    //car * front; 
    //car * rear;  
    car * dummy; 
    train * makeTrain(int numberofCars);
    void insertFront(int n);  
    void insertRear(int n);
    int deleteFront();
    int deleteRear();
    int valueofTrain();
};


void train::insertFront(int n){
    car * carro = new car();
    carro->data = n;  
    car * after = dummy->next;
    carro->next = after->prev;
    carro->prev = dummy->next; 
    dummy->next = carro; 
    after->prev = carro;  
}

void train::insertRear(int n){
    car * carro = new car();
    carro->data = n;  
    car * before = dummy->prev;
    carro->next = dummy->prev;
    carro->prev = before->next; 
    dummy->prev = carro; 
    before->next = carro;          
}

int train::deleteFront(){
    if(dummy->next == dummy->prev){
        return -1;
    } 
    car * rip = dummy->next;
    dummy->next = rip->next; 
    if(dummy->next == NULL){
       dummy->next = dummy-> prev = dummy;
        return -1; 
    } 
    return rip->data; 
}

int train::deleteRear(){
    if(dummy->next == dummy->prev){
        return -1;
    } 
    car * rip = dummy->prev;
    dummy->prev = rip->prev; 
    if(dummy->next == NULL){
       dummy->next = dummy-> prev = dummy;
        return -1; 
    } 
    return rip->data;
}

int train::valueofTrain(){
    car * temp = new car;
    temp = dummy->next;
    int value = 1;
    int counter = 1;
    while(temp != dummy){
        value = (temp->data * counter) + value;
        counter += 1;
        temp = temp->next; 
    }
    return value;
}

train * train::makeTrain(int numberofCars){ //Make Train when given number of cars
    train * answer = new train;   
    answer->dummy->next = answer->dummy->prev = dummy;
    if(numberofCars == 0){ //return dummy node 
        return answer; 
    }
    else{
        for (int i = 1; i <= numberofCars; i++){
            answer->insertRear(i*i);
        }
        return answer;
    }            
}

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
    int numberofTrains = stoi(argv[1]), turns = stoi(argv[2]), numberofCars = stoi(argv[3]);
    int sending, receiving, positon;
    train * train_station[numberofTrains];
    cout << numberofTrains << " number of turns: " << turns << " number of cars: " << numberofCars <<endl; 
    cin >> big_random;

    //cout << big_random; 

    //Loop to fill up Trains with Cars 
    for (int i = 0; i < numberofTrains; i++){
        cout << "Hello There" <<endl; 
        train_station[i]->makeTrain(numberofCars); 
        cout << "I am filling up the trains " << i << endl; 
    }
    
    //Fill up the Train Station
    /* for(int i = 0; i < numberofTrains; i++){
        car * temp;
        temp = train_station[i]->front;
        int j = 1; 
        while(temp != train_station[i]->rear){
            temp->data = j * j; 
            j+=1;
            temp = temp->next;
        }
        cout << "I have filled the train station" << endl; 
    } */

    //For Loop to do switching/printing 
    for(int i = 1; i <= turns; i++){
        positon = (big_random % 2) + 1;
        sending = (big_random % numberofTrains) + 1; 
        receiving = (big_random % numberofTrains) + 1; 
        if(sending == receiving){
            printTrains(train_station,numberofTrains);
            cin >> big_random;
            continue; 
        }
        if(positon == 1){
            cout << "turn " << i << ": train " << sending << " sends a car to train " << receiving << " , from front"  << endl;
            int deleted = train_station[sending]->deleteFront();
            train_station[receiving]->insertFront(deleted);  
            cout << "I am deleting from the front" <<endl; 
        }
        if(positon == 2){
            cout << "turn " << i << ": train " << sending << " sends a car to train " << receiving << " , from rear"  << endl;
            int deleted = train_station[sending]->deleteRear();
            train_station[receiving]->insertFront(deleted);
            cout << "I am deleting from the rear" << endl; 
        }
         
        printTrains(train_station,numberofTrains);

        cin >> big_random;
        cout << " I have done a turn" <<endl; 
    }

    return 0;
}



