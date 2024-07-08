#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

vector<string> tasks;

void clearScreen() {
   
    system("CLS");
}

void input(){
     cout<<"Enter all your tasks and press X after your done"<<endl;

    string t;
    while(t!="X"){
        getline(cin, t);
        tasks.push_back(t);
    }
}
void print(){
     cout<<"\t\tYour Tasks: "<<endl;
    for(int i=0;i<tasks.size()-1;i++){
        cout<<i+1<<"."<<tasks[i]<<endl;
    }

}

int main(){
    cout<<"\t\tTo Do List"<<endl;
    cout<<endl;
    cout<<endl;
    input();
    clearScreen();
    print();

}