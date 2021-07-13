//This code will take 10 names of people entering the bank, then print out the person's name whos work has been done
//each person will have 2 mins to complete the work
// In one run the code will take 30 people and then close with a message

#include <iostream>
#include <unistd.h>
using namespace std;

int size=10;
string queue[10];
int front = -1;
int back = -1;

//function to check if queue is empty
bool isempty(){
    if(front == -1 && back == -1){
        return true;
    }
    else{
        return false;
    }
}
//function to insert element in queue
void enqueue (string value){
    if (back == size-1){
        cout<<"Queue is full \n";
    }
    else{
        if( front == -1){
            front = 0;
        }
        back++;
        queue[back] = value;
    }
}
//function to remove element from queue
//this function is used to remove people's name who's work has been done
void dequeue (){
    if (isempty()==true){
        cout<<"Queue is empty\n";
    }
    else{
        if(front == back){
            front = back = -1;
        }
        else{
            front++;
        }
    }
}
//function to access front name whos's work is done
string showfront(){
    if( isempty()){
        cout<<"Queue is empty\n";
    }
    return queue[front];
}

//function to insert customer’s name
void insertpeople (){
    string name = "";

    for (int i=0; i<10; i++){
        cout<<"Enter Your Name: ";
        cin>>name;
        enqueue(name);
    }
}

//the function which prints out the names from the start in 2 mins interval
void bankwork(){
    int counter=0;

    while (counter<30){
        if (isempty()==false){
            for (int i=0; i<10; i++) //take 10 input
            {
                usleep(1000000*120); //2 mins time (2*60)
                cout<<showfront() << " has just left the Bank" <<endl;
                dequeue();
                counter++; // to check for 30 output
            }
        }
        else{
            insertpeople();
        }
    }
    cout<<"The bank is closed for the day"<<endl;
}

int main(){

    bankwork();

    return 0;
}
