#include <vector>
#include <deque>
#include <string>
#include <iostream>

using namespace std;
typedef unsigned char Byte;
typedef vector<Byte> Bytestream;

template <class... Ts> struct my_tuple {};

template <class T, class... Ts>
struct my_tuple<T, Ts...> : my_tuple<Ts...> {
  my_tuple(T t, Ts... ts) : my_tuple<Ts...>(ts...), tail(t) {}

  T tail;
  void dump(const Bytestream & bs){
    for(int i = 0;i<bs.size(); ++i) {
      cout << char(bs[i]);
    }
    cout << endl;
  }

  vector<Byte> make_bytestream(long l) {
    cout << "make_bytestream-l called with " << l << endl;
    Bytestream bs;
    if(l == 0) {
        bs.push_back('0');
    } else {
      while(l) {
        bs.push_back(l%10);
        l /= 10;
      }
      reverse(bs.begin(),bs.end());
    }
    dump(bs);
    return bs;
  }
/*
  vector<Byte> make_bytestream() {
    Bytestream bs = make_bytestream(tail);
    return bs;
  }
*/
  vector<Byte> make_bytestream(T t, Ts... ts) {
    cout << "make_bytestream called with " << t << endl;
    return make_bytestream(t) + make_bytestream(ts...);
  }
};


int main() {
  my_tuple<int, long, const char*> t(1,10L, "Hello");

  Bytestream bs = t.make_bytestream(1, 10L, "abcd");
  t.dump(bs);
  return 0;
}
