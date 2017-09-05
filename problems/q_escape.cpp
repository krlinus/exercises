#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Problem statement: change the delimiter in a csv input from
',' to '|'. Allow for fields in quotes. Allow for escaping quotes
by using two quotes. (Use double-quote char, not single)
*/
vector <string> parse(const vector <string> &records) {
    enum Place {OUT, IN} place;
    vector<string> retval;
    place=OUT;
    char last=0;
    const int N=records.size();
    for(int r = 0;r < N;++r) {
        string rec = records[r];
        string out_str;
        const int L=records[r].length();
        for(int i = 0;i < L; ++i) {
            const char c = rec[i];
            if(c != ',' && c != '"') {
                out_str += c;
            } else if (c == ',') {
                if(place == OUT){
                    out_str += '|';
                } else {
                    out_str += c;
                }
            } else if (c == '"') {
                if(place == OUT) {
                    place = IN;
                    if(last == '"'){
                        out_str += '"';
                        rec[i]=0;
                    }
                } else {
                    if(last == '"'){
                        out_str += '"';
                        rec[i]=0;
                    } else {
                      place = OUT;
                    }
                }
            }
            last=rec[i];
        }
        retval.push_back(out_str);
    }
    return retval;
}

int main() {
  string s1="abc,\"def, ghi\",\"jkl \"\"Jackal\"\"";
  string s2="\"\"\"hero\"\", michael\",37,\",456\",long,live";
  cout <<"s1 = " << s1 << endl;
  cout <<"s2 = " << s2 << endl;
  vector<string> vs;
  vs.push_back(s1);
  vs.push_back(s2);

  vector<string> ret=parse(vs);
  for(int i=0;i<ret.size();++i) {
    cout << ret[i] << endl;
  }
  //assert(ret[0] == "abc|def, ghi|jkl \"Jackal\"");
  //assert(ret[1] == "hero michael,37,|456,long,live
  return 0;
}

