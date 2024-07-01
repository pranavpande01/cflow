// C++ program to illustrate the begin and end iterator
#include <iostream>
#include <map>
#include <string>
#include<vector>
#define MAX 1000
using namespace std;


char eq[]="((1)+((x)^(4)))-(((2)*(x))-(3))";
int len=sizeof(eq)/sizeof(char);





class Stack {
    int top;

public:
    int a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        //cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

vector<vector<int>> pairs;
void re(int index){
    //cout<<len;
    //cout<<eq[index];
    Stack open;
    vector<int> temp;
    vector<vector<int>> temp_;

    while(index<len){

        if(eq[index]=='('){
            open.push(index);
        }
        else if (eq[index]==')')
        {
            temp={open.peek(),index};
            cout<<open.peek()<<"-"<<index<<"\n";
            temp_={temp};
            pairs.insert(pairs.end(),temp_.begin(),temp_.end());
            open.pop();
        }
        else{
        }
        
        index++;
    
    }
}

int main()
{
    re(0);
for(int i=0;i<(sizeof(pairs)/sizeof(pairs[0]));i++){
    //cout<<pairs[i][0]<<"-"<<pairs[i][1]<<"\n";
    }
    return 0;
}
