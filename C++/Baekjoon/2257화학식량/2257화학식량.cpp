#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

int cal(stack<char> S){
	int sum = 0;
	int multiple = 1; 

	while(S.empty() != true){				

		if(S.top() == 'H'){
			sum += 1 * multiple;
			multiple = 1;
		}
		else if(S.top() == 'C'){
			sum += 12 * multiple;
			multiple = 1;			
		}
		else if(S.top() == 'O'){	
			sum += 16 * multiple;
			multiple = 1;
		}
		else if(S.top() == '('){}
		else if(S.top() == ')'){}
		else{ 
			multiple = S.top()-'0';								
		}//¼ýÀÚ 
		
		S.pop();		
	}

	return sum;
}

int main(){
	
	stack <char> S;
	string tmp;

	cin >> tmp;

	for(int i = 0; i < tmp.size(); i++){
		S.push(tmp[i]);
	}
	
	cout << cal(S);

	return 0;
}
