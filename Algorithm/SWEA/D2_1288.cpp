////https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18_yw6I9MCFAZN&categoryId=AV18_yw6I9MCFAZN&categoryType=CODE
//
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
//int check[10];
//int chk;
//
//void go(int n, int cnt){
//    int tmp = n;
//    while(tmp){
//        int mod = tmp % 10;
//        check[mod] = 1;
//        chk++;
//        tmp /= 10;
//        printf("1");
//    }
//    if(chk == 9){
//        ans = cnt;
//        return;
//    }
//    else {
//        go(n * 2, cnt + 1);
//    }
//}
//
//int main(void) {
//    int t, cnt = 1;
//    scanf("%d", &t);
//
//    while (t--) {
//        int n;
//        scanf("%d", &n);
//        go(n, 0);
//        printf("#%d %d\n", cnt++, ans);
//    }
//    return 0;
//}