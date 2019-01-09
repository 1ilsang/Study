//https://www.acmicpc.net/problem/9613

#include <cstdio>

int gcd(int a, int b) {
    if(a < b) int tmp = a, a = b, b = tmp;
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        long long ans = 0;
        int arr[102];
        scanf("%d", &n);
        for(int i = 0 ; i < n; i++) scanf("%d", &arr[i]);
        for(int i = 0; i < n - 1; i++) for(int j = i + 1; j < n; j++) ans += gcd(arr[i], arr[j]);
        printf("%lld\n", ans);
    }
    return 0;
}
