#include <cstdio>
#include "oi.h"

const char *code = "sta";

const int maxn = 200000;

oi::Random RG;

void gen_special(const char* testname, int n)
{
    char filename[30];
    sprintf(filename,"%s%s.in",code,testname);
    FILE* out = fopen(filename,"w");
    fprintf(stderr,"%s...\n",filename);
    int i,j;
    fprintf(out,"%d %d\n",n,3*n*(n+1)/2+2*n);
    for(i=1; i<=n; i++)
    {
      if (i>1) fprintf(out," ");
      fprintf(out,"%d",n+1-i+n);
    }
    fprintf(out,"\n");
    for(i=1; i<=n; i++)
        for(j=i; j<=n; j++)
            fprintf(out,"MAX\n%d %d\n",i,j);
    for(i=1; i<=n; i++)
        fprintf(out,"UPDATE\n%d %d\n",i,(i==n/3)*n + n);
    for(i=1; i<=n; i++)
        for(j=i; j<=n; j++)
            fprintf(out,"MAX\n%d %d\n",i,j);
    for(i=1; i<=n; i++)
        fprintf(out,"UPDATE\n%d %d\n",i,2*i);
    for(i=1; i<=n; i++)
        for(j=i; j<=n; j++)
            fprintf(out,"MAX\n%d %d\n",i,j);
    fclose(out);
}

int A[maxn];

void gen_random(const char* testname, int n, int m, int range, int draws)
{
    char filename[30];
    sprintf(filename,"%s%s.in",code,testname);
    FILE* out = fopen(filename,"w");
    fprintf(stderr,"%s...\n",filename);
    fprintf(out,"%d %d\n",n,m);
    for(int i=0; i<n; i++)
    {
        if (i) fprintf(out," ");
        A[i] = RG.rand()%(2*range) - range;
        fprintf(out,"%d",A[i]);
    }
    fprintf(out,"\n");
    for(int i=0; i<m; i++)
        if (RG.rand()%4)
        {
            fprintf(out,"UPDATE\n");
            int x = RG.rand()%n;
    //        fprintf(stderr,"Trying %d [%d].\n",x+1,A[x]);
            if (RG.rand()%3)
                for(int q=0; q<draws-1; q++)
                {
                    int y = RG.rand()%n;
                    if (A[y]>A[x])
                        x = y;
                }
    //        fprintf(stderr,"%d: %d -> ",x+1,A[x]);
            A[x] = RG.rand()%(2*range) - range;
//            fprintf(stderr,"%d\n",A[x]);
            fprintf(out,"%d %d\n",x+1, A[x]);
        }
        else
        {
            fprintf(out,"MAX\n");
            int len = RG.rand()%n;
            int a = RG.rand()%(n-len)+1;
            fprintf(out,"%d %d\n",a,a+len);
        }
    fclose(out);
}

int main()
{
    RG.setSeed(4922);
    gen_random("1",10,50,100,1);
    gen_random("2a",31,1000,1000,20);
    gen_random("2b",32,1000,1000,20);
    gen_random("2c",33,1000,1000,20);
    gen_special("3",200);
    gen_random("4a",5000,20000,1000000,60);
    gen_random("4b",5000,20000,1000000,300);
    gen_random("5a",131071,200000,1000000,10);
    gen_random("5b",131073,200000,1000000,10);
    gen_random("5c",200000,200000,1000000,10);
    return 0;
}
