
#include <iostream>
#include "math.h"
#include <string>
#include<vector>
#include "stack.h"
#include <stdlib.h>

//#define MAX 1000
using namespace std;

char eq[]="(((x)^(2))+(1))";
//FILE *file = fopen("equation.txt", "r");
//char eq[];
//fscanf(file,"%d",&eq);

//char eq[]="(((3)+(0))*((x)^(2)))";
//char eq[]="(((s)o(x))+(0))";
//char eq[]="(((x)+(6))*(((x)^(2))+(1)))";
//char eq[]="(((x)+(4.00))*((x)^(2)))";

struct node
{  
    
    struct node* parent;
    vector<int> pair;
    char op;
    vector<struct node*> children;
    float diff;
    float val;
    int isleaf;
};

void details(struct node  n){
    printf("parent :%p\n",n.parent);
    cout <<"pair : " << n.pair[0]<<" - "<<n.pair[1]<<endl<<"op : "<<n.op<<endl<<"val : "<<n.val<<endl<<"diff :"<<n.diff<<endl;

    for(int i=0;i<n.children.size();i++) cout<<"children : "<<n.children[i]<<endl;
    cout<<"isleaf: "<<n.isleaf<<endl;
    cout<<"\n";
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

float diff(struct node n1, struct node n2,char op){
    
    float diff;
    switch (op)
    {
    case '^':
        diff=pow(n1.val,n2.val-1)*n2.val;
        break;
    case '+':
        diff=n1.diff+n2.diff;
        break;
    case '*':
        diff=(n1.diff*n2.val)+(n2.diff*n1.val);
        break;
    default:
        break;
    }
    return diff;
}

float val(struct node n1, struct node n2,char op){
    
    float val;
    switch (op)
    {
    case '^':
        val=pow(n1.val,n2.val);
        break;
    case '+':
        val=n1.val+n2.val;
        break;
    case '*':
        val=(n1.val*n2.val);
        break;
    default:
        break;
    }
    return val;
}

vector<struct node> makeHeirarachyGraph(){
    vector<struct  node> graph;
    vector<vector<int>> pairs=re(0);
    float x=1.5;
    
// populating
    for(int i=0;i<pairs.size();i++){
        struct node temp={NULL, pairs[i],'_',{NULL},0,0,0};
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

    i=0;
    while(i<graph.size()) {
    if(graph[i].children[0] ==NULL) graph[i].isleaf=1;
    i++;
    }

    i=0;
    while(i<graph.size()){
        if(graph[i].isleaf) {

            if(eq[graph[i].pair[0]+1]=='x') {
                graph[i].val=x;
                graph[i].diff=1;
                }
            else if (eq[graph[i].pair[0]+1]=='e'){
                graph[i].val=exp(1);
                graph[i].diff=0;
                }
                
            else {
                graph[i].val=stof(string(&eq[graph[i].pair[0]+1],&eq[graph[i].pair[1]]));
                graph[i].diff=0;
                }
            
        }
        i++;

        
    }
    i=0;
    while(i<graph.size()){
        if(graph[i].isleaf){
            struct node * curr=graph[i].parent;
            while (curr !=NULL)
            {
                
                curr->val=val(*curr->children[0],*curr->children[1],curr->op);;
                //cout<<curr<<endl;
                //details(*curr);
                curr=curr->parent;
                //cout<<"lala\n";
                //j++;

            }
            
            
        }
        i++;
    }

    i=0;
    while(i<graph.size()){
        if(graph[i].isleaf){
            struct node * curr=graph[i].parent;
            while (curr !=NULL)
            {
                
                curr->diff=diff(*curr->children[0],*curr->children[1],curr->op);;
                //cout<<curr<<endl;
                //details(*curr);
                curr=curr->parent;
                //cout<<"lala\n";
                //j++;

            }
            
            
        }
        i++;
    }
      
    return graph;
}



int main()
{
   
   
    vector<struct node> graph=makeHeirarachyGraph();
    int i=0;
    /*
    while(i<graph.size()){
       details(graph[i]);

        i++;
    }
    */
   cout<<"grad = "<<graph[0].diff;
    return 0;


}

//_func__