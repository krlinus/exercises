#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int getpos(const vector<int> &inp, int tgt) {
    const int N = inp.size();
    for(int i=0;i<N;++i) {
        cerr << "inpi=" << inp[i] << endl;
        if(tgt >= inp[i]) {
            return i;
        }
    }
    return N;
}

int main() {
    int scores_count;
    cin >> scores_count;
    vector <int> scores;
    for(int i=0;i<scores_count;++i) {
        int c;
        cin >> c;
        if(!binary_search(scores.begin(), scores.end(), c)) {
            scores.push_back(c);
            cerr << "inserted "<< c << endl;
        }
    }
    cerr << "stored " << scores.size() << endl;
    int alice_scores_count;
    cin >> alice_scores_count;
    //vector <int> alice_scores(alice_scores_count);
    for (int i=0;i<alice_scores_count;++i) {
        int s;
        cin >> s;
        cerr << "searching " << s << endl;
        int pos = getpos(scores, s);
        cout << pos << endl;
    }
    
    
    return 0;
}
