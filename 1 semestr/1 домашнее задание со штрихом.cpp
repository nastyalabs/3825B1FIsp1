#include <stdio.h>

int absval(int x) {
    if (x >= 0)
        return x;
    else
        return -x;
}

int main() {
    char k1[3], k2[3], piece[10];
    int x1, y1, x2, y2;
    printf("Vvedite K1 K2 i figuru (king queen rook bishop knight):\n");
    if (scanf_s("%2s %2s %9s", k1, (unsigned)sizeof(k1), k2, (unsigned)sizeof(k2), piece, (unsigned)sizeof(piece)) != 3) {
        printf("Error vvoda");
        return 0;
    }
    x1 = k1[0] - 'a' + 1;
    y1 = k1[1] - '1' + 1;
    x2 = k2[0] - 'a' + 1;
    y2 = k2[1] - '1' + 1;
    int dx = absval(x2 - x1);
    int dy = absval(y2 - y1);
    int k = (dx <= 1 && dy <= 1 && !(dx == 0 && dy == 0));
    int r = (x1 == x2 || y1 == y2);
    int b = (dx == dy);
    int q = (r || b);
    int n = (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    char p = piece[0];  
    int can = 0;
    if (p == 'k') can = k;       
    else if (p == 'q') can = q;  
    else if (p == 'r') can = r;  
    else if (p == 'b') can = b;  
    else if (p == 'n') can = n;  
    else {
        printf("Unknown figura\n");
        return 0;
    }

    if (can) {
        printf("YES\n");
        return 0;
    }

    printf("NO\n");
    printf("Other figures kotorye can walk:\n");

    int any = 0;

    if (k && p != 'k') { printf("king "); any = 1; }
    if (q && p != 'q') { printf("queen "); any = 1; }
    if (r && p != 'r') { printf("rook "); any = 1; }
    if (b && p != 'b') { printf("bishop "); any = 1; }
    if (n && p != 'n') { printf("knight "); any = 1; }

    if (!any) printf("NONE");

    printf("\n");
    return 0;
}
