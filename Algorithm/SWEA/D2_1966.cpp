//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PrmyKAWEDFAUq&categoryId=AV5PrmyKAWEDFAUq&categoryType=CODE

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main(void){
    int t, cnt = 1;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i =0; i < n;i++){
            int tmp;
            scanf("%d", &tmp);
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        printf("#%d ", cnt++);
        for(int i =0; i< v.size(); i++){
            printf("%d ", v[i]);
        }puts("");
        v.clear();
    }
    return 0;
}