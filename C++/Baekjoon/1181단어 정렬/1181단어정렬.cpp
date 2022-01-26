#include <iostream>
#include <cstring>

using namespace std;

struct info{
	string spelling;
	int len;
};


int main()
{
	int num;
	int min;	
	string str;
	
	info tmp;

	cin >> num;

	info word[num];

	for(int i = 0; i<num; i++)
	{
		cin >> word[i].spelling;
		word[i].len= word[i].spelling.length();
	}

	for(int i = 0; i<num; i++){
		min = i;
		for(int j =i+1; j<num; j++)
		{
			if(word[min].len > word[j].len){
				min = j;
			}
			
			else if(word[min].len == word[j].len)
			{
				for(int k=0; k<word[min].len; k++){
					if(word[min].spelling[k] > word[j].spelling[k]) {min = j; break;}
				}			
			}
		}
		
		if(min != i){
			tmp = word[i];
			word[i] = word[min];
			word[min] = tmp;
		}
	}

	for(int i = 0; i<num; i++){
		cout << word[i].spelling;
		if(i != num -1) cout << endl;

	}

}
