//https://www.acmicpc.net/problem/1561
//http://1ilsang.blog.me/221434066332

#include <cstdio>

typedef long long ll;

const ll MAX_T = 60000000000;

int n, m;
int arr[10001];

int main(void){
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < m; i++) scanf("%d", &arr[i]);

    if(n <= m) {
        printf("%d\n", n);
        return 0;
    }

    ll l, r, t, cnt;
    l = t = 0;
    r = MAX_T;

    while(l <= r) {
        ll mid = (l + r) >> 1;
        cnt = m;
        for(int i = 0; i < m; i++) cnt += mid / arr[i];
        if(cnt >= n) t = mid, r = mid - 1;
        else l = mid + 1;
    }

    cnt = m;
    for(int i = 0; i < m; i++) cnt += (t - 1) / arr[i];
    for(int i = 0; i <= m; i++) {
        if(t % arr[i] == 0) cnt++;
        if(cnt == n) {
            printf("%d\n", i + 1);
            break;
        }
    }

    return 0;
}

