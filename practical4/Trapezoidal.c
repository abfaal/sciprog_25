#include <stdio.h>
#include <math.h>

//Function prototypes
float degtorad(float degang);
float traprule(int N, float TanArr[N+1]);

int main()
{
  int N=12, i;
  float TanArr[N+1], deg, rad, area;
  
  //f(xi) at x_i i=0, ....., 12
  for(i=0; i<=N; i++){
    deg = i*5.0;
    rad = degtorad(deg);
    TanArr[i] = tan(rad);
    printf("TanArr[%d]%f\n", i, TanArr[i]);
  }
  
  //Calculate area using trapezoidal rule
  area = traprule(N, TanArr);

  printf("\nTrapezoidal result: %f\n",area);
  printf("Real result: %f\n",log(2.0));

  return 0;
}

//Convert degrees to radians
float degtorad(float degang){
  return((M_PI*degang)/180.0);
}

//Implementing the Trapezoidal rule
float traprule(int N, float TanArr[N+1]){
  float area;
  int i;

  area = TanArr[0] + TanArr[N];
  for(i=1; i<N; i++){
    area = area+2.0*TanArr[i];
  }

  float mult_rad = degtorad((60.0-0.0)/(2*N));
  area=mult_rad*area;

  return area;
}

