#include <iostream>
using namespace std;


    class Node
	{
    	public:
            int data;
            Node *next;
            
    };
        
    class list{
        private:
            Node *head;
        public:
            list()
			{
                this->head=NULL;
            }

            string insertAfter(int positionalData,int insertiveData){
                Node* after=head;
                Node* temp= new Node;
                if(head==NULL)
				{
                    return "No list found,Unsuccessful\n";
                }

                while(temp!=NULL)
			{
                if(temp->data==positionalData){
                        temp->data=insertiveData;
                        temp->next=after->next;
                        after->next=temp;
                        return "Successful\n";
                }
                after=after->next;
            }

            }

            void DeleteAtstart(){
                Node* temp=new Node;
                temp->next=head;
                Node* todelete=head;
                head->next=head;
                delete todelete;
            }

            void DeleteAtEnd(){
                Node* temp=head;
                Node* todelete;
                while(temp!=NULL){
                    todelete=temp;
                    temp=temp->next;
                }
                delete todelete;
            }

            void deleteNode(int v){
                Node* temp =head;
                Node* NodeD;
                while(temp!=NULL){
                    if(temp->data==v)
                        {
                            temp=NodeD;
                            temp=temp->next;
                        }
                }
                delete NodeD; 
            }
            
            

    }; 

int main(){
    list n;
    Node* head=NULL;
    n.insertAfter(5,10);
    n.DeleteAtstart();
    n.DeleteAtEnd();
    n.deleteNode(1);
    

}
