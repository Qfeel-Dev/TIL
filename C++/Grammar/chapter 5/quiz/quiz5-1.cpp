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
			
			len=strlen(company_c)+1;//길이 파악  
			company = new char[len];//메모리 동적 할당 
			strcpy(company,company_c);//값 복사 
		
			len=strlen(tel_c)+1;//길이 파악  
			tel = new char[len];//메모리 동적 할당 
			strcpy(tel,tel_c);//값 복사 			
		}
		
		NameCard(const NameCard& copy)
		:info(copy.info)
		{
			int len=strlen(copy.name)+1;
			this->name = new char[len];		
			strcpy(this->name,copy.name);
			
			len=strlen(copy.company)+1;//길이 파악  
			this->company = new char[len];//메모리 동적 할당 
			strcpy(this->company,copy.company);//값 복사 
		
			len=strlen(copy.tel)+1;//길이 파악  
			this->tel = new char[len];//메모리 동적 할당 
			strcpy(this->tel,copy.tel);//값 복사 			
		}


		void ShowNameCardInfo() const{
			cout << "이름: "<<name<<endl;
			cout << "회사: "<<company<<endl;
			cout << "전화번호: "<<tel<<endl;		
		 
		 	switch(info){
				case 0:
					cout<<"직급: 사원"<<endl;
					
				break;

				case 1:
					cout<<"직급: 주임"<<endl;
					
				break;					
				
				case 2:
					cout<<"직급: 대리"<<endl;
					
				break;
				
				case 3:
					cout<<"직급: 과장"<<endl;
				break;									
			
			}	
		}


};


int main(){

	NameCard man1("부규필","Samsung","010-4828-8769",COMP_POS::SENIOR);
	NameCard copy1=man1;

	
	man1.ShowNameCardInfo();
	copy1.ShowNameCardInfo();
	
}

//deprecated conversion from string constant to 'char*'
