#include <stdio.h>

int main()
{
    int N;
    unsigned int ii = 3;
    char bool_flag = 0;

    //for(unsigned char ii = 97;ii<=122;ii++) printf("'%c',",ii);
    
    scanf("%d",&N);

    printf("2 ");
    
    while(ii <= N)
    {
        for(unsigned int jj = 3;jj < ii; jj = jj+1)
        {
            if( ii%jj == 0 )
            {
                bool_flag = 1;
                break;
            }
        }
        if(bool_flag == 0)
        {
            printf("%d, ",ii);
        }
        
        ii +=2;
        bool_flag = 0;
    }
}
