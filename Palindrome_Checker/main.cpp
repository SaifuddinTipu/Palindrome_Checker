/** Checking a Palindrome in C++

 -------------------------------------------------------------------------------------------------------------|
 MD. SAIFUDDIN TIPU

 -------------------------------------------------------------------------------------------------------------|
 
 */

#include <windows.h>
#include <iostream>
#include <cctype>
#include<string>
#include "queue.h"
#include "stack.h"

using namespace std;
void mainmenu();  //function mainmenu
bool readtext();  //function to read and clean text
bool palindrom(); //function to check palindrome
char singleChar = ' '; //variable to get the string
char newchar[1000];   //variable for new string
int i=0;
SingleQueue<char> queue;
StackListType<char> stack;


int main()
{
    mainmenu();
}

void mainmenu()
{
	xy:
	cout <<"\nEnter your text here to check if its a palindrome: ";

	readtext();
    string choice;

	redo:
	cout<<"\nEnter y to continue and n to exit>> ";
	cin>>choice;
	if(choice.compare("y")==0 || choice.compare("Y")==0)
    {
        cin.ignore();
	    goto xy;
    }
    else if(choice.compare("n")==0|| choice.compare("N")==0)
    {
        cout<<"\n\n\t\tThanks for using this program\n\n";
        exit(0);
    }
    else
    {
       cout<<"Wrong Input..........\n";
       goto redo;
}
}


bool readtext()
{
	re:
	while(cin.get(singleChar) && singleChar != '\n')
	{
	if(ispunct(singleChar))
    {
        goto re;
    }
    else if(isspace(singleChar))
    {
        goto re;
    }
    else if(isdigit(singleChar))
    {
        goto re;
    }
    else
	{
	    i++;
		newchar[i] = tolower(singleChar);
		queue.EnQueue(tolower(newchar[i]));
		stack.Push(tolower(newchar[i]));
	}

	}
	cout<<"\nYour clean text is: ";
	for(int j=1;j<=i;j++)
    {
        cout<<newchar[j];
    }
    cout<<"\n\n";

    for(int k=1;k<=i;k++)
    {
        cout<<newchar[k];
        newchar[k]=' ';
    }
            i=0;

	palindrom();         //call function palindrome
    stack.MakeEmpty();   //call MakeEmpty function from stack.h to destroy the current list
	queue.MakeEmpty();   //call MakeEmpty function from queue.h to destroy the current list
}

bool palindrom()
{
	bool isPalindrome = true;
	// determine if the string is a palindrome
	while((!queue.IsEmpty()) && (!stack.IsEmpty()) && isPalindrome)
	{
		if(queue.Front() != stack.Top())
		{
			isPalindrome = false;
		}
		else
		{
			queue.DeQueue();
			stack.Pop();
		}

	}

	// display results to the screen
	if(isPalindrome)
	{
		cout<<" is a palindrome!\n";
	}
	else
	{
		cout<<" is NOT a palindrome..\n";
	}

	return 0;
}
//end of program
