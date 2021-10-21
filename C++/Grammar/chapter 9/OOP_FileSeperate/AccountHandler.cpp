#include "BankingCommonDec1.h"

AccountHandler::AccountHandler():accNum(20){}


void AccountHandler::MakeAccount(void) {
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


void AccountHandler::DepositMoney(void){
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


void AccountHandler::WithdrawMoney(void){
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

void AccountHandler::ShowAllAccInfo(void) const{
	for(int i=0; i<accNum; i++){
		accArr[i]->ShowAccInfo();
	}
}


