#include<iostream>
#include <stdlib.h>
using namespace std;

   //global variables
    char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; 
    int row,col;
    char token='X';
    string n1,n2;
    bool draw=false;

void clearScreen(){
    system("CLS");
}

void structure(){
    

    cout<<"  "<<space[0][0]<<"   |"<<"  "<<space[0][1]<<"  |"<<"  "<<space[0][2]<<endl;
    cout<<"      |     |     "<<endl;
    cout<<"______|_____|_____"<<endl;
    cout<<"  "<<space[1][0]<<"   |"<<"  "<<space[1][1]<<"  |"<<"  "<<space[1][2]<<endl;
    cout<<"      |     |     "<<endl;
    cout<<"______|_____|_____"<<endl;
    cout<<"  "<<space[2][0]<<"   |"<<"  "<<space[2][1]<<"  |"<<"  "<<space[2][2]<<endl;
    cout<<"      |     |     "<<endl;
    cout<<"      |     |     "<<endl;

}

bool result(){
    for(int i=0;i<3;i++){
        if((space[i][0]==space[i][1] && space[i][1]==space[i][2])||(space[0][i]==space[1][i] && space[1][i]==space[2][i])){ //horizontal and vertical
         return true;
        }
        }
    if((space[0][0]==space[1][1] && space[1][1]==space[2][2])||(space[0][2]==space[1][1]&&space[1][1]==space[2][0])){//diagonal
          return true;
        }
    
    for(int i=0;i<3;i++){ // keeps the program running if there's still space
        for(int j=0;j<3;j++){
            if(space[i][j]!='X' && space[i][j]!='O'){
                return false;
            }
        }
    }
    draw=true;// if horizontal/vertical and diagonal doesnt work out and there's no space remaining indicates it is a draw
    return true;// also stop the execution of the program
}

void input(){
    int digit;
    if(token=='X'){
        cout<<n1<<"Please enter: ";
        cin>>digit;
    }

    if(token=='O'){
        cout<<n2<<"Please enter: ";
        cin>>digit;
    }

    switch (digit)
    {
        case 1:row=0;
               col=0;
               break;
        case 2:row=0;
               col=1;
               break;
        case 3:row=0;
               col=2;
               break;
        case 4:row=1;
               col=0;
               break;
        case 5:row=1;
               col=1;
               break;
        case 6:row=1;
               col=2;
               break;
        case 7:row=2;
               col=0;
               break;
        case 8:row=2;
               col=1;
               break;
        case 9:row=2;
               col=2;
               break;
        default:cout<<"Invalid Input"<<endl;
    }
    if(token=='X'&& space[row][col]!='O' && space[row][col]!='X'){
        space[row][col]='X';
        token='O';
    }
    else if(token=='O'&& space[row][col]!='O' && space[row][col]!='X'){
        space[row][col]='O';
        token='X';
    }
    else{
     cout<<"Wrong input, Try Again"<<endl;
     input();
    }
    
}


int main(){

    cout<<"Enter the name of the first player"<<endl;
    getline(cin,n1);
    cout<<"Enter the name of the second player"<<endl;
    getline(cin,n2);
    cout<<n1<<" is player 1"<<endl;
    cout<<n2<<" is player 2"<<endl;
    cout<<n1<<" will be X and "<<n2<<" will be O"<<endl;

    while(!result()){
        structure();
        input();
        clearScreen();
      
    }
    if(token=='X' && draw==false)
      {
        cout<<n2<<" wins!"<<endl;
        structure();
      }
    else if(token=='O' && draw==false){
      cout<<n1<<" wins!"<<endl;
      structure();
    }
    else
       {
        cout<<"It's a draw"<<endl;
        structure();
       }
    
}
    