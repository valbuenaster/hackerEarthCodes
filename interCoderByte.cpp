#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> string2int(string & Str)
{
  vector<string> retVal;

  //cout << "Str = "<<Str<<endl;
  //cout << "Str.size() = "<<Str.size()<<endl;
  int counter = 0;
  int counter0 = 0;
  int integerConv = 0;

  while(counter < Str.size())
  {
    counter = Str.find(',',counter);
    //cout << "counter = " << counter << endl; 
    if(counter == string::npos)
    {
      //cout<< "Se rompio"<<endl;
      break;
    }
    string temp = Str.substr(counter0,counter-counter0);
    counter++;
    counter0 = counter+1;
    //cout<<"temp = "<<temp<<endl;
    retVal.push_back(temp);
  }
  string temp = Str.substr(counter0,Str.size()-counter0);
  retVal.push_back(temp);
/*
  for(auto elem:retVal) cout << elem << " ";
  cout<<endl;
*/
  return retVal;
}


string FindIntersection(string strArr[], int arrLength) {
  
  // code goes here  
  vector<string> Vect1= string2int(strArr[0]);
  vector<string> Vect2= string2int(strArr[1]);

  vector<string>StrRet;
  string RightFormat;

  int counter = 0;
  int offset = 0;


  while(counter < Vect2.size())
  {
    string V2 = Vect2[counter];
    for(int ii=offset;ii<Vect1.size();ii++)
    {
      string V1 = Vect1[ii];
      int Eval = V2.find(V1);
      if( Eval!= string::npos)
      {
        offset = ii+1;
        //cout<<"offset = "<<offset<<endl;
        //cout <<"Vect2["<<counter<<"] = "<<Vect2[counter] << endl;
        StrRet.push_back(Vect2[counter]);
        break;
      }
    }

    counter++;
  }

  for(auto elem: StrRet)
  {
    RightFormat += elem;
    RightFormat += ',';
  }
  RightFormat = RightFormat.substr(0,RightFormat.size()-1);
  //cout <<"RightFormat = "<< RightFormat <<endl;
  //return strArr[0];
  return RightFormat;
}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;
    
}
