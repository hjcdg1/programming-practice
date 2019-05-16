#include <stdio.h>
#include <stdlib.h>
#define R 10000
#define MAX_N 5001

int N;
int xs[MAX_N * 2 + 3][4];
int ys[MAX_N * 2 + 3][4];
int xs_len = 0, ys_len = 0;

int xbuf[R * 2 + 3];
int ybuf[R * 2 + 3];

int comp(const void * a, const void * b)
{
   int *aa, *bb;
   aa = (int *)a;
   bb = (int *)b;

   if (aa[0] > bb[0])
      return 1;
   if (aa[0] < bb[0])
      return -1;
   return bb[3] - aa[3];
}


int main() {
   int x1, x2, y1, y2;
   int len = 0;
   
   /* input */
   scanf("%d", &N);
   for (int i = 0; i < N; i++) {
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      
      if (x1 > x2) {
         int temp = x1;
         x1 = x2;
         x2 = temp;
      }
      if (y1 > y2) {
         int temp = y1;
         y1 = y2;
         y2 = temp;
      }

      /* x */
      xs[xs_len][0] = y1;
      xs[xs_len][1] = x1;
      xs[xs_len][2] = x2;
      xs[xs_len++][3] = 1;   // open

      xs[xs_len][0] = y2;
      xs[xs_len][1] = x1;
      xs[xs_len][2] = x2;
      xs[xs_len++][3] = -1;  // close
    
      /* y */
      ys[ys_len][0] = x1;
      ys[ys_len][1] = y1;
      ys[ys_len][2] = y2;
      ys[ys_len++][3] = 1;   // open
      ys[ys_len][0] = x2;
      ys[ys_len][1] = y1;
      ys[ys_len][2] = y2;
      ys[ys_len++][3] = -1;  // close
   }

   /* sort */
   qsort(xs, xs_len, sizeof(int[4]), comp);
   qsort(ys, ys_len, sizeof(int[4]), comp);

   /* count x */
   for (int i = 0; i < xs_len; i++){
      for (int j  = xs[i][1]; j < xs[i][2]; j++){
         xbuf[j + R] += xs[i][3];
         if (xbuf[j + R] == 0)
            len++;
         else if (xbuf[j + R] == 1 && xs[i][3] == 1)
            len++;
      }
   }

   /* count y */
   for (int i = 0; i < ys_len; i++) {
      for (int j = ys[i][1]; j < ys[i][2]; j++) {
         ybuf[j + R] += ys[i][3];
         if (ybuf[j + R] == 0)
            len++;
         else if (ybuf[j + R] == 1 && ys[i][3] == 1)
            len++;
      }
   }
   // return
   printf("%d\n", len);
   return 0;
}
