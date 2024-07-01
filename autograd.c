#include <stdio.h>
#include<math.h>


struct node{
    struct node* prev[10]; //array of address of structs
    double val;
    double grad;
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

double cons(double a){
    
    return a;
}
void backpropogation(){

}

void forwardpropogation(){

}
 

void calc(double x){
// (x^4) - 2x - 3
    struct node n1,n2,n3,n4,n5,n6,n7,n8;
    //int x=0;

    n1.prev[0]=NULL;
    n1.val=x;
    n1.next[0]=&n5;
    n1.next[1]=&n6;

    
    n2.prev[0]=NULL;
    n2.val=cons(4);
    n2.next[0]=&n5;
    
    n3.prev[0]=NULL;
    n3.val=cons(2);
    n3.next[0]=&n6;
    
    n4.prev[0]=NULL;
    n4.val=cons(3);
    n4.next[0]=&n8;
    
    n5.prev[0]=&n1;
    n5.prev[1]=&n2;
    n5.val=pow(n5.prev[0]->val,n5.prev[1]->val);

    
    n6.prev[0]=&n1;
    n6.prev[1]=&n3;
    n6.val=mul(n6.prev[0]->val,n6.prev[1]->val);
    
    n7.prev[0]=&n5;
    n7.prev[1]=&n6;
    n7.val=dif(n7.prev[0]->val,n7.prev[1]->val);
    n7.next[0]=&n8;
    
    n8.prev[0]=&n7;
    n8.prev[1]=&n4;
    n8.val=dif(n8.prev[0]->val,n8.prev[1]->val);
    n8.next[0]=NULL;
    
    struct node nodes[10]={n1,n2,n3,n4,n5,n6,n7,n8};
    //printf("x=%lf, y=%lf\n",x,nodes[7].val);
    printf("%lf",nodes[7].val);
    
}


 
 int main(){
    double x=-1;
   // while(x<3){
     //   calc(x);
       // x=x+0.1;
//}
calc(x);
    return 0;
 }