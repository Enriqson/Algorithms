#include <iostream>
#include <new>
#include <stdlib.h>


using namespace std;

void merge(int *b,int *c,int *a,int p, int q){
  int i=0;
  int j=0;
  int k=0;

  while(i<p&&j<q){
    if(b[i]<=c[j]){
      a[k]=b[i];
      i++;
      k++;
    }
    else{
      a[k]=c[j];
      j++;
      k++;
    }
  }
  if(i==p){
    while(j<q){
      a[k]=c[j];
      j++;
      k++;
    }
  }
  else{
    while(i<p){
      a[k]=b[i];
      i++;
      k++;
    }
  }

}

void mergesort(int *a,int size){
  if(size>1){
    int i;
    int *b;
    int *c;
    int j=0;
    b=new int[size/2];
    c=new int[(1+size)/2];
    if(b==NULL) exit(-1);
    if(c==NULL) exit(-2);
    for(i=0;i<size/2;i++){
      b[i]=a[i];
    }
    for(i=(size/2);i<size;i++){
      c[j]=a[i];
      j++;
    } 
    mergesort(b, size/2);
    mergesort(c, (1+size)/2);
    merge(b,c,a,size/2,(1+size)/2);
    delete[] b;
    delete[] c;
  }
}
int main() {
  int a[]={17,8,3,67,8,1,54};
  mergesort(a, 7);
  for(int i=0;i<7;i++){
    cout<<a[i]<<endl;
  }
}
