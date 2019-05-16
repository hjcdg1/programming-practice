#include <stdio.h>

int arr[200][2];
int tmp[200][2];

int merg(int a, int an, int b, int bn) {
    int i,j;
    int cn = 0;
    int atop = 0;
    int btop = 0;
    int last = -1;
    int mx;
    for(i=j=0; i<an || j<bn;) {
        if(j==bn || (arr[a+i][0]<=arr[b+j][0] && i<an)) {
            atop = arr[a+i][1];
            mx = atop>btop?atop:btop;
            if(last==-1 || last!=mx) {
                tmp[cn][0] = arr[a+i][0];
                tmp[cn][1] = mx;
                cn++;
                last = mx;
            }
            i++;
        }
        if(i==an || (arr[a+i][0]>=arr[b+j][0] && j<bn)) {
            btop = arr[b+j][1];
            mx = atop>btop?atop:btop;
            if(last==-1 || last!=mx) {
                tmp[cn][0] = arr[b+j][0];
                tmp[cn][1] = mx;
                cn++;
                last = mx;
            }
            j++;
        }
    }
    for(i=0; i<cn; i++) {
        arr[a+i][0] = tmp[i][0];
        arr[a+i][1] = tmp[i][1];
    }
    return cn;
}

int sky(int s, int e) {
    if(e-s<3)
        return 2;
    int m = (s+e)/2/2*2;
    return merg(s, sky(s,m), m, sky(m,e));
}

int main() {
    int n,x,y,z;
    int i, cn;
    scanf("%d", &n);
    for(i=0; i<2*n; i+=2){
        scanf("%d %d %d", &x, &y, &z);
        arr[i][0] = x;
        arr[i][1] = z;
        arr[i+1][0] = y;
        arr[i+1][1] = 0;
    }
    cn = sky(0,2*n);
    for(i=0; i<cn; i++)
        printf("%d %d\n", arr[i][0], arr[i][1]);
}

