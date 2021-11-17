#include <iostream>
#include <cstring>


using namespace std;

class String{
	private:
		char *txt;
	
	public:
				
		String(const char *s)
		{
			txt = new char[strlen(s)+1];
			strcpy(txt,s);			
		}
		
		
		String(const String& s)
		{
			txt = new char[strlen(s.txt)+1];
			strcpy(txt,s.txt);			
		}
		
		
		String operator=(const char* s)
		{
			delete []txt;
			txt = new char[strlen(s)+1];
			strcpy(txt,s);			
		}
	
		String operator=(const String& s)
		{
			delete []txt;
			txt = new char[strlen(s.txt)+1];
			strcpy(txt,s.txt);			
		}
		
		
		String operator+(const String& s)
		{
			char *txt;
			txt = new char[strlen(s.txt) + strlen(this->txt) + 1];
			strcpy(txt,this->txt);
			strcat(txt,s.txt);
			
			String tmp(txt);
			return tmp;
		
		}
	
		String operator+=(const String& s)
		{
			char *txt;
			txt = new char[strlen(s.txt) + strlen(this->txt) + 1];
			strcpy(txt,this->txt);
			strcat(txt,s.txt);
			
			delete []this->txt;
			this->txt = new char[strlen(s.txt) + strlen(this->txt) + 1];
			strcpy(this->txt,txt);
						
			delete []txt;
		}
	
		friend bool operator==(const String& str1 , const String& str2)
		{
			cout << "== overloading" << endl;
			
			if(strlen(str1.txt) != strlen(str2.txt))
			{
				cout << "lenth false" << endl;
				cout << str1.txt << " || "<<str2.txt << endl;
			
				 return false;
			
			}
			for(int i=0; i<strlen(str1.txt); i++)
			{
			
				if(str1.txt[i] != str2.txt[i]) return false;			
			}
			
			return true;
		}
		
		friend ostream& operator<<(ostream& os, const String& s)
		{
			os << s.txt;
			return os;
			
		}

		friend istream& operator<<(istream& is, String& s)
		{
			char txt[100];
			is >> txt;
			s = String(txt);
			return is;
		}	
	
		void Show() const
		{
			cout << txt << endl;
		}


};


int main(void)
{
	String str1("I love girl");
	String str2 = "hello";

	str1 = "I love girl";
	str2 = "I love gira";
		
	str1.Show();
	str2.Show();

	if(str1 == str2)
	{
		cout << "right" << endl;
	}
	
	else
	{
		cout << "wrong" << endl;
	}
	
	cout<<str1<<endl;
	 

}
