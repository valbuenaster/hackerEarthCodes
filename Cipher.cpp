#include <iostream>
#include <string>

#define SIZE_NUM 10
#define SIZE_ALPHA 26

#define OFFSET_NUM 48
#define OFFSET_UCALPHA 65
#define OFFSET_LCALPHA 97


using namespace std;

const char array_ALPHA[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const char array_alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const char array_nums[] = {'0','1','2','3','4','5','6','7','8','9'};

char encryptnum(char letter,int degree)
{
        int original_ind = letter - OFFSET_NUM;
        int modulus = (original_ind + degree)%SIZE_NUM;
        return array_nums[modulus];
}

char encryptUC(char letter,int degree)
{
        int original_ind = letter - OFFSET_UCALPHA;
        int modulus =(original_ind + degree)%SIZE_ALPHA;
        return array_ALPHA[modulus];
}

char encryptlc(char letter,int degree)
{
        int original_ind = letter - OFFSET_LCALPHA;
        int modulus =(original_ind + degree)%SIZE_ALPHA;
        return array_alpha[modulus];
}

int main()
{
        int N;
        int n;
        char temp;
        char coded_temp;
        int grade;
        string Str;
        string coded_Str;

        cin >> Str;
        cin >> N;

        n = Str.length();

        //cout<<Str<<endl;
        //cout<<N<<endl;

        for(int ii = 0;ii<n;ii++)
        {
                temp = Str[ii];
                grade = 3;

                //uppercase
                if((temp>=65)&&(temp<=90)) grade = 1;

                //lowercase
                if((temp>=97)&&(temp<=122)) grade = 0;

                //numbers
                if((temp>=48)&&(temp<=57)) grade = 2;


                switch(grade)
                {
                        case 0:
                                coded_temp = encryptlc(temp,N);
                                coded_Str.push_back(coded_temp);
                                break;
                        case 1:
                                coded_temp = encryptUC(temp,N);
                                coded_Str.push_back(coded_temp);
                                break;
                        case 2:
                                coded_temp = encryptnum(temp,N);
                                coded_Str.push_back(coded_temp);
                                break;
                        case 3:
                                coded_Str.push_back(temp);
                                break;
                }

        }
        cout <<coded_Str<<endl;
}
