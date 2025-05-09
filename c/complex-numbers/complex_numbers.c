#include "complex_numbers.h"
#include <math.h>
#include <stdlib.h>

complex_t c_add(complex_t a, complex_t b)
{
 
   complex_t add_complex = {
      a.real + b.real,
      a.imag + b.imag
   };
   return add_complex;
}

complex_t c_sub(complex_t a, complex_t b)
{
 
   complex_t sub_complex = {
      a.real - b.real,
      a.imag - b.imag
   };
   return sub_complex;
}

complex_t c_mul(complex_t a, complex_t b)
{
  
   complex_t mul_complex = {
      a.real * b.real - a.imag * b.imag,
      a.real * b.imag + a.imag * b.real
   };
   return mul_complex;
}

complex_t c_div(complex_t a, complex_t b)
{
   
   double denominator = b.real * b.real + b.imag * b.imag;
   complex_t div_complex = {
      (a.real * b.real + a.imag * b.imag) / denominator,
      (a.imag * b.real - a.real * b.imag) / denominator
   };
   return div_complex;
}

double c_abs(complex_t x)
{
   
   return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t c_conjugate(complex_t x)
{
  
   complex_t conjugate_complex = {
      x.real,
      -x.imag
   };
   return conjugate_complex;  
}

double c_real(complex_t x)
{
  
   return x.real;
}

double c_imag(complex_t x)
{
 
   return x.imag;
}

complex_t c_exp(complex_t x)
{
   
   complex_t exp_complex = {
      exp(x.real) * cos(x.imag),
      exp(x.real) * sin(x.imag)
   };
   return exp_complex;
}
