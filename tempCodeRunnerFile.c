#include <stdio.h>
#include <math.h>
#include <stdlib.h>


struct parameters{
int iteration;
double theta;
double learning_rate;
double beta_1;
double beta_2;
double epsilon;
double m;
double v;
};


double grad(double val){
   
    
    double gradient=4*pow(val,3) -2;
    return gradient;
}

double y(double x){
    return pow(x,4)-(2*x)-3;
}

struct parameters calc_theta(struct parameters params){
   
    params.iteration+=1;
    params.m= (params.beta_1*params.m)+(1-params.beta_1)*grad(params.theta);
   
    params.v=(params.beta_2*params.v)+(1-params.beta_2)*pow(grad(params.theta),2.0);
   
    double m1_hat=params.m/(1-pow(params.beta_1,params.iteration));

    double v1_hat=params.v/(1-pow(params.beta_2,params.iteration));

    params.theta= params.theta-(params.learning_rate*(m1_hat/(pow(v1_hat,0.5)+params.epsilon)));
   

    return params;
}



int main() 
{
    struct parameters params;
    struct parameters params_;
    
    FILE *file = fopen("values.txt", "r");
    fscanf(file,"%d",&params.iteration);
    fscanf(file,"%lf",&params.learning_rate);
    fscanf(file,"%lf",&params.beta_1);
    fscanf(file,"%lf",&params.beta_2);
    params.epsilon=pow(10,-8);
    fscanf(file,"%lf",&params.m);
    fscanf(file,"%lf",&params.v);

    params.theta=18;
    printf("%lf\n",params.theta);

    double a[10];   
    int termination=1;
    int i=0;

    while(termination){
        termination=0;

        params_=calc_theta(params);
        params.iteration=params_.iteration;
        params.theta=params_.theta;
        params.learning_rate=params_.learning_rate;
        params.beta_1=params_.beta_1;
        params.beta_2=params_.beta_2;
        params.epsilon=params_.epsilon;
        params.m=params_.m;
        params.v=params_.v;
        params=params_;

        a[i%10]=y(params.theta);

        for(int j=1;j<10;j++){
            if(a[j]!=a[j-1]){
                termination=1;
                break;
            }
        }

        i++;

    }
    printf("optimization completed in %d steps\n",i);
    printf("x=%lf y=%lf\n",params.theta,y(params.theta));
    return 0;
}
