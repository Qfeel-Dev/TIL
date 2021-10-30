#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"


class AccountHandler{
	private : 
		Account * accArr[100];   //Account ��ü�� �� ������ �迭 
		int accNum;	        // ����� Account ��ü�� �� 
	public :
		
		AccountHandler();
				
		~AccountHandler();
				
				
		void MakeAccount(void);
	
		void DepositMoney(void);
	
		void WithdrawMoney(void);
		
		void ShowAllAccInfo(void) const;
}; 


#endif
