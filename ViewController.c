#include "ViewController.h"

APM * approxPiModel()
{
	APM anAPM;
	anAPM.sign = 1;
	anAPM.pi0 = 0.0;
	anAPM.pi1 = 0.0;
	anAPM.n = 1.0;
	anAPM.term = 1.0;
	anAPM.count0 = 0;
	anAPM.count1 = 0;
	return(&anAPM);
}

void approxPiView(APM *apm)
{
	printf(V_STR0, apm->pi0, apm->count0, MAX_T0_STR, '\n');
	printf(V_STR0, apm->pi1, apm->count1, MAX_T1_STR, '\n');
}

APM * approxPiCtrl(APM *apm)
{
	while(fabs(apm->term) >= MAX_T0) {
		apm->pi0 += apm->term;
		apm->n += 2;
		apm->sign = -apm->sign;
		apm->term = apm->sign / apm->n;
		++apm->count0;
	}
	apm->pi0 *= 4;
	while(fabs(apm->term) >= MAX_T1) {
		apm->pi1 += apm->term;
		apm->n += 2;
		apm->sign = -apm->sign;
		apm->term = apm->sign / apm->n;
		++apm->count1;
	}
	apm->pi1 *= 4;
	return(apm);
}