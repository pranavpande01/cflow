// C++ program to illustrate the begin and end iterator
#include <iostream>
#include <map>
#include <string>
#include<vector>
#define MAX 1000
using namespace std;


char eq[]="(((1)+((x)^(4)))-(((2)*(x))-(3)))";


struct node
{   
    struct node* parent;
    vector<int> pair;
    vector<struct node*> children;
};

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

vector<vector<int>> re(int index){
    
    Stack open;
    vector<int> temp;
    vector<vector<int>> temp_;
    vector<vector<int>> pairs;
    while(index<(sizeof(eq)/sizeof(char))){


        if(eq[index]=='('){
            open.push(index);
        }
        else if (eq[index]==')')
        {
            temp={open.peek(),index};
            //cout<<open.peek()<<"-"<<index<<"\n";
            temp_={temp};
            pairs.insert(pairs.end(),temp_.begin(),temp_.end());            
            open.pop();
        }
        else{
        }
        
        index++;
    
    }
    return pairs;
}

int main()
{
    vector<vector<int>> pairs=re(0);
    int len=pairs.size();
  
    vector<struct  node> graph;
  
for(int i=0;i<len;i++){
    struct node temp={NULL, pairs[i],{NULL}};
    vector<struct node> temp_={temp};
    graph.insert(graph.end(),temp_.begin(),temp_.end());
    }

//sort the graph vector according to the ascending order of opening bracket index
int flag=1;   

while (flag==1){
    flag=0;
    struct node temp;

    for(int i=1;i<graph.size();i++){
        
            if (graph[i].pair[0]<graph[i-1].pair[0]){
                temp=graph[i-1];
                graph[i-1]=graph[i];
                graph[i]=temp;
                flag=1;
        
                }
        
        
        }
    }
   
    for(int i=0;i<graph.size();i++){
        cout<<graph[i].pair[0]<<"-"<<graph[i].pair[1]<<"\n";
    }
    
    
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            if(graph[i].pair[0]>graph[j].pair[0] && graph[i].pair[1]<graph[j].pair[1]){
                graph[i].parent=&graph[j];
            }
        }
    }

    for(int i=0;i<graph.size();i++){
        cout<<graph[i].parent<<"   :   "<<graph[i].pair[0]<<"-"<<graph[i].pair[1]<<&graph[i]<<"\n";
    }

    return 0;
    

}
