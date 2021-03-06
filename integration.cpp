
#include <iostream>
#include "integration.h"

double wrapper(double x, void* p) {
    auto fc = reinterpret_cast<std::function<double(double)> *>(p);
    return (*fc)(x);
}

double sIntegral(std::function<double(double)>* fcn,
                 double a, double b, double* error) {
    int N = 100000;
  gsl_error_handler_t * old_handler =
      gsl_set_error_handler_off();
  gsl_integration_workspace* w =
      gsl_integration_workspace_alloc(N);
  gsl_function F;
  F.function = &wrapper;
  F.params = fcn;
  double result;
  double relerr = 1.0e-15;
  int status = 1;
  while (status) {
    
    status = gsl_integration_qags(&F, a, b, 0.,
                                  relerr, N,
                                  w, &result,
                                  error);

    
    if (relerr < 1.e-3) {
      relerr *= 10;
    } else {
      relerr *= 1.1;
      if (status) {
        std::cout <<
            "AS: Warning: tolerance increased to " <<
            relerr << std::endl;
      }
    }
    

  }
  
  gsl_integration_workspace_free(w);
  gsl_set_error_handler(old_handler);
  
  return result;
}

double Integral(std::function<double(double)>* fcn,
                double a, double b, double* error) {
  int N = 1000000;
  gsl_error_handler_t * old_handler =
      gsl_set_error_handler_off();
  gsl_integration_workspace* w =
    gsl_integration_workspace_alloc(N);
  gsl_function F;
  F.function = &wrapper;
  F.params = fcn;
  double result;
  double relerr = 1.0e-15;
  int status = 1;
  while (status) {
    
    status = gsl_integration_qag(&F, a, b, 0.,
                                 relerr, N, 6,
                                 w, &result,
                                 error);

    
    if (relerr < 1.e-3) {
      relerr *= 10;
    } else {
      relerr *= 1.1;
      if (status) {
	std::cout <<
            "A: Warning: tolerance increased to "
		  << relerr << std::endl;
      }
    }

  }
  
  gsl_integration_workspace_free(w);
  gsl_set_error_handler(old_handler);
  
  return result;
}



