//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15OZ4qAPICFAYD&categoryId=AV15OZ4qAPICFAYD&categoryType=CODE


//틀렸음. 다시 풀어야 함.
//#include <istream>
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <utility>
//#include <math.h>
//
//using namespace std;
//pair<int, int> home, work;
//vector<pair<int, int>> v;
//
//int ans;
//int check[12];
//
//void go(int now, int cnt) {
//    check[now] = 1;
//    int minDistance = 1000, distance, nextEdge;
//    printf("now = %d, cnt = %d, ans = %d\n", now,cnt,ans);
//
//    if(cnt == 0) {
//        ans += abs(v[now].first - v[1].first) +
//                   abs(v[now].second - v[1].second);
//    }else {
//        for (int i = 2; i < v.size() + 2; ++i) {
//            if (check[i] == 0) {
//                distance = abs(v[now].first - v[i].first) +
//                           abs(v[now].second - v[i].second);
//                if (minDistance > distance) {
//                    minDistance = distance;
//                    nextEdge = i;
//                }
//            }
//        }
//        ans += minDistance;
//        go(nextEdge, cnt - 1);
//    }
//}
//
//int main(void) {
//    int t, cnt = 1;
//    scanf("%d", &t);
//
//    while (t--) {
//        int n, x, y;
//        scanf("%d", &n);
//        v.resize(n + 2);
//
//        for (int i = 0; i < n + 2; i++) {
//            scanf("%d %d", &x, &y);
//            v[i] = make_pair(x, y);
//        }
//        go(0, n);
//
//        printf("#%d %d\n", cnt++, ans);
//        v.clear();
//    }
//    return 0;
//}