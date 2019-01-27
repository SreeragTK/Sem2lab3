//including library
#include<stdio.h>
#include<iostream>
using namespace std;
//defining linkedlist using clas
class box{
    public:
          //box contain an element and a pointer point to next box
          int data;
          box*next,*prev;
          box(){
	      next=NULL;
	      prev=NULL;
	      }
          };
class linklist{
    public:
            //pointer point to first element
            box*head;
            //pointer pointt to last element
           box*tail;
           //constructor
           linklist(){
           head=NULL;
           tail=NULL;
           }
//inserting elements at ends
void insert(int value){
                     //pointer point to new created box
                     box*temp=new box;
                     temp->data=value;
                     /*for entry of first element
                     * if else condition*/
                     if(head==NULL){
                     //head points to the first element
                     head=temp;
                     //previous of head null
                     temp->prev=NULL;
                     }
//entry of element other than 1st
                    else{
                       //enter at last position
                       tail->next=temp;
                       temp->prev=tail;
                         }
//now tail point to last element
                      tail=temp;
                    }
void display(){
               //defining current position
               box*current=head;
               //till last element
               while(current!=NULL){
               //displaying the data in box
               cout<<current->data<<"  ";
               //updating current
               current=current->next;
                                 }
               cout<<endl;
               }
//displaying from tail to head(fuly)
void revdisplay(){
               box*current=tail;
               cout<<endl<<"display in reverse order"<<endl;
              //run till end
              //using while loop
              while(current!=NULL){
              //printing the current data
              cout<<current->data<<"  ";
              current=current->prev;
              }

cout<<endl;
}
//delete function to delete last element
void delet(){
           //create temp and current
           box*temp=tail;
           box*current=head;
           while(current->next!=tail){
                              //NEXT pointer of current box point to next box
                             //PREV pointer of next box point to current box
                            current=current->next;
                          current->next->prev=current;
                         }
        //delete last element
        current->next=NULL;
        //update tail
        tail =current;
        //remove temp
        delete temp;
        cout<<"delete last entered element  ";
        }
//insertion at a particular position
void insertat(int pos,int value){
                              //current pointer point to head initially
                             box*current=head;
                           //current position
                          int i=1;
                        while(i<pos-1){
                                       i++;
                                       current=current->next;
                                       current->next->prev=current;
                                      }
                                 //creating new box
                                box*temp=new box;
                              //store value
                             temp->data=value;
                            //temp->prev store address of previous box
                           temp->prev=current->next->prev;
                         //temp next store current next
                        temp->next=current->next;
                      //now current next is temp
                     current->next=temp;
                    current->next->next->prev=temp;
                   cout<<"After inserting "<<value<<"  at position-"<<pos<<endl;
}
//delete at particular position
void deleteat(int pos){
                      box*current=head;
                      box*temp;
                     //initial position
                     int i=1;
                     while(i<pos-1){
                                  i++;
                                  current=current->next;
                                }
                     //out put of current is  previous position of POS
                     //temp store address of POS
                     temp=current->next;
                     temp=current->next->next->prev;
                     //delete  element
                     current->next=NULL;
                     //current box pointer  point to next of temp
                     current->next=temp->next;
                     current->next->next->prev=NULL;
                     current->next->next->prev=temp->prev;
                     cout<<"After delete element at position  " <<pos<<endl;
                     delete temp;
                     }
//counting the data stored in list
void count(){
             int i=1;
             box*current=head;
             while(current->next!=NULL){
             i++;
             current=current->next;
             }
             cout<<"the no of element present in the link list :- \n\t\""<<i<<"\"\n";
             }
};
//declaring main function
int main(){
linklist L;
L.insert(1);
L.insert(2);
L.insert(3);
L.insert(4);
L.insert(5);
L.display();
L.insertat(2,9);
L.display();
L.deleteat(3);
L.display();
L.delet();
L.display();
L.revdisplay();
L.count();
return 0;
//closing the function
}
