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
		
		int GetPay(){return balance;}		
		int GetID(){return accID;}
		
		
		virtual void DepositAccMoney(int money){			
			balance += money;
			return;
		}
		
		void WithdrawAccMoney(int money){			
			balance-=money;
			return;			
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

class NormalAccount : public Account{
	private :
		int BeneInfo;
	public : 
		NormalAccount(int accID, int balance, char *cusName,int benefit)
		:Account(accID,balance,cusName), BeneInfo(benefit)
		{}
		
		void DepositAccMoney(int money){						
			Account::DepositAccMoney(money);
			Account::DepositAccMoney(money*((double)BeneInfo/100));			
			return;
		}		
};

class HighCreditAccount : public NormalAccount{
	private :
		int level;
	public : 
		HighCreditAccount(int accID, int balance, char *cusName,int benefit,int lv)
		:NormalAccount(accID,balance,cusName,benefit),level(lv){}
		
		void DepositAccMoney(int money){
			NormalAccount::DepositAccMoney(money);
			switch(level){
				case 1:
					Account::DepositAccMoney(money*0.07);
					break;
				
				case 2:
					Account::DepositAccMoney(money*0.04);
					break;
					
				case 3:
					Account::DepositAccMoney(money*0.02);
					break;
			}
			return;
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
			int AccountType;
			int bene;//������		
			int level;	

			cout<<"[������������]"<<endl;
			cout<<"1.���뿹�ݰ��� 2.�ſ�ŷڰ���"<<endl;
			cout<<"����: ";	
			cin>>AccountType;

			if(AccountType == 1){cout<<"[���뿹�ݰ��� ����]"<<endl;} 
			else if(AccountType == 2){cout<<"[�ſ뿹�ݰ��� ����]"<<endl;} 
			else{cout<<"��ȿ���� ���� ������ �Դϴ�."<<endl; return;}
						
			cout<<"����ID: ";	
			cin>>id;
			
			cout<<"��  ��: ";	
			cin>>name;
			
			cout<<"�Աݾ�: ";	
			cin>>balance;
						
			
			if(AccountType == 1 || AccountType == 2)
			{
				cout<<"������: ";
				cin>>bene;							
			
				if(AccountType == 1) accArr[accNum] = new NormalAccount(id,balance,name,bene);
				
				else{
					cout<<"�ſ���(1toA, 2toB, 3toC): ";
					cin>>level;
					
					accArr[accNum] = new HighCreditAccount(id,balance,name,bene,level);
				}
								
				accNum++;				
				cout<<endl;
			} 
	
			else{cout<<"��ȿ���� ���� ������ �Դϴ�."<<endl; return;} //���� ���� ���� ������ ��� 								 			
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
				if(id == accArr[i]->GetID()){
					accArr[i]->DepositAccMoney(money);	
					cout<<"�ԱݿϷ�"<<endl<<endl;
					return;
				}												
			}
			
			cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
			return;	
		}
	
	
		void WithdrawMoney(void){
			int money;
			int id;
			cout<<"[��    ��]"<<endl;
			cout<<"����ID: ";	cin>>id;
			cout<<"��ݾ�: ";	cin>>money;
			
			for(int i=0; i<accNum; i++){
				if(id == accArr[i]->GetID()){
					if(accArr[i]->GetPay() < money){
						cout<<"�ܾ׺���"<<endl<<endl;
						return;
					}
					
					accArr[i]->WithdrawAccMoney(money);
					cout<<"��ݿϷ�"<<endl<<endl;
					return;
				}																
			}
			
			cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
			return;	
		}
		
		void ShowAllAccInfo(void) const{
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





