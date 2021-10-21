#ifndef __NOMAL_ACCOUNT_H__
#define __NOMAL_ACCOUNT_H__

#include "Account.h"

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


#endif
