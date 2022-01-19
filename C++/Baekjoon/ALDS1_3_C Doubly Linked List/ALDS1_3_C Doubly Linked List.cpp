#include <iostream>
#include <cstring>


struct Node
{
	int key;
	Node *prev, *next;
}



int main()
{
	int command_num;
	char command[15];

	scanf("%d",&command_num);
	
	for(int i = 0 ; i< command_num; i++)
	{
		scanf("%s",command);
		if(command[0] == 'i'){}
		else
		{
			if(strlen(command) == 11){//delete first
			
			}

			else if(strlen(command) == 10){//delete last
			
			}

			else{//delete x
			
			}

		}
	
	}


}
