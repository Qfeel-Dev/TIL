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
					cout<<"계좌ID: ";
					cin>> id_tmp;
					for(int j=0; j<i; j++){
						if(guest[j].id != id_tmp) continue;
						
						cout<<"입금액: ";
						cin>> money;
						guest[j].money += money;							
						break;
					}
					
				break;
				
				case 3:
					cout<<"계좌ID: ";
					cin>> id_tmp;
					for(int j=0; j<i; j++){
						if(guest[j].id != id_tmp) continue;
						
						cout<<"출금액: ";
						cin>> money;
						guest[j].money -= money;							
						break;
					}
				break;
					
					
				case 4: 
					for(int j =0; j<i; j++){																	
						cout<<"계좌ID: "<<guest[j].id <<endl;
						cout<<"이름: "<<guest[j].name <<endl;
						cout<<"잔액: "<<guest[j].money <<endl;						
						cout<<endl;
					}
				break;
			}		
		}
		
	}

	cout<<"프로그램 종료";
}

void init(){
	cout<<"----MENU----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
	cout<<"선택: ";
}

struct p_info Create_account(){
	
	struct p_info new_info;
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>> new_info.id;
	
	cout<<"이름: ";
	cin>> new_info.name;
	
	cout<<"입금액: ";
	cin>> new_info.money;	
	
	return new_info;
}
