//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13_BWKACUCFAYh&categoryId=AV13_BWKACUCFAYh&categoryType=CODE
//http://1ilsang.blog.me/221317170348

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void){
    for(int tcase = 1; tcase < 11; tcase++){
        int sumMap[100][100];
        int tmp, maxRow = 0, maxCol = 0, maxDia = 0, ans;
        int tmpRow = 0, tmpCol = 0, tmpDia = 0, tmpDia2 = 0;
        scanf("%d", &tmp);
        for(int i = 0; i< 100; i++){
            for(int j = 0; j<100; j++){
	            scanf("%d", &sumMap[i][j]);
            }
        }
        for(int i = 0; i < 100; i++){
            tmpDia += sumMap[i][i];
            tmpDia2 += sumMap[99-i][99-i];
            for(int j = 0; j < 100; j++){
                tmpRow += sumMap[i][j];
                tmpCol += sumMap[j][i];
            }
            if(maxRow < tmpRow){
                maxRow = tmpRow;
            }
            if(maxCol < tmpCol){
                maxCol = tmpCol;
            }
            tmpRow = 0;
            tmpCol = 0;
        }
        ans = max(tmpDia, max(tmpDia2, max(maxRow, maxCol)));
        printf("#%d %d\n", tcase, ans);
    }
    return 0;
}
