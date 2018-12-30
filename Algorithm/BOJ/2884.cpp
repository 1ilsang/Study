//https://www.acmicpc.net/problem/2884
//http://1ilsang.blog.me/221430471148

#include <cstdio>

int main(void) {
    int h, m, flag = 0;
    scanf("%d %d", &h, &m);
    if (m - 45 < 0) {
        m = 60 + (m - 45);
        flag = 1;
    } else m -= 45;
    if (flag == 1 && h == 0) h = 23;
    else if (flag == 1) h -= 1;
    printf("%d %d\n", h, m);
    return 0;
}
