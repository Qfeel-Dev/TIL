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
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
	cout<<"����: ";		
}

struct p_info Create_account(){
	
	struct p_info new_info;
	
	cout<<"[���°���]"<<endl;
	cout<<"����ID: ";
	cin>> new_info.id;
	
	cout<<"�̸�: ";
	cin>> new_info.name;
	
	cout<<"�Աݾ�: ";
	cin>> new_info.money;	
	
	return new_info;
}
