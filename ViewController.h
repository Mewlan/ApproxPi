#include <stdio.h>
#include <math.h>

/***Model***/

/*APM*/
#define MAX_T0 1e-6
#define MAX_T1 1e-8
#define MAX_T0_STR "1e-6"
#define MAX_T1_STR "1e-8"

typedef struct Apm
{
	int sign;
	double pi0;
	double pi1;
	double n;
	double term;
	int count0; 
	int count1;
} APM;

APM * approxPiModel();
/*endAPM*/

/***View***/

/*APV*/
#define V_STR0 "pi = %10.8f, count = %d, max term = %s%c"

void approxPiView(APM *apm);
/*endAPV*/

/***Controller***/

/*APC*/
APM * approxPiCtrl(APM *apm);
/*endAPC*/






