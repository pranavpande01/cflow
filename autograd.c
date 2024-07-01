#include <stdio.h>
#include<math.h>


struct node{
    int *prev;
    double val;
    int *next;
};



 int main(){
    int x,y;

    struct  node a,b,c;
    c.prev=&a;
    c.val=pow( *(c.prev).val,4);
    c.next=NULL;

    printf("hi");


    
    return 0;
 }