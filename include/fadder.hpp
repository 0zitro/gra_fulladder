#ifndef ADDER_HPP
#define ADDER_HPP

#include <systemc>
// #include <systemc.h>
using namespace sc_core;

SC_MODULE(HALF_ADDER) {

  sc_in<bool> a{"a"}, b{"b"};
  sc_out<bool> s{"s"}, c{"c"};

  // --TODO: Add the necessary definitions to define the module.
  //       The module should have two input ports `a` and `b`,
  //       and two output ports `s` and `c`, all of boolean type.
  //       The output `s` should hold the LSB of the sum of `a` and `b`,
  //       and the output `c` should hold the carry bit of the sum.

  void operate() {
    bool a_ = a.read();
    bool b_ = b.read();

    s.write(a_ ^ b_);
    c.write(a_ && b_);
  }

  SC_CTOR(HALF_ADDER) {
    SC_METHOD(operate);
    sensitive << a << b;
  }
};


SC_MODULE(FULL_ADDER) {
  
  sc_in<bool> a{"a"}, b{"b"}, cin{"cin"};
  sc_out<bool> s{"s"}, cout{"cout"};

  HALF_ADDER half1{"half1"}, half2{"half2"};

  //--TODO: Use 2 HALF_ADDERS to define a full adder.
  //      You may use additional signals if necessary.
  //      The module should have three input ports `a`, `b`, and `cin`,
  //      and two output ports `s` and `cout`, all of boolean type.
  //      The output `s` should hold the LSB of the sum of `a`, `b`, and `cin`,
  //      and the output `cout` should hold the carry bit of the sum.

  void operate() {
    s.write(half2.s.read());
    cout.write(half1.c.read() || half2.c.read());
  }

  SC_CTOR(FULL_ADDER) {
    half1.a(a);
    half1.b(b);

    half1.a(cin);
    half2.b(half1.s);

    SC_METHOD(operate);

    sensitive << a << b << cin;
  }
};
#endif