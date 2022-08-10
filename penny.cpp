#include <iostream>
#include <iomanip>

using namespace std;

void output(string emoji[][5]);//function that outputs the main array /board
void toss(string penny[][5]);// function that adds prizes/pennies

const int row = 5;
const int col= 5;//column
// global variable aka you can acess the variables by any function
// good to use const int here because they dont change

int main()
{
	srand(time(NULL));
	//string emoji[10][10];
	
	string emoji[row][col];// array
	string penny[row][col];
	int r,c;// row,colum
	int moneybag = 0;
	int grapes = 0;
	int jack = 0;
	int bricks = 0;
	int monkey = 0;
	
	for(int i = 0; i< row; i++)// initializes array aka checks everything//runs 4 times
	{
		for(int j=0; j<col; j++)// runs 6 times
		{
			emoji[i][j] = "🟦";// 
		}
	}
	for(int i = 0; i< 3; i++)// all the for loops are to add prizes onto array
	{
		r = rand()%5;//random spot on row
		c = rand()%5;// random spot in colum
		
		
		if(emoji[r][c] == "🟦")
		{
			emoji[r][c] = "💰";
		}
		else
		{
			i--;
		}
	}
	for(int i = 0; i< 3; i++)
	{
		r = rand()%5;
		c = rand()%5;
		
		if(emoji[r][c] == "🟦")
		{
		emoji[r][c] = "🍇";
		}
		else 
		{
			i--;
		}
	}
	for(int i = 0; i< 3; i++)
	{
		r = rand()%5;
		c = rand()%5;
		
		if(emoji[r][c] == "🟦" )
		{
		emoji[r][c] = "🎃";
		}
		else
		{
			i--;
		}
	}
	for(int i = 0; i< 3; i++)
	{
		r = rand()%5;
		c = rand()%5;
		
		if(emoji[r][c] == "🟦" )
		{
		emoji[r][c] = "🧱";
		}
		else
		{
			i--;
		}
	}
	for(int i = 0; i< 3; i++)
	{
		r = rand()%5;
		c = rand()%5;
		
		if(emoji[r][c] == "🟦" )
		{
		emoji[r][c] = "🐒";
		}
		else
		{
			i--;
		}
	}
	
	
	toss(emoji);// array that adds penny
	output(emoji);  //reward table
	
	return 0;
}
	
void output(string emoji[][5])
{	//output array
	for(int i = 0; i< row; i++)// initializes array aka checks everything//runs 4 times
	{
		for(int j=0; j<col; j++)// runs 6 times
		{
			cout << setw(4) << emoji[i][j];// makes code look pretty aka makes everything even
		}
		cout << endl;// makes 2d aka makes more like a box
	}
}
void toss(string penny[][5])
{//91
	int r;// row of array
	int c;// colum of array
	int moneybag = 0;// starts all prizes at 0 
	int grapes = 0;
	int jack = 0;
	int bricks = 0;
	int monkey = 0;
	for(int i = 0; i< 10; i++)//loop
	{
		r = rand()%5;
		c = rand()%5;

		if(penny[r][c] == "🟦" ) 
		{
		
		}
		else if(penny[r][c] == "💰")// functions to count up prizes penny lands on
		{
			moneybag++;
		}
		else if(penny[r][c] == "🍇" )
		{
			grapes++;
	
		}
		else if(penny[r][c] ==  "🎃" )
		{
			jack++;
		}
		else if(penny[r][c] ==  "🧱" )
		{
			bricks++;
		}
		else if(penny[r][c] ==  "🐒" )
		{
			bricks++;
		}
		
	
		penny[r][c] = "🪙";// couts penny
	}
	
	if (moneybag == 3)// if statements that organizes prizes and conditions 
	{
	cout <<"you won a moneybag " << endl;
	}
	
	if (grapes == 3)
	{
	cout << " you won grapes"<< endl;
	}
	
	if (jack == 3)
	{
	cout << " you won jackolatern"<< endl;
	}
	
	if (bricks == 3)
	{
	cout << " you won bricks"<< endl;
	}
	if (monkey == 3)
	{
	cout << " you won monkey"<< endl;
	
	}
	if(moneybag != 3 && grapes != 3 && jack != 3 && bricks != 3 && monkey != 3)
	{
	cout<< " you won nothing " << endl;
	}
	
}
