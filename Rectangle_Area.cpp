#include <iostream>
#include <vector>
#include <map>
using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int area1 = abs(ay2 - ay1)*abs(ax2 - ax1);

    int area2 = abs(by1 - by2)*abs(bx2 - bx1);


    int ans = area1 + area2;

    int reduce = 0;

    multimap <int, int> ystore = {{ay1, 1}, {ay2, 1}, {by1, 2}, {by2, 2}};
    multimap <int, int> xstore = {{ax1, 1}, {ax2, 1}, {bx1, 2}, {bx2, 2}};

    auto ity = ystore.begin();
    auto itx = xstore.begin();

    if ((*ity).second != (*(++ystore.begin())).second && (*itx).second != (*(++xstore.begin())).second){
        ++ity;
        ++itx;
        int y1 = (*ity).first;
        int x1 = (*itx).first;
        ++ity;
        ++itx;
        int y2 = (*ity).first;
        int x2 = (*itx).first;

        reduce = abs(y2 - y1)*abs(x2 - x1);
    }

    return ans - reduce;
}

int main(){
    return 0;
}