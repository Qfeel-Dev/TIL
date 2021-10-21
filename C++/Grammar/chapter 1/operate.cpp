#include "operate.h"
#include <iostream>

using namespace std;

struct p_info{
	char name[NAME_LEN];
	int id;
	int money;	
};

void init(void){
	cout<<"----MENU----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
	cout<<"선택: ";		
}

struct p_info Create_account(){
	
	struct p_info new_info;
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>> new_info.id;
	
	cout<<"이름: ";
	cin>> new_info.name;
	
	cout<<"입금액: ";
	cin>> new_info.money;	
	
	return new_info;
}
