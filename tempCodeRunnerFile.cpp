#include <iostream>
#include <map>
#include <string>
#include<vector>
#define MAX 1000
using namespace std;


char eq[]="(((x)+(6))*(((x)^(2))+(1)))";


struct node
{  
    struct node* parent;
    vector<int> pair;
    char op;
    vector<struct node*> children;
    float diff;
};

struct treeNode{

};
void details(struct node  n){
    printf("%p",n.parent);
    cout <<" : " << n.pair[0]<<" - "<<n.pair[1]<<" : "<<n.op<<" : ";

    for(int i=0;i<n.children.size();i++) cout<<n.children[i]<<" , ";
    cout<<"\n";
}

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


vector<struct node> makeHeirarachyGraph(){
    vector<struct  node> graph;
    vector<vector<int>> pairs=re(0);

// populating
    for(int i=0;i<pairs.size();i++){
        struct node temp={NULL, pairs[i],'^',{NULL},0};
        vector<struct node> temp_={temp};
        graph.insert(graph.end(),temp_.begin(),temp_.end());
    }


    //sorting graph vector
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
   
    //populating parents and children
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            if(graph[i].pair[0]>graph[j].pair[0] && graph[i].pair[1]<graph[j].pair[1]){
                graph[i].parent=&graph[j];
            }
        }
        if(graph[i].parent!=NULL){
                vector<struct node *> a={&graph[i]};
                (graph[i].parent)->children.insert((graph[i].parent)->children.begin(),a.begin(),a.end());
                
        }
       


    }

   
    //cleaning
    int i=0;
    while(i<graph.size()){
        
        if(graph[i].children.size()>1) graph[i].children.pop_back();
        i++;
    }
   
    
   


    i=0;
    //sorting children
    while(i<graph.size()){
            if (graph[i].children[0] !=NULL){
            if(graph[i].children[1]->pair[0]<graph[i].children[0]->pair[0]){
                struct node * temp=graph[i].children[1];
                graph[i].children[1]=graph[i].children[0];
                graph[i].children[0]=temp;
            }
            }
            i++;
        
    }
        
        
    i=0;
    while(i<graph.size()){
            if (graph[i].children[0] !=NULL){
                    //cout<<eq[graph[i].children[0]->pair[1]+1]<<"\n";
                    graph[i].op=eq[graph[i].children[0]->pair[1]+1];
            }
            i++;
        
    }

    return graph;
}


int main()
{
   
   
    vector<struct node> graph=makeHeirarachyGraph();
    int i=0;
    while(i<graph.size()){
       details(graph[i]);
        i++;
    }
   
   
    return 0;
   

}
