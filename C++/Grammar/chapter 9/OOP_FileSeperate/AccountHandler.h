#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__


class AccountHandler{
	private : 
		Account * accArr[100];   //Account ��ü�� �� ������ �迭 
		int accNum;	        // ����� Account ��ü�� �� 
	public :
		
		AccountHandler();
				
		void MakeAccount(void);
	
		void DepositMoney(void);
	
		void WithdrawMoney(void);
		
		void ShowAllAccInfo(void) const;
}; 


#endif
