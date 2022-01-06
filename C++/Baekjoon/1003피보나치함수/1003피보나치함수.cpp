#include <iostream>

using namespace std;

int zero_cnt;
int one_cnt;



int num[41];
num[0] = 0;
num[1] = 1;

int num_zero_cnt[41];
int num_one_cnt[41];

num_zero_cnt[0] = 1;
num_one_cnt[1] = 1;


int fibonacci(int n) {

	if()
 	
    if (n == 0) {
        zero_cnt++;
        return 0;
    } 
	else if (n == 1) {

        one_cnt++;
        return 1;
    } 



	
	else {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}

int main()
{
	
	int test_case;
	
	
	
	cin >> test_case;
	//test_case=1;
	
	int n[test_case];
	
	for(int i =0; i<test_case; i++)
	{
		cin >> n[i];
		
	}
	
	
	for(int i =0; i<test_case; i++)
	{
		zero_cnt = 0;
		one_cnt = 0;
	
		fibonacci(n[i]);
		cout << zero_cnt <<" "<< one_cnt;
		if(i+1 != test_case) cout << endl;
	}
}
