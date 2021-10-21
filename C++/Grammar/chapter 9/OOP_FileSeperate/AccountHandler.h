#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__


class AccountHandler{
	private : 
		Account * accArr[100];   //Account 객체가 들어갈 포인터 배열 
		int accNum;	        // 저장된 Account 객체의 수 
	public :
		
		AccountHandler();
				
		void MakeAccount(void);
	
		void DepositMoney(void);
	
		void WithdrawMoney(void);
		
		void ShowAllAccInfo(void) const;
}; 


#endif
