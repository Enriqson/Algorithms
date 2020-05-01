#include <iostream>

using namespace std;

int Binsearch(int *a,int l,int r, int k){
  if(l<=r){
    int m=(l+r)/2;
    if(k==a[m]){
      return m;
    }
    else if(k>a[m]){
      return Binsearch(a,1+m,r,k);
    }
    else return Binsearch(a,l,m-1,k);
  }
  return -1;
}

int Bisearch(int *a,int r, int k){
  int l=0;
  int m;
  while(l<=r){
    m=(l+r)/2;
    if(k==a[m]){
      return m;
    }
    else if(k>a[m]){
      l=m+1;
    }
    else r=m-1;
  }
  return -1;
}

int main() {
  int a[]={1,2,3,4,5,6,10,15};
  int s=Binsearch(a, 0, 7, 15);
  int r=Bisearch(a, 7, 15);
  cout<<s<<endl;
  cout<<r<<endl;
}
