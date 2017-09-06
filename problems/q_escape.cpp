#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
/*
Problem statement: change the delimiter in a csv input from
',' to '|'. Allow for fields in quotes. Allow for escaping quotes
by using two quotes. (Use double-quote char, not single)
*/
vector <string> parse(const vector <string> &records) {
    enum Place {OUT, IN, Q} place;
    vector<string> retval;
    const int N=records.size();
    for(int r = 0;r < N;++r) {
        place=OUT;
        char last=0;
        string rec = records[r];
        string out_str;
        const int L=records[r].length();
        for(int i = 0;i < L; ++i) {
            const char c = rec[i];
            cerr << 1 << ": c = " << c << endl;
            
            if(c != ',' && c != '"') {
                out_str += c;
                cerr << 1.1 << endl;
                if(place==Q) {
                  place=OUT;
                  cerr << "1.1.1" << endl;
                }
            } else if (c == ',') {
                cerr << 1.2 << endl;
                if(place == OUT || place == Q){
                    out_str += '|';
                    place = OUT;
                    cerr << "1.2.1" << endl;
                } else if (place == IN) {
                    out_str += c;
                    cerr << "1.2.2" << endl;
                }
            } else if (c == '"') {
                cerr << "1.3" << endl;
                if(place == OUT) {
                    place = IN;
                    rec[i]=0;
                    cerr << "1.3.1" << endl;
                } else if (place == IN) {
                    cerr << "1.3.2" << endl;
                    if(last == '"'){
                        out_str += '"';
                        rec[i]=0;
                        cerr << "1.3.2.1" << endl;
                    } else {
                      place = Q;
                      cerr << "1.3.2.2" << endl;
                    }
                } else {
                  cerr << "1.3.3" << endl;
                  place = IN;
                  rec[i] = 0;
                  out_str += '"';
                }
            }
            last=rec[i];
            cerr << out_str << endl;
        }
        retval.push_back(out_str);
    }
    return retval;
}

int main() {
  string s1="abc,\"def, ghi\",\"jkl \"\"Jackal\"\"";
  string s2="\"\"\"hero\"\", michael\",37,\",456\",long,live";
  string s3="abc,\"def, ghi\",\"\"\"\",\"jkl \"\"Jackal\"\"";
  cerr <<"s1 = " << s1 << endl;
  cerr <<"s2 = " << s2 << endl;
  cerr <<"s3 = " << s3 << endl;
  vector<string> vs;
  vs.push_back(s1);
  vs.push_back(s2);
  vs.push_back(s3);

  vector<string> ret=parse(vs);
  for(int i=0;i<ret.size();++i) {
    cerr << ret[i] << endl;
  }
  assert(ret[0] == "abc|def, ghi|jkl \"Jackal\"");
  assert(ret[1] == "\"hero\", michael|37|,456|long|live");
  assert(ret[3] == "abc|def, ghi|\"|jkl \"Jackal\"");
  return 0;
}

