#include "../include/fadder.hpp"

void run(bool a, bool b, bool cin) {
  sc_signal<bool> signal_a;
  sc_signal<bool> signal_b;
  sc_signal<bool> signal_cin;
  sc_signal<bool> signal_s;
  sc_signal<bool> signal_cout;
  
  signal_a.write(a);
  signal_b.write(b);
  signal_cin.write(cin);

  FULL_ADDER full_adder("full_adder");

  full_adder.a(signal_a);
  full_adder.b(signal_b);
  full_adder.cin(signal_cin);
  full_adder.s(signal_s);
  full_adder.cout(signal_cout);

  sc_start();

  std::cout << std::boolalpha << signal_s.read() << " " << signal_cout.read() << std::endl;
}

int sc_main(int argc, char* argv[]) {
  if(argc != 4) {
    std::cout << "USAGE: ./out <a> <b> <cin>" << std::endl;
    return 1;
  }

  int a = 0;
  int b = 0;
  int c = 0;

  a = std::stoi(argv[1]);
  b = std::stoi(argv[2]);
  c = std::stoi(argv[3]);

  run(a, b, c);
  return 0;
}
