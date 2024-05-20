#ifndef ADDER_HPP
#define ADDER_HPP

#include <systemc>
#include <systemc.h>
using namespace sc_core;

SC_MODULE(HALF_ADDER) {

  sc_in<bool> a, b;
  sc_out<bool> s, c;

  // TODO: Add the necessary definitions to define the module.
  //       The module should have two input ports `a` and `b`,
  //       and two output ports `s` and `c`, all of boolean type.
  //       The output `s` should hold the LSB of the sum of `a` and `b`,
  //       and the output `c` should hold the carry bit of the sum.
};


SC_MODULE(FULL_ADDER) {
  
  sc_in<bool> a, b, cin;
  sc_out<bool> s, cout;

  HALF_ADDER half1, half2;

  //TODO: Use 2 HALF_ADDERS to define a full adder.
  //      You may use additional signals if necessary.
  //      The module should have three input ports `a`, `b`, and `cin`,
  //      and two output ports `s` and `cout`, all of boolean type.
  //      The output `s` should hold the LSB of the sum of `a`, `b`, and `cin`,
  //      and the output `cout` should hold the carry bit of the sum.

};
#endif