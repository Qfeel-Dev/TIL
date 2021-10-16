#include <iostream>
#include <cstring>


using namespace std;

class MyFriendInfo{
	private :
		char * name;
		int age;
		
	public :
		
		MyFriendInfo(int fage, char *fname):age(fage)
		{
			name = new char[strlen(fname)+1];
			strcpy(name,fname);
			
		}
		
		void ShowMyfriendInfo() const 
		{
			cout << "이름" << name << endl;
			cout << "나이" << age << endl;	
		}
		
		~MyFriendInfo(){
			delete []name;
			cout <<"basic delete" << endl;
			
		}
};



class MyFriendDetailInfo : public MyFriendInfo{ 
	private :
		char * addr;
		char * tel;
		
	public :
		
		MyFriendDetailInfo(int fage, char *fname , char *faddr, char *ftel):MyFriendInfo(fage,fname)
		{
			addr = new char[strlen(faddr)+1];
			strcpy(addr,faddr);
		
			tel = new char[strlen(ftel)+1];
			strcpy(tel,ftel);
		}
		
		void ShowMyfriendDetailInfo() const 
		{
			cout << "주소" << addr << endl;
			cout << "번호" << tel << endl;	
		}
		
		~MyFriendDetailInfo(){
			delete []addr;
			delete []tel;
			
			cout <<"detail delete" << endl;
			
		}
};



int main(void){
	MyFriendDetailInfo f1(23,"부규필","제주","48288769");
	
	f1.ShowMyfriendInfo();
	f1.ShowMyfriendDetailInfo();
	
	return 0;
}
