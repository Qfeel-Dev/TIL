#include "BankingCommonDec1.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
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
