#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};


class Account{
	private:
		int accID;      // ���¹�ȣ
		int balance;    // ��    ��		
		char * cusName; // ���̸�
	public :
		Account(int accID, int balance, char *cusName)
		{
			this->cusName = new char[strlen(cusName)+1];
			strcpy(this->cusName,cusName);
			
			this->accID = accID;
			this->balance = balance;
		}
		
		Account(const Account& copy)
		:accID(copy.accID), balance(copy.balance)
		{
			this->cusName = new char[strlen(copy.cusName)+1];
			strcpy(this->cusName,copy.cusName);
		}
		
		
		void DepositAccMoney(int accid,int money){
			
			if(this->accID == accid){
				balance += money;
				cout<<"�ԱݿϷ�"<<endl<<endl;
				return;
			}

			else{
				cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
			}	
		}
		
		void WithdrawAccMoney(int accid,int money){
	
			if(this->accID == accid){
				if(balance<money){
					cout<<"�ܾ׺���"<<endl<<endl;
					return;
				}
				balance-=money;
				cout<<"��ݿϷ�"<<endl<<endl;
				return;
			}
			
			else{
				cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
			}			
		}
		
		void ShowAccInfo(void) const{
			cout<<"����ID: "<<accID<<endl;
			cout<<"��  ��: "<<cusName<<endl;
			cout<<"��  ��: "<<balance<<endl<<endl;	
		}
		
		~Account(){
			delete []cusName;
		}
				
};


class AccountHandler{
	private : 
		Account * accArr[100];   //Account ��ü�� �� ������ �迭 
		int accNum;	        // ����� Account ��ü�� �� 
	public :
		
		AccountHandler():accNum(0)
		{}
				
		void MakeAccount(void) {
			int id;
			char name[NAME_LEN];
			int balance;
			
			
			cout<<"[���°���]"<<endl;
			cout<<"����ID: ";	
			cin>>id;
			
			cout<<"��  ��: ";	
			cin>>name;
			
			cout<<"�Աݾ�: ";	
			cin>>balance;
			
			cout<<endl;
			
		 	
			accArr[accNum] = new Account(id,balance,name);
			accNum++;
		}
	
	
	
		void DepositMoney(void){
			int money;
			int id;
			cout<<"[��    ��]"<<endl;
			cout<<"����ID: ";	
			cin>>id;
			cout<<"�Աݾ�: ";	
			cin>>money;
			
			for(int i=0; i<accNum; i++){
				accArr[i]->DepositAccMoney(id,money);	
			}
		}
	
	
		void WithdrawMoney(void){
			int money;
			int id;
			cout<<"[��    ��]"<<endl;
			cout<<"����ID: ";	cin>>id;
			cout<<"��ݾ�: ";	cin>>money;
			
			for(int i=0; i<accNum; i++){
				accArr[i]->WithdrawAccMoney(id,money);
			}
		}
		
		void ShowAllAccInfo(void){
			for(int i=0; i<accNum; i++){
				accArr[i]->ShowAccInfo();
			}
		}
}; 








int main(){
	int choice = 0;
	AccountHandler handler;


	while(1){
	
		cout<<"-----Menu------"<<endl;
		cout<<"1. ���°���"<<endl;
		cout<<"2. ��    ��"<<endl;
		cout<<"3. ��    ��"<<endl;
		cout<<"4. �������� ��ü ���"<<endl;
		cout<<"5. ���α׷� ����"<<endl;
		cout<<"����: "; 
		cin>>choice;
		cout<<endl;
		
		switch(choice){
			case MAKE:
				handler.MakeAccount(); 
				
				break;
			case DEPOSIT:
				handler.DepositMoney(); 
				break;
			case WITHDRAW: 
				handler.WithdrawMoney(); 
				break;
			case INQUIRE:
				handler.ShowAllAccInfo(); 
				break;
			case EXIT:
				return 0;
	
			default:
				cout<<"Illegal selection.."<<endl;
		}
		
	}
	return 0;
}





