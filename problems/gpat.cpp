#include <map>
using namespace std;

/*
18. find the number of discrete patterns of 1's in a grid. Assume each cell can be either 0 or 1
Contiguous cells are up-down and left-right.
*/

int patCount(int **grid, int nRows, int nCols) {
    struct Range {
        int start, end;
        static int nextId;
        int id;
        Range(int s, int e) start(s), end(e) {
            id = nextId;
            nextId++;
        }
        set(int s, int e) {
            start=s; end = e;
        }
    };
    Range::nextId=1;
    for(int i=0;i<nRows;i++) {
        bool start=-1;
        for(int j=0;i<nCols;j++) {
            if(grid[i][j]) {
                if(start == -1) {
                    start=j;
                }
                if(j==nCols-1) {
                    Range r(start, start);
                    rvect.push_back(r);
                }
            } else {
                if(start != -1) {
                    int end=j;
                }
                Range r(start, end);
                rvect.push_back(r);
            }

        }
    }

}

int main() {
    int arr1[][] = {
        {0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1}
    };
    int c = patCount(arr1, 7, 6);
    print("Expected: %d, got: %d\n", 5, c);
    return 0;
}
