//https://www.acmicpc.net/problem/1725
//http://1ilsang.blog.me/221412218805

#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
    stack<int> st;
    int ans = 0;
    int n, top;
    int histo[100001];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &histo[i]);

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && histo[st.top()] >= histo[i]) {
            int bot;
            top = st.top();
            st.pop();
            if (st.empty()) bot = i;
            else bot = i - st.top() - 1;

            ans = max(ans, histo[top] * bot);
        }
        st.push(i);
    }

    printf("%d\n", ans);

    return 0;
}
