#include <vector>
#include <deque>
#include <string>

using namespace std;
typedef unsigned char Byte;
typedef vector<Byte> Bytestream;


template <class... Ts> struct my_tuple {};

template <class T, class... Ts>
struct my_tuple<T, Ts...> : my_tuple<Ts...> {
  my_tuple() {}
  my_tuple(T t, Ts... ts) : my_tuple<Ts...>(ts...), tail(t) {}

  T tail;
  
  vector<Bytestream> fields;
 /* 
  vector<Byte> make_bytestream(string s) {
   vector<Byte> retval;
   const int SZ = s.size();
   for(int i=0;i<SZ;++i) {
     retval.push_back(s[i]);
   }
   fields.push_back(retval);
   return retval;
  }
  */
  template<T>
  vector<Byte> make_bytestream(T l) {
   
   vector<Byte> retval;
   deque<Byte> dq;
   while(l) {
     dq.push_front((l % 10) + '0');
     l /= 10;
   }
   const size_t SZ = dq.size();
   if(SZ == 0) {
     retval.push_back('0');
   }
   for(int i=0; i < SZ; ++i) {
     retval.push_back(dq[i] );
   }
 
   fields.push_back(retval);
   return retval;
  }
  vector<Byte> make_bytestream(T t, Ts... ts) {
    return make_bytestream(t) + make_bytestream(ts...);
  }
  /*
  template<int>
  vector<Byte> make_bytestream(int l) {
   
   vector<Byte> retval;
   deque<Byte> dq;
   while(l) {
     dq.push_front((l % 10) + '0');
     l /= 10;
   }
   const size_t SZ = dq.size();
   if(SZ == 0) {
     retval.push_back('0');
   }
   for(int i=0; i < SZ; ++i) {
     retval.push_back(dq[i] );
   }
 
   fields.push_back(retval);
   return retval;
  }
  */
};

int main() {
  my_tuple<int, long> t(1,10L);
  t.make_bytestream(1,10L);
  return 0;
}
