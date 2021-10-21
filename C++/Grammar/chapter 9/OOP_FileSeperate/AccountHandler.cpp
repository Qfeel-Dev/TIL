#include "BankingCommonDec1.h"

AccountHandler::AccountHandler():accNum(20){}


void AccountHandler::MakeAccount(void) {
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


void AccountHandler::DepositMoney(void){
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


void AccountHandler::WithdrawMoney(void){
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

void AccountHandler::ShowAllAccInfo(void) const{
	for(int i=0; i<accNum; i++){
		accArr[i]->ShowAccInfo();
	}
}


