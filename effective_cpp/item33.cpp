/*
 * Does function override trample on differing parameters?
 *
 */

struct Base {
  void myfunc() {}
  void myfunc(double d) {}
};

struct Derived : public Base {
  // using Base::myfunc; // ----> This makes it "work"
  void myfunc() {}
};

int main() {
  Derived d;
  d.myfunc(1.0);
  return 0;
}

/* Compilation results:

item33.cpp: In function ‘int main()’:
item33.cpp:17:15: error: no matching function for call to ‘Derived::myfunc(double)’
   d.myfunc(1.0);
               ^
item33.cpp:17:15: note: candidate is:
item33.cpp:12:8: note: void Derived::myfunc()
   void myfunc() {}
        ^
item33.cpp:12:8: note:   candidate expects 0 arguments, 1 provided

shell returned 1

*/

