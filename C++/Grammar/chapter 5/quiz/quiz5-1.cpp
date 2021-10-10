#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS{
	enum{
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};
}


class NameCard{
	private :
		char * name;
		char * company;
		char * tel;
		int info;
	public : 
		
		NameCard(const char * name_c, const char * company_c,const char * tel_c,int info_c)
		:info(info_c)
		{
			int len=strlen(name_c)+1;
			name = new char[len];		
			strcpy(name,name_c);
			
			len=strlen(company_c)+1;//���� �ľ�  
			company = new char[len];//�޸� ���� �Ҵ� 
			strcpy(company,company_c);//�� ���� 
		
			len=strlen(tel_c)+1;//���� �ľ�  
			tel = new char[len];//�޸� ���� �Ҵ� 
			strcpy(tel,tel_c);//�� ���� 			
		}
		
		NameCard(const NameCard& copy)
		:info(copy.info)
		{
			int len=strlen(copy.name)+1;
			this->name = new char[len];		
			strcpy(this->name,copy.name);
			
			len=strlen(copy.company)+1;//���� �ľ�  
			this->company = new char[len];//�޸� ���� �Ҵ� 
			strcpy(this->company,copy.company);//�� ���� 
		
			len=strlen(copy.tel)+1;//���� �ľ�  
			this->tel = new char[len];//�޸� ���� �Ҵ� 
			strcpy(this->tel,copy.tel);//�� ���� 			
		}


		void ShowNameCardInfo() const{
			cout << "�̸�: "<<name<<endl;
			cout << "ȸ��: "<<company<<endl;
			cout << "��ȭ��ȣ: "<<tel<<endl;		
		 
		 	switch(info){
				case 0:
					cout<<"����: ���"<<endl;
					
				break;

				case 1:
					cout<<"����: ����"<<endl;
					
				break;					
				
				case 2:
					cout<<"����: �븮"<<endl;
					
				break;
				
				case 3:
					cout<<"����: ����"<<endl;
				break;									
			
			}	
		}


};


int main(){

	NameCard man1("�α���","Samsung","010-4828-8769",COMP_POS::SENIOR);
	NameCard copy1=man1;

	
	man1.ShowNameCardInfo();
	copy1.ShowNameCardInfo();
	
}

//deprecated conversion from string constant to 'char*'
