#include "section.h"
#include <iostream>
#define mu 105.6583745
#define a 7.2973525698e-3
#define pi 3.14159265
/*double beta1(double s, double s_th){
    	return sqrt(1 - s_th/s);
}

double eta(double s, double s_th){
	return M_PI*a/beta1(s, s_th);
}*/

double born(double s, double * pars){
  	/*if (s > s_th) {
    		return 2*M_PI*M_PI*pow(a,3)*(1 - beta1(s, s_th)*beta1(s, s_th)/3)/(1 - exp(-eta(s, s_th)))/s;
  	}
  	if(s == s_th){
	  	return 2*M_PI*M_PI*pow(a, 3)/s;
  	}*/
  	return (20*pi/s)*pars[2]*pars[3]*pow(pars[0]*pars[1], 2)/
		( pow( s - pars[0]*pars[0], 2) + s*pow(pars[1], 2))*pow(s/pars[0]/pars[0], 3);	
;
}
