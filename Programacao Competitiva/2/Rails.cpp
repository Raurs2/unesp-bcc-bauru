#include <bits/stdc++.h>

using namespace std;

int N, num, i, aux = 0;
stack<int> trem;

int main() {
    scanf("%d", &N);
    while (N != 0) {
        num = 1;
        while (num) {
            for (i = 0; i < N; i++) {
                aux = 0;
                scanf("%d", &num);
                if (num == 0) {
                    break;
                } else {
                    trem.push(num);
                }
            }
            if (!trem.empty()) {
                if (trem.top() == N) {
                    for (i = N; i > 0; i--) {
                        if (trem.top() == i) {
                            trem.pop();
                            aux++;
                        } else {
                            printf("No\n");
                            break;
                        }    
                    }
                } else if (trem.top() == 1) {
                    for (i = 1; i < N; i++) {
                        if (trem.top() == i) {
                            trem.pop();
                            aux++;
                        } else {
                            printf("No\n");
                            break;
                        }
                    }
                } else {
                    printf("No\n");
                }
                if (aux == N) {
                    printf("Yes\n");
                }
                while (!trem.empty()) {
                    trem.pop();
                }
            }
        }
        printf("\n");
        scanf("%d", &N);
    }
    return 0;
}