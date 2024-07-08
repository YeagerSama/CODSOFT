#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int a,b;
    char op;
    cout<<"Enter two numbers to perform operations on: "<<endl;
    cin>>a>>b;
    cout<<"Enter the operator"<<endl;
    cin>>op;

    switch (op)
    {
    case '+': cout<<"The answer is: "<<(a+b);
              break;
    case '-': cout<<"The answer is: "<<(a-b);
              break;
    case '*': cout<<"The answer is: "<<(a*b);
              break;
    case '/': cout<<"The answer is: "<<(a/b);
              break;
    case '%': cout<<"The answer is: "<<(a%b);
              break;
    case '^': cout<<"The answer is: "<<(pow(a,b));
              break;
    default:cout<<"Invalid Input"<<endl;
        break;
    }

}