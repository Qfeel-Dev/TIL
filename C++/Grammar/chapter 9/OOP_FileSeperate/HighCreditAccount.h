#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "BankingCommonDec1.h"
#include "NormalAccount.h"



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

#endif
