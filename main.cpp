#include <iostream>
#define MAX_STACK_SIZE 10
using namespace std;
struct Element{
	int data;
	int upper;
	Element *next;
};
class Stack{
	private:
	Element tumpuk;
	Element *head = NULL;	
	public:
	void first(){
		tumpuk.upper = -1;
	}
	bool Empty(){
        if(tumpuk.upper == -1){
			return 1;
		}else{
			return 0;
		}
    }
	bool Full(){
        if(tumpuk.upper == MAX_STACK_SIZE-1){
			return 1;
		}else{
			return 0;
		}
    }
    void push(int input){
		if(Full()){
			cout << "Antrian Penuh";
		}else{
			Element *tmp = new Element;
			tmp->data = input;
			tmp->next=NULL;
			if(Empty())
			{
				head=tmp;
				head->next=NULL;
			}else{
				tmp->next=head;
				head=tmp;
			}
			cout<<"Push sukses \n";
			tumpuk.upper++;
		}
	}
	void pop(){
		if (Empty()){
			cout<<"\nAntrian Kosong\n";
		}else{
			Element *tmp = new Element;
			tmp = head;
			head = head->next;
			delete tmp;
			cout<<"\nPop sukses\n";
			tumpuk.upper--;
		}	
	}	
	void getTop(){
		if(Empty()){
			cout << "Antrian Kosong";
		}else{
			cout << head->data;
		}
	}
	void print(){
		if(Empty()){
			cout << "Antrian Kosong" << endl;
		}else{
			cout << "Isi Antrian : " << endl;
			Element *tmp = new Element;
			tmp = head;
			while(tmp!=NULL)
			{
				cout<<tmp->data<<"  ";
				tmp=tmp->next;
			}
		}
	}
};
int nama_menu();
int main(){
	Stack obj;
	int mainmenu,var;
	obj.first();
	do{
		mainmenu = nama_menu();
		switch(mainmenu){
			case 1:
					cout << "Masukan Angka yang ingin dipush: ";cin>>var;
					obj.push(var);
					cin.ignore();
					cin.get();
					break;
			case 2:
					if(obj.Empty()){
						cout << "Antrian Kosong" << endl;
					}else{
						cout << "Angka ";obj.getTop(); cout << " akan dihapus";
						cin.get();
						obj.pop();
					}
					break;
			case 3:
					if(obj.Empty()){
						cout << "Antrian Kosong" << endl;
					}else{
						cout << "Elemen Paling Atas adalah = ";obj.getTop();
						cin.get();
					}
					break;
			case 4:
					obj.print();
					cin.get();
					break;
			case 5:
					exit(0);
			default:
					cout <<"\t\nPilihan tidak ada";
					cin.get();
					break;
		}

	}while (mainmenu != 5);
		cin.get();
		return 0;
}
int nama_menu(){
	int mainmenu;
	cout << "MENU : "<<endl<<endl;
	cout << "1. Push"<<endl;
	cout << "2. Pop"<<endl;
	cout << "3. Get Top"<<endl;
	cout << "4. Print Stack List"<<endl;
	cout << "5. Exit..."<<endl<<endl;
	cout << "Pilihan : "; cin >> mainmenu;
	cin.ignore();
	return mainmenu;  }
