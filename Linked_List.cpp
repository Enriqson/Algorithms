#include <iostream>

using namespace std;

class no{

  public:
  int val;
  no* next;
  
  no(int i,no* prox){
    this->next=prox;
    this->val=i;
  }
  no(no* prox){
    this->next=prox;
  }
  ~no(){
    next=NULL;
  }
};

class lista{

  public:
  no* head;
  no* tail;
  no* curr;
  int tam;
  

  lista(){
    this->head=new no(NULL);
    this->tail=head;
    this->curr=head;
    this->tam=0;
  }
  
  void insert(int i){
    no* temp=new no(i,curr->next);
    curr->next=temp;
    if(curr==tail) tail=curr->next;
    tam++;
  }

  void remove(){
    if(curr->next!=NULL){
      no* temp=curr->next;
      curr->next=curr->next->next;
      tam--;
      if(tail==temp) tail=curr->next;
      delete temp;
    }
  }

  void next(){
    if(curr->next!=NULL){
      curr=curr->next;
    }
  }

  void prev(){
    no* temp=curr;
    curr=head;
    while(curr->next!=temp){
      curr=curr->next;
    }
  }

  void clear(){
    no* temp;
    curr=head;
    tail=head;
    
    while(curr->next!=NULL){
      temp=curr->next;
      curr->next=curr->next->next;
      delete temp;
    }
    tam=0;
  }

  int getVal(){
    if(curr->next!=NULL){ 
      return curr->next->val;
    }
    else{
      cerr<<"deu ruim";
      return -1;
    }
  }
  
};

int main() {
  lista dale;
  dale.insert(2);
  dale.next();
  dale.insert(3);
  dale.insert(5);
  dale.remove();
  cout<<dale.getVal()<<endl;

}
