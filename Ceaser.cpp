#include <iostream>

using namespace std;


string encode(string n, int choice); // function change name to numbers
string decode(string n, int choice);// function add the number by amount then change numbers to words////


int main()
{

	string n;// creates variable to store info
	
	int choice;
	
	
	
	cout << "enter message here:";
	getline(cin,n);// inserts info to variable n
	
	cout << " enter the number to shift your coded message: ";
	cin >> choice;
	
	
	cout << "This is your message encoded: " << endl;
	cout << encode(n,choice) << endl;
	
	
	
	cout << "your decoded message is " << decode(encode(n,choice),choice) << endl;

	return 0;
	
}
string encode(string n, int choice) // changes ascii to code + number
	{
 		for(int i=0; i< n.length(); i++) // creates loop
 		{
 		
			if(n[i]>=65 && n[i] <= 90 && n[i] + choice > 90)//creates boarder so the index is a Capital letter and not a symbol
			{
				n[i] = n[i]-26+choice;// changes index by adding choice and creates a loop incase the change index is no a letter 
			}
			else if(n[i]>=97 && n[i] <= 122 && n[i]+ choice > 122)// creates boarder so the index is a lowercase letter and not a symbol
			{
				n[i] = n[i]-26+choice;
			}
			else if (n[i] == 32)
			{
			
			}
			else
			{
				n[i] = n[i]+choice;
			}
		
		}
		return n;// returns new message/code
	
	}
string decode(string n,int choice)// changes new code TO SENTENCE
	{
	
 		for(int i=0; i< n.length(); i++) //creates loop
 		{
 		
			if(n[i]>=65 && n[i] <= 90 && n[i] - choice < 65)//limits ascii table to only capital letters
			{
				n[i] = n[i]+26-choice;// creates loop after border/limit 
			}
			else if(n[i]>=97 && n[i] <= 122 && n[i]- choice < 97)// limits ascii table to only lowercase letters
			{
				n[i] = n[i]+26-choice;// creates loop after border/limit 
			}
			else if (n[i] == 32)
			{
			
			}
			else
			{
				n[i] = n[i]-choice;// sudtracts choice in order to decode the code and return original message
			}
			
		
		}
	return n;// returns new n value
	
	
	}