/* can I write to a set element? */

#include <set>
#include <iostream>
using namespace std;
struct Range {
    mutable int start, end;
    bool operator<(const Range&r) const {
        if(r.start > start) return true;
        if(r.start == start) {
            if(r.end > end) return true;
        }
        return false;
    }
    bool operator==(const Range&r) const {
        return r.start == start && r.end == end;
    }
    Range(int s, int e) : start(s), end(e) {}
    void setVals(int s, int e) const { start = s; end = e; }
};

int main() {
    set<Range> sr;
    int s, e;
    s = e = -1;
    cin >> s >> e;
    while(s>0 && e>0) {
        Range r1(s,e);
        set<Range>::iterator srIter = find(sr.begin(), sr.end(), r1);
        if(srIter != sr.end()) {
            cout << "Found " << s << ", " << e << endl;;
            srIter->setVals(srIter->start+2, srIter->end+2);
        } else {
            sr.insert(r1);
        }
        cin >> s >> e;
    }
    for(set<Range>::iterator srIter=sr.begin(); srIter != sr.end(); srIter++) {
        cout << "Range: " << srIter->start << ", " << srIter->end << endl;
    }
    return 0;
}


