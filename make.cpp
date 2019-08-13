#include "kw/testlib.hpp"
const int C = 10001;
char a[C], b[C];
int n, l, x, y;
int main(int ngrv, char *ngrc[]) {
    if (ngrv != 2) {
        fprintf(stderr, "Error: The command syntax is not right.\n");
        return 0;
    }
    l = strlen(ngrc[1]);
    if (l >= 5 && (l != 4 || ngrc[1][1] != '0' || ngrc[1][2] != '0' || ngrc[1][3] != '0' || ngrc[1][4] != '0' || ngrc[1][5] != '1')) {
        fprintf(stderr, "Error: Number of data is too big.\n");
        return 0;
    }
    for (int i = 0; i < l; ++i) {
        (n *= 10) += ngrc[1][i] - '0';
    }
    for (int i = 1; i <= n; ++i) {
        x = i;
        y = 0;
        while (x) {
            x /= 10;
            ++y;
        }
        memset(a, 0, sizeof(a));
        for (int j = y - 1; ~j; --j) {
            a[j] = x % 10 + '0';
            x /= 10;
        }
        freopen("data.in", "w", stdout);
        printf("%d\n", i);
        fclose(stdout);
        memset(b, 0, sizeof(b));
        sprintf(b, "data < data.in > data%s.in", a);
        system(b);
        memset(b, 0, sizeof(b));
        sprintf(b, "std < data%s.in > data%s.ans", a, a);
        system(b);
        fprintf(stderr, "Message: No.%s data is OK!\n", a);
    }
    system("rm -rf data.in");
    system("rm -rf std.exe");
    system("rm -rf data.exe");
    return 0;
}