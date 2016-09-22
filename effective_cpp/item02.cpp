/* 
class GamePlayer {
 private:
  static const int NumTurns = 5;
  int scores[NumTurns];
  ...
};
// constant declaration
// // use of constant
// What you see above is a declaration for NumTurns , not a definition.
// Usually, C++ requires that you provide a definition for anything you
// use, but class-specific constants that are static and of integral type
// (e.g., integers, char s, bool s) are an exception. As long as you don’t take
// their address, you can declare them and use them without providing a
// definition.
//
*/


#include <iostream>

class GamePlayer {
  static const int NumTurns = 5;
 public:
  void print_NumTurns_address() {
// Case 1: Take the address of static const member.
//
    //std::cout << &NumTurns << std::endl;
    // Results in below error:
    // /tmp/cckWSmlf.o: In function `GamePlayer::print_NumTurns_address()':
    // item02.cpp:(.text._ZN10GamePlayer22print_NumTurns_addressEv[_ZN10GamePlayer22print_NumTurns_addressEv]+0xd):
    // undefined reference to `GamePlayer::NumTurns'
    // collect2: error: ld returned 1 exit status
    // std::cout << "NumTurns = " << NumTurns << std::endl;
    //
    // Case 2:
    std::cout << &NumTurns << std::endl;

  }
};
// Case 2: If you do take the address of a class constant, or if your
// compiler incorrectly insists on a definition even if you don’t take the
// address, you provide a separate definition like this:
    const int GamePlayer::NumTurns;

int main() {
  GamePlayer gp;
  gp.print_NumTurns_address();
  return 0;
}

