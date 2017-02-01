#include <iostream>
using namespace std;

class ArregrloNNP {
   private:
      int * arr;
      int n;
   public:
     ArregrloNNP(int _n){
       arr =  new int [_n];
       n=_n;
     }
      safearay()  {
         register int i;
         for(i = 0; i < n; i++){
            arr[i] = n;
         }
      }
      int isnnp(int n)
      {
	       int x = 0;
         for (int i = n-1; i > 0; i--)
         {
           if(n%i==0)
           {
             x += i;
           }
         }
         if(x==n)
         {
           return n;
         }
         else
         {
           return -1;
         }
}

      int &operator[](int i) {
         if( i > n) {
               cout << "Woops, you cant go there" <<endl;
               return arr[0];
         }
         else if(i<0){
           cout << "Woops, you cant go there " <<i<<endl;
           return arr[0];
         }
         return arr[i];
      }
      int &operator = (int emp){
        if(isnnp(emp)>=0);{
          this=emp
        }
        else
          cout<<"No es NNP"<<endl;
        cout<<"HOLO"<<endl;
      }
};
int main(){
  ArregrloNNP a = ArregrloNNP(3);
  a[1]=6;
  a[1]=5;
  a[-1]=1;
}