#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account{
	private:
		int accID;      // °èÁÂ¹øÈ£
		int balance;    // ÀÜ    ¾×		
		char * cusName; // °í°´ÀÌ¸§
	public :
		Account(int ID, int money, char *name);
		Account(const Account& copy);
		
		int GetPay();		
		int GetID();
		
		virtual void DepositAccMoney(int money);
		
		void WithdrawAccMoney(int money);
		
		void ShowAccInfo(void) const;
		
		~Account();
};

#endif
