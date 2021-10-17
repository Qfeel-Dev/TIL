#include <iostream>
#include <cstring>

using namespace std;


class Book{
	private:
		char * title;
		char * isbn;
		int price;
	public:
		Book(char * title, char * isbn, int bprice):price(bprice){
			this->title = new char[strlen(title)+1];
			strcpy(this->title,title);
			
			
			this->isbn = new char[strlen(isbn)+1];
			strcpy(this->isbn,isbn);
		}
		
		~Book(){
			delete []title;
			delete []isbn;
		}
		
		void ShowBookInfo() const{
			cout << "제목 : " << title << endl;
			cout << "ISBN : " << isbn << endl;
			cout << "가격 : " << price << endl;
		}
};

class EBook : public Book{
	private :
		char * DRMKey;
	public :
		EBook(char * title, char * isbn, int bprice, char * DRMKey):Book(title,isbn,bprice){	
			this->DRMKey = new char[strlen(DRMKey)+1];
			strcpy(this->DRMKey,DRMKey);
		}		
		~EBook(){
			delete []DRMKey;
		}
		
		void ShowEBookInfo() const {
			ShowBookInfo();
			cout << "DRM Key : " << DRMKey << endl;
		}
};

int main(void){
	Book book("좋은 c++", "551-12345-890-0",20000);
	book.ShowBookInfo();
	
	cout << endl;
	
	EBook ebook("좋은 c++ ebook", "551-12345-890-1",10000,"fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	
	return 0;
}
