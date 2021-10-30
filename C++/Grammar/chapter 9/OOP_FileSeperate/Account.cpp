#include "Account.h"
#include "BankingCommonDec1.h"


Account::Account(int ID,int money,char *name)
:accID(ID),balance(money)
{	
	cusName = new char[strlen(name)+1];
	strcpy(cusName,name);
}

Account::Account(const Account& copy)
:accID(copy.accID), balance(copy.balance)
{
	this->cusName = new char[strlen(copy.cusName)+1];
	strcpy(this->cusName,copy.cusName);
}

int Account::GetPay(){return balance;}		
int Account::GetID(){return accID;}

void Account::DepositAccMoney(int money){			
	balance += money;
	return;
}

void Account::WithdrawAccMoney(int money){			
	balance-=money;
	return;			
}

void Account::ShowAccInfo(void) const{
	cout<<"°èÁÂID: "<<accID<<endl;
	cout<<"ÀÌ  ¸§: "<<cusName<<endl;
	cout<<"ÀÜ  ¾×: "<<balance<<endl<<endl;	
}

Account::~Account(){
	delete []cusName;
}
