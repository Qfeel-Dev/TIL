#include <iostream>

using namespace std;
const int NAME_LEN=20;

struct p_info{
	char name[NAME_LEN];
	int id;
	int money;	
};

void init();
struct p_info Create_account();


int main(){
	
	int sel=0;
	int i=0;
	int id_tmp=0;
	int money=0;
	
	struct p_info guest[100];
	
	
	while(1){
		init();
		sel=0;
		id_tmp=0;
		money=0; 		
		
		cin>>sel;
		if(sel == 5) break;
		else{
			switch(sel){
				case 1: guest[i] = Create_account();  i++; break;
				
				case 2:	
					cout<<"����ID: ";
					cin>> id_tmp;
					for(int j=0; j<i; j++){
						if(guest[j].id != id_tmp) continue;
						
						cout<<"�Աݾ�: ";
						cin>> money;
						guest[j].money += money;							
						break;
					}
					
				break;
				
				case 3:
					cout<<"����ID: ";
					cin>> id_tmp;
					for(int j=0; j<i; j++){
						if(guest[j].id != id_tmp) continue;
						
						cout<<"��ݾ�: ";
						cin>> money;
						guest[j].money -= money;							
						break;
					}
				break;
					
					
				case 4: 
					for(int j =0; j<i; j++){																	
						cout<<"����ID: "<<guest[j].id <<endl;
						cout<<"�̸�: "<<guest[j].name <<endl;
						cout<<"�ܾ�: "<<guest[j].money <<endl;						
						cout<<endl;
					}
				break;
			}		
		}
		
	}

	cout<<"���α׷� ����";
}

void init(){
	cout<<"----MENU----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
	cout<<"����: ";
}

struct p_info Create_account(){
	
	struct p_info new_info;
	
	cout<<"[���°���]"<<endl;
	cout<<"����ID: ";
	cin>> new_info.id;
	
	cout<<"�̸�: ";
	cin>> new_info.name;
	
	cout<<"�Աݾ�: ";
	cin>> new_info.money;	
	
	return new_info;
}
