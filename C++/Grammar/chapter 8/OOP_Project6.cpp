#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};



class Account{
	private:
		int accID;      // 계좌번호
		int balance;    // 잔    액		
		char * cusName; // 고객이름
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
			cout<<"계좌ID: "<<accID<<endl;
			cout<<"이  름: "<<cusName<<endl;
			cout<<"잔  액: "<<balance<<endl<<endl;	
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
		Account * accArr[100];   //Account 객체가 들어갈 포인터 배열 
		int accNum;	        // 저장된 Account 객체의 수 
	public :
		
		AccountHandler():accNum(0)
		{}
				
		void MakeAccount(void) {
			int id;
			char name[NAME_LEN];
			int balance;
			int AccountType;
			int bene;//이자율		
			int level;	

			cout<<"[계좌종류선택]"<<endl;
			cout<<"1.보통예금계좌 2.신용신뢰계좌"<<endl;
			cout<<"선택: ";	
			cin>>AccountType;

			if(AccountType == 1){cout<<"[보통예금계좌 개설]"<<endl;} 
			else if(AccountType == 2){cout<<"[신용예금계좌 개설]"<<endl;} 
			else{cout<<"유효하지 않은 선택지 입니다."<<endl; return;}
						
			cout<<"계좌ID: ";	
			cin>>id;
			
			cout<<"이  름: ";	
			cin>>name;
			
			cout<<"입금액: ";	
			cin>>balance;
						
			
			if(AccountType == 1 || AccountType == 2)
			{
				cout<<"이자율: ";
				cin>>bene;							
			
				if(AccountType == 1) accArr[accNum] = new NormalAccount(id,balance,name,bene);
				
				else{
					cout<<"신용등급(1toA, 2toB, 3toC): ";
					cin>>level;
					
					accArr[accNum] = new HighCreditAccount(id,balance,name,bene,level);
				}
								
				accNum++;				
				cout<<endl;
			} 
	
			else{cout<<"유효하지 않은 선택지 입니다."<<endl; return;} //추후 계좌 종류 증설시 사용 								 			
		}
	
	
		void DepositMoney(void){
			int money;
			int id;
			cout<<"[입    금]"<<endl;
			cout<<"계좌ID: ";	
			cin>>id;
			cout<<"입금액: ";	
			cin>>money;
			
			for(int i=0; i<accNum; i++){				
				if(id == accArr[i]->GetID()){
					accArr[i]->DepositAccMoney(money);	
					cout<<"입금완료"<<endl<<endl;
					return;
				}												
			}
			
			cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
			return;	
		}
	
	
		void WithdrawMoney(void){
			int money;
			int id;
			cout<<"[출    금]"<<endl;
			cout<<"계좌ID: ";	cin>>id;
			cout<<"출금액: ";	cin>>money;
			
			for(int i=0; i<accNum; i++){
				if(id == accArr[i]->GetID()){
					if(accArr[i]->GetPay() < money){
						cout<<"잔액부족"<<endl<<endl;
						return;
					}
					
					accArr[i]->WithdrawAccMoney(money);
					cout<<"출금완료"<<endl<<endl;
					return;
				}																
			}
			
			cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
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
		cout<<"1. 계좌개설"<<endl;
		cout<<"2. 입    금"<<endl;
		cout<<"3. 출    금"<<endl;
		cout<<"4. 계좌정보 전체 출력"<<endl;
		cout<<"5. 프로그램 종료"<<endl;
		cout<<"선택: "; 
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





