#include <stdio.h>
#include <stdlib.h>
#define LENGTH 2*100000

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

int lenght(char *Str)
{
        int a = 0;
        while(a<LENGTH)
        {
                if(Str[a]==0) break;
                a++;
        }
        return a;
}
int valSum(char *Str,int n)
{
        int a = 0;
        int sum = 0;
        while(a<n)
        {
                sum += Str[a];
                a++;
        }
        return sum;
}

int TwoString(char *Str1,char *Str2)
{
        //printf("%s, %s => %d, %d\n", Str1, Str2,lenght(Str1), lenght(Str2));
        int n1 = lenght(Str1);
        int n2 = lenght(Str2);
        //int *p;
        int summation = 0;
        char p[LENGTH];

        //p = (int*)malloc(max(n1,n2)*sizeof(int));
        //printf("\nStr1 = %s\n", Str1);
        //printf("Str2 = %s\n", Str2);

        if((n1!=n2)||(valSum(Str1,n1)!=valSum(Str2,n2)))
        {
                return -1;
        }else{
                
                for(unsigned int aa = 0;aa<n1;aa++) p[aa] = 1; 

                for(unsigned int bb = 0;bb<n1;bb++)
                {
                        for(unsigned int cc = 0;cc<n1;cc++)
                        {
                                if(p[cc]==-1)
                                {                                                
                                        continue;
                                }else{
                                        if(Str1[bb]==Str2[cc]) p[cc] = -1;
                                }
                        }
                }
                for(unsigned int aa = 0;aa<n1;aa++) summation = summation + p[aa];              

                //printf("lll %d, n = %d\n",-summation,n1);
                if(-summation == n1)
                {
                        return 1;                
                }else{
                        return -1; 
                }
        }

        //free(p);
}
/*
void TwoString(char *Str1,char *Str2)
{
        //printf("%s, %s => %d, %d\n", Str1, Str2,lenght(Str1), lenght(Str2));
        int n1 = lenght(Str1);
        int n2 = lenght(Str2);
        //int *p;
        int summation = 0;
        char p[LENGTH];

        //p = (int*)malloc(max(n1,n2)*sizeof(int));
        //printf("\nStr1 = %s\n", Str1);
        //printf("Str2 = %s\n", Str2);

        if((n1!=n2)||(valSum(Str1,n1)!=valSum(Str2,n2)))
        {
                printf("NO\n");
        }else{
                
                for(unsigned int aa = 0;aa<n1;aa++) p[aa] = 1; 

                for(unsigned int bb = 0;bb<n1;bb++)
                {
                        for(unsigned int cc = 0;cc<n1;cc++)
                        {
                                if(p[cc]==-1)
                                {                                                
                                        continue;
                                }else{
                                        if(Str1[bb]==Str2[cc]) p[cc] = -1;
                                }
                        }
                }
                for(unsigned int aa = 0;aa<n1;aa++) summation = summation + p[aa];              

                //printf("lll %d, n = %d\n",-summation,n1);
                if(-summation == n1)
                {
                        printf("YES\n");                
                }else{
                        printf("NO\n"); 
                }
        }

        //free(p);
}
*/

int main()
{
	int num;
        char STRG1[LENGTH];
        char STRG2[LENGTH];

	scanf("%d", &num);

        char **arrayLines = (char**)malloc(2*sizeof(char*));
        int *arrayRES = (int*)malloc(num*sizeof(int));

        for(unsigned int ii = 0;ii<num;ii++)
        {
                //arrayLines[0] = (char*)malloc(LENGTH*sizeof(char*));
                //scanf("%s",*arrayLines);
                scanf("%s %s",STRG1,STRG2);
                //arrayRES[ii] = TwoString(arrayLines[0],arrayLines[1]);
                arrayRES[ii] = TwoString(STRG1,STRG2);
        }

        //for(unsigned int jj = 0;jj<2*num;jj++)
        //{
        //        char *pointer = arrayLines[jj];
        //        printf("\n%s", pointer);
        //}
        //printf("\nDespues de la funcion\n\n");
        
        for(unsigned int ii = 0;ii<num;ii++) (arrayRES[ii] > 0)? printf("YES\n") : printf("NO\n");

        free(arrayLines);
        free(arrayRES);
}
/*
int main()
{
	int num;
        char STRG[LENGTH];

	scanf("%d", &num);

        char **arrayLines = (char**)malloc(2*num*sizeof(char*));

        for(unsigned int ii = 0;ii<2*num;ii++)
        {
                arrayLines[ii] = (char*)malloc(LENGTH*sizeof(char*));
                scanf("%s",arrayLines[ii]);
        }

        
        //for(unsigned int jj = 0;jj<2*num;jj++)
        //{
        //        char *pointer = arrayLines[jj];
        //        printf("\n%s", pointer);
        //}
        //printf("\nDespues de la funcion\n\n");
        

        for(unsigned int ii = 0;ii<num;ii++)
        {
                TwoString(arrayLines[2*(ii)],arrayLines[(2*(ii))+1]);
        }

        free(arrayLines);
}
*/
