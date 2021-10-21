#inlcude "operate.h"

using namespace std;





int main(){
	
	int sel=0;
	int i=0;
	int id_tmp=0;
	int money=0;
	
	struct p_info guest[100];
	
	while(1){
		init();
		sel=0;
		id_tmp=0;
		money=0; 		
		
		cin>>sel;
		if(sel == 5) break;
		else{
			switch(sel){
				case 1: guest[i] = Create_account();  i++; break;
				
				case 2:	
					cout<<"계좌ID: ";
					cin>> id_tmp;
					for(int j=0; j<i; j++){
						if(guest[j].id != id_tmp) continue;
						
						cout<<"입금액: ";
						cin>> money;
						guest[j].money += money;							
						break;
					}
					
				break;
				
				case 3:
					cout<<"계좌ID: ";
					cin>> id_tmp;
					for(int j=0; j<i; j++){
						if(guest[j].id != id_tmp) continue;
						
						cout<<"출금액: ";
						cin>> money;
						guest[j].money -= money;							
						break;
					}
				break;
					
					
				case 4: 
					for(int j =0; j<i; j++){																	
						cout<<"계좌ID: "<<guest[j].id <<endl;
						cout<<"이름: "<<guest[j].name <<endl;
						cout<<"잔액: "<<guest[j].money <<endl;						
						cout<<endl;
					}
				break;
			}		
		}
		
	}

	cout<<"프로그램 종료";
}


