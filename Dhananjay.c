#include <stdlib.h>
#include <stdio.h>

#define STR_DATA 500 

const char ARRAY_PRIMES[] = {2, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
#define N_VALUES 13

void dhananjay(char *str_i, int ss, char *str_o)
{
        //printf("Array to treat \n%s\n",str_i); 
        int min_com;
        int temp = 0;

        for(int ii = 0; ii<ss;ii++)
        {
                min_com = 1000;
                //printf("\nCHARACTER = %c, %d", str_i[ii], str_i[ii]);

                for(char jj = N_VALUES-1;jj>=0;jj--)
                {
                        temp = abs(str_i[ii] - ARRAY_PRIMES[jj]);
                        //printf("\n%d, temp  = %d", jj,temp);
                        if(temp <= min_com)
                        {
                                min_com = temp;
                        }else{
                                str_o[ii] = ARRAY_PRIMES[jj+1];
                                //printf("\nstr_o[ii] = %d\n", str_o[ii]);
                                break;       
                        }
                        if(jj==0) str_o[ii] = ARRAY_PRIMES[1];
                }
                printf("%c",str_o[ii]);
        }
        printf("\n");
}

int main()
{
        int N;
        int n;
        int *p_sizes;
        char **array_Str;
        char str[500];
        char strR[500];

        scanf("%d",&N);

        p_sizes = (unsigned int*)malloc(N*sizeof(unsigned int));
        array_Str = (char**)malloc(N*sizeof(char*));

        for(char ii = 0;ii<N;ii++)
        {
                scanf("%d", &n);
                p_sizes[ii] = n;
                array_Str[ii] = (char*)malloc(n*sizeof(char));

                scanf("%s",array_Str[ii]);        
        }


        for(char jj = 0;jj<N;jj++)
        {
                dhananjay(array_Str[jj],p_sizes[jj],strR);  
                
                //printf("\nn = %d, s = %s",p_sizes[jj],array_Str[jj]);
                //for(char kk=0;kk<p_sizes[jj];kk++) printf("%c",strR[kk]);
                //printf("\n");   
        }

        //for(char kk=0;kk<n;kk++) printf("%c",strR[kk]);
        //printf("\n");

        free(p_sizes);
        free(array_Str);
}
