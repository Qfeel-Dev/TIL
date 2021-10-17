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
		
		
		void DepositAccMoney(int accid,int money){
			
			if(this->accID == accid){
				balance += money;
				cout<<"입금완료"<<endl<<endl;
				return;
			}

			else{
				cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
			}	
		}
		
		void WithdrawAccMoney(int accid,int money){
	
			if(this->accID == accid){
				if(balance<money){
					cout<<"잔액부족"<<endl<<endl;
					return;
				}
				balance-=money;
				cout<<"출금완료"<<endl<<endl;
				return;
			}
			
			else{
				cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
			}			
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
			
			
			cout<<"[계좌개설]"<<endl;
			cout<<"계좌ID: ";	
			cin>>id;
			
			cout<<"이  름: ";	
			cin>>name;
			
			cout<<"입금액: ";	
			cin>>balance;
			
			cout<<endl;
			
		 	
			accArr[accNum] = new Account(id,balance,name);
			accNum++;
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
				accArr[i]->DepositAccMoney(id,money);	
			}
		}
	
	
		void WithdrawMoney(void){
			int money;
			int id;
			cout<<"[출    금]"<<endl;
			cout<<"계좌ID: ";	cin>>id;
			cout<<"출금액: ";	cin>>money;
			
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





