#include "getCorrections.h"
#include "integration.h"
#include <iostream>
#define me 0.5109989461 

double getCorrections(double E, double * pars) {
	double xm = 1.e-8;
	double xmax = 1 - 4. * me * me / E /E;
	std::function<double(double)> fcn = [E, pars] (double x) {
		double tx = born(E * E * (1-x), pars) * radiator(x, E * E);
      		return tx;
  	};
	double abserr = 0;
	double result;
	if (xm < xmax) {
		result = sIntegral(&fcn, 0, xm, &abserr);
		result += Integral(&fcn, xm, xmax, &abserr);
	} else {
		result = sIntegral(&fcn, 0, xmax, &abserr);
	}
	return result;
}
