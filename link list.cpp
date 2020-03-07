    #include<iostream>
    #include<conio.h>
    #include<stdlib.h>
using namespace std;
//NODE CLASS 
class Node{
public:
	Node *Next;
};
class List: public Node{// LIST IS CHILD CLASS OF NODE. IN OTHER WORDS NODE IS SUBJCTED TO THE METHODS IN LIST CLASS
	Node *start;
public:
	List(){
		start=NULL;
	}
	int length();
	int position_of_value(int);
	void create();
	void insert();
	void del();
	void sort_link_list();
	void update_node_value();
	void search();
	void display();
	void reverse_link_list();
};
//FIND LENGTH OF THE LIST
int List::length(){
	int i=0;
	if(start==NULL)
	return 0;
	Node *hold;
	hold=start;
	while(hold!=NULL){
		hold=hold->Next;
		i++;
	}
	return i;
}
//FIND THE POSITION OF THE PROVIDED VALUE IF EXISTS
int List::position_of_value(int value){
	int i=1,j=0;
	Node *hold;
	hold=start;
	while(i<=length()){
		if(hold->data==value){
			j++;
			return i;
		}
		hold=hold->Next;
		i++;
	}
	if(j==0){
		return 0;
	}
}
//CREATE OR APPEND A NODE ie TO ADD A NODE AT LAST IN SERIALLY..
void List::create(){
	int item,i=1,len;
	cout<<"Enter the element: ";
	cin>>item;
	Node *temp, *hold;
	temp=new Node;
	temp->data=item;
	temp->Next=NULL;
	if (start==NULL){
		start=temp;
		cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
		getch();
		return;
	}
	else{
		hold=start;
		while(i<length()){
			hold=hold->Next;
			i++;
		}
		hold->Next=temp;
	}
	cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
	getch();
}

//INSERT A NODE A DIFFERENT POSITION
void List::insert(){
	int item,choice,position,i=1;
	cout<<"Enter the element to insert: ";
	cin>>item;
	cout<<"--------- Insert at ---------"<<endl;
	cout<<"1.Begining\n2. Tail\n3. Between Start and Tail\n";
	cout<<"Choice: ";
	cin>>choice;
	Node *temp=new Node();
	Node *hold;
	hold=start;
	temp->data=item;
	if(start==NULL){
		temp->Next=NULL;
		start=temp;
	}
	switch(choice){
        //////////////////////////////////////////////////////////////
		case 1:
		temp->Next=start;
		start=temp;
		break;
    ////////////////////////////////////////////////////////////
		case 2:
		temp->Next=NULL;
		while(i<length()){
			hold=hold->Next;
			i++;
		}
		hold->Next=temp;
		break;
    ////////////////////////////////////////////////////////////////// insert  at any position
		case 3:
		cout<<"Enter the position: ";
		cin>>position;
		if(position==1){
			temp->Next=start;
			start=temp;
		}
		else if(position==length()){
			temp->Next=NULL;
			while(i<length()){
				hold=hold->Next;
				i++;
			}
			hold->Next=temp;
		}
		else{
     while(i<position-1){//we insert after position-1
     	hold=hold->Next;
     	i++;
     }
     temp->Next=hold->Next;
     hold->Next=temp;
 }
 break;
        ////////////////////////////////////////
 default:
 cout<<"Invalid choice!!"<<endl;
 break;

}
cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
getch();
}
//DELETE A NODE 
void List::del(){
	if(start==NULL){
		cout<<"List is empty. Cannot Be Deleted!!"<<endl;
		cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
		getch();
		return ;
	}
	int choice,position,i=1,value;
	Node *hold;
	hold=start;
	cout<<"1. BY POSITION \n 2.BY VALUE\n";
	cout<<"choice";
	cin>>choice;

	switch(choice){
		case 1:
		cout<<"Enter the position: ";
		cin>>position;
		if(position==1){
			start=start->Next;
		}

		while(i<position-1){
			hold=hold->Next;
			i++;
		}
		hold->Next=hold->Next->Next;
		break;
		case 2:
		cout<<"enter the value to Delete";
		cin>>value;
		position=position_of_value(value);
        ////same as deleting by position because you got the position of the inserted value....
		if(position==0){
			break;
		}
		if(position==1){
			start=start->Next;
		}

		while(i<position-1){
			hold=hold->Next;
			i++;
		}
		hold->Next=hold->Next->Next;
		break;
	}
	cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
	getch();
}
//SORT THE LIST
void List::sort_link_list(){
	Node *hold;
	int len=length();
    //bubble sorting
	for(int i=1;i<=len;i++){
		hold=start;
		for(int j=1;j<=len-i;j++){
			if((hold->data)>(hold->Next->data)){
				int temp=hold->data;
				hold->data=hold->Next->data;
				hold->Next->data=temp;
			}hold=hold->Next;
		}
	}
	cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
	getch();
}
//UPDATE
void List::update_node_value(){
	int value, newvalue,position;
	Node *hold=start;
	cout<<"Enter the value to Update :";
	cin>>value;
	cout<<"Enter new value :";
	cin>>newvalue;
	position=position_of_value(value);
	if(position==0){
		cout<<" Value does not exist. "<<endl;
		cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
		getch();
		return;
	}
	else if(position==1){
		start->data=newvalue;
		cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
		getch();
		return;
	}
	else{
		for(int i=1;i<position;i++){
			hold=hold->Next;
		}
		hold->data=newvalue;
	}
	cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
	getch();
}
    //SEARCH
void List::search(){
	int value;
	cout<<"Enter the value to search :";
	cin>>value;
	int position=position_of_value(value);
	if(position==0){
		cout<<"Value doesn't exist"<<endl;
	}
	else{
		cout<<"Value "<<value<<" found at position "<<position<<"."<<endl;
	}
}
//DISPLAY THE LIST
void List::display(){
	Node *hold;
	hold=start;
	int i=1;
	while(i<=length()){
		cout<<" "<<hold->data<<" --> ";
		i++;
		hold=hold->Next;
	}
	cout<<"NULL"<<endl;
	cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
	getch();
	return;
}
//REVERSE THE LIST
void List::reverse_link_list(){
	if(length()==0){
		cout<<"list is empty!!"<<endl;
		return;
	}
	else if(length()==1){
		cout<<"Action completed!"<<endl;
		return;
	}
	Node *prev=NULL;
	Node *temp=start;
	Node *nxt=start->Next;

	while(temp!=NULL){
		temp->Next=prev;
		prev=temp;
		temp=nxt;
		nxt=nxt->Next;
		if(nxt==NULL){
			temp->Next=prev;
			prev=temp;
			start=prev;
			temp=nxt;

		}
	}
	cout<<"\n\n\t\t^^^^^ ACTION COMPLETED ^^^^^\n\n\n";
	getch();
}


int main(){
	List l;
	int choice;
	while(1){
		cout<<"---------Here is the Link List Menu ----------------\n"<<endl
		<<"1. Create\n"<<endl
		<<"2. Insert\n"<<endl
		<<"3. Delete\n"<<endl
		<<"4. Display\n"<<endl
		<<"5. Size of list\n"<<endl
		<<"6. Sort List\n"<<endl
		<<"7. Search\n"<<endl
		<<"8. Reverse List\n"<<endl
		<<"9. Update\n"<<endl
		<<"10.Exit\n"<<endl
		<<"   choice: ";
		cin>>choice;
		switch(choice){
			case 1:
			l.create();
			break;
			case 2:
			l.insert();
			break;
			case 3:
			l.del();
			break;
			case 4:
			l.display();
			break;
			case 5:
			cout<<"The length is:"<<l.length()<<endl;
			break;
			case 6:
			l.sort_link_list();
			break;
			case 7:
			l.search();
			break;
			case 8:
			l.reverse_link_list();
			break;
			case 9:
			l.update_node_value();
			break;
			case 10:
			exit(0);
			break;
			default:
			cout<<"\n\n\t\t!!!!! INVALID CHOICE !!!!!\n\n\n";
		}
	}
	return 0;
}
