#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include<limits.h>

long long Solve (long long k, int* arr, int n ) 
{
   // Write code here
   int m_max = 0;
   int index_max = 0;
   int diff = 0;
   int sum_diff = 0;
   int mm_max = 0;

   int  mod_index = 0;

   long long Cost = 0;
/*   
   long long *aux_Array = (long long*)malloc((k+1)*sizeof(long long));

   for(long long aa = 0;aa<k+1;aa++)
   {
           aux_Array[aa] = aa - k;
   }
*/   
   for(unsigned int ii = 0;ii<n;ii=ii+1)
   {
           if(arr[ii]<= 0)continue;
           
           m_max = arr[ii];
           index_max = ii;
           
           sum_diff = 0;
           mm_max = m_max;
           for(long long ll = 0; ll<(k+1); ll=ll+1)
           {
               for(int bb = -1;bb<2;bb = bb + 2)
               {
                       mod_index = index_max + bb*(ll-k);
                       if((mod_index < 0)||(mod_index >= n)||(arr[mod_index]> 0)) continue;

                           
                       diff = m_max + arr[mod_index];
                       if(diff<0)
                       {
                            arr[mod_index] = diff;
                            m_max = 0;
                            sum_diff = mm_max;
                            break;
                        }else{
                            m_max = diff;
                            arr[mod_index] = 0;
                            //sum_diff = sum_diff + abs(arr[aux_Array[ll]]);
                            sum_diff = sum_diff -(arr[mod_index]);
                        }
                       if(m_max <= 0) continue;
               } 
               if(m_max <= 0) break;  
           }
           arr[index_max] = m_max;
   }
   //free(aux_Array);
   
   for(unsigned int ff = 0;ff<n;ff=ff+1)
   {
        Cost = Cost + abs(arr[ff]);
   }
   return Cost;
}

int main() {
    long long k;
    
    int n;
    scanf("%d", &n);
    scanf("%lld", &k);
    int i_arr;
    int *arr = (int *)malloc(n*(sizeof(int)));
    for(i_arr=0; i_arr<n; i_arr++)
    	scanf("%d", &arr[i_arr]);

    long long out_ = Solve(k, arr, n);
    printf("%lld\n", out_);
    free(arr);
}
