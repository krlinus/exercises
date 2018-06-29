
#include <iostream>
#include <vector>
using namespace std;

class RangeSum {
    long l,r;
    long sum;
    public:
    long getSum() { return sum;}
    RangeSum(long l, long r, long sum=0) {
        this->l=l;
        this->r=r;
        this->sum=sum;
    }
     bool apply(const RangeSum &rs, vector<RangeSum> &new_ranges) {
        bool retval=false;

        if((rs.l >= l && rs.l <= r) ||
          (rs.r <= r && rs.r >= l)) {
            if(rs.l==l && rs.r ==r) {
                sum += rs.sum;
                retval=true;
            } else {
                /*
                 ---
                --      // case 1: create 2 ranges
                ---
                 -      // case 2: create 2 ranges
                ---
                  --    // case 3: create 2 ranges
                 ---
                -----   // case 4: create 2 ranges
                ---
                -       // case 5: create 1 range
                ---
                  -     // case 6: create 1 range
                ---
               ----
                ----    // case 7,8: create 1 range
                */
                
                if (rs.l < l && rs.r > l ) {
                    RangeSum leftRange(rs.l, l-1, sum+rs.sum);
                    new_ranges.push_back(leftRange);
                    retval=true;                    
                }
                if (rs.r > r) {
                    RangeSum rightRange(r+1, rs.r, sum+rs.sum);
                    new_ranges.push_back(rightRange);
                    retval=true;
                }
                if(rs.l>l && rs.r<r) {
                    RangeSum leftRange(l,rs.l-1,sum);
                    RangeSum rightRange(rs.r+1,r,sum);
                    l=rs.l;
                    r=rs.r;
                    sum += rs.sum;
                    new_ranges.push_back(leftRange);
                    new_ranges.push_back(rightRange);
                    retval=true;
                }
            }
            
            
        }
        return retval;
    }
    
};

int main() {
    long SZ=0, n_ranges=0;
    cin >> SZ >> n_ranges;
    RangeSum rs(0,SZ,0);
    vector<RangeSum> rsv;
    rsv.push_back(rs);
    while(n_ranges--) {
        int l, r, s;
        cin >> l >> r >> s;
        RangeSum rs(l,r,s);
        for(int i=0;i<rsv.size();++i) {
            if(rsv[i].apply(rs,rsv)) {
                break;
            }
        }
    }
    int max = rsv[0].getSum();
    for(int i=0;i<rsv.size();++i) {
        if (rsv[i].getSum() > max) max = rsv[i].getSum();
    }
    cout << max << endl;
    return 0;
}
