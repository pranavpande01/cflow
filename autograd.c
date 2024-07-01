#include <stdio.h>
#include<math.h>


struct node{
    struct node* prev[10]; //array of address of structs
    double val;
    struct node* next[10]; //array of address of structs
};

double mul(double a,double b){
    return a*b;
}

double add(double a, double b){
    return a+b;
}
double dif(double a, double b){
    return a-b;
}
double divide(double a, double b){
    return a/b;
}

void backpropogation(){

}

void forwardpropogation(){

}
 

void calc(double x){
// (x^4) - 2x - 3
    struct node n1,n2,n3,n4,n5,n6;
    //int x=0;

    n1.prev[0]=NULL;
    n1.val=x;
    n1.next[0]=&n2;// one node to n2, one to n3
    n1.next[1]=&n3;
    
    n2.prev[0]=&n1;
    n2.val=pow((n2.prev[0])->val,4);
    n2.next[0]=&n5;

    n3.prev[0]=&n1;
    n3.val=mul(2,(n3.prev[0])->val);
    n3.next[0]=&n5;
    
    n4.prev[0]=NULL;
    n4.val=3;
    n4.next[0]=&n5;
    
    n5.prev[0]=&n2;
    n5.prev[1]=&n3;
    n5.val=dif((n5.prev[0])->val, (n5.prev[1])->val);
    n5.next[0]=&n6;

    n6.prev[0]=&n5;
    n6.prev[1]=&n4;
    n6.val=dif(n6.prev[0]->val,n6.prev[1]->val);


    //printf("%lf",n5.val);
    
    
    struct node nodes[10]={n1,n2,n3,n4,n5,n6};
    printf("x=%lf, y=%lf\n",x,nodes[5].val);

}


 
 int main(){
    double x=-3;
    while(x<3){
        calc(x);
        x=x+0.1;
}
    return 0;
 }