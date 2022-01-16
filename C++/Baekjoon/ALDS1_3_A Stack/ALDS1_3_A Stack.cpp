#include <iostream>
#include <cstdlib>


using namespace std;


int op[1000];
int stack_pt;

void init()
{
	stack_pt = 0;
}

void push(int v)
{
	op[++stack_pt] = v;
	
}

int pop()
{
	stack_pt--;
	return op[stack_pt + 1];
}

int main()
{
	char input_buf[100];	
	int a,b;
	init();

	while(scanf("%s",input_buf) != EOF)
	{	
		if(input_buf[0] == '+')
		{
			a = pop();
			b = pop();
			push(a+b);		
		}
		else if(input_buf[0] == '-')
		{
			b = pop();
			a = pop();
			push(a-b);
		}

		else if(input_buf[0] == '*')
		{
			a = pop();
			b = pop();
			push(a*b);
		}
		else
		{			
			push(atoi(input_buf));
		}
	}
	cout << pop();	
	
}
