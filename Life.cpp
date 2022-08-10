
#include <iostream>
#include <iomanip>

using namespace std;

void output(string life[][20]);// function that outputs array

void changer(string life[][20],string change[][20]);// function that changes both arrays based on day




const int row = 20;// keeps array row size at 20 
const int col= 20;//keeps array row size at 20

int main()
{

	
	
	int r = 0;//variable for row colum keeps track of row cordinate
	int c = 0;// variable for colum keeps track of colum cordinate
	char choice; // stores choice , y or n
	int a = 0;// variable that keeps track of number of alive cells
	
	srand(time(NULL));// picks a random number
	
	
	string life[row][col];// creates first array
	string check[row][col];//creates second array array


	
	for(int i = 0; i< row; i++)// loop that checks every row
	{
		for(int j=0; j<col; j++)// loop that checks every colum
		{
			life[i][j] = "O";// couts O in array
			
			check[i][j] = "O";// couts O in array
		}
		
	}
	
	

	cout << " would you like to add cells (y/n) ?" << endl;// asks user for choice
	cin >> choice;// stores that choice
	
	
	while (choice == 'y')// creates a condition of that choice
	{
	cout << " pick your coordinates of live cells " << endl;// request user the cordinates of cells
	cin >> r >> c;// stores value of cordinates
	
	life[r][c] = "X";// couts an X on those cordinats represents a live cell
	a++;// adds to variable that stores number of alive cells
	
	cout << " would you like to add more cells (y/n) ?" << endl;// request user again for hoice
	cin >> choice;// stores choice
	}

	
	output(life); //calls output function
	
	cout << "would you like to go to the next day (y/n)" << endl;// request user for choice
	cin >> choice;// stores choice
	
	while(choice == 'y' && a != 0)// creates condition if choice is yes and if there are alive cells
	{
		changer(life,check);// calls second array that was changed in function changer
		output(life);// calls output function which output array changed
		
		a=0;// variable that stores count of alive cells
		
		for(int i = 0; i< row; i++)//creates loop to check every row
		{
			for(int j=0; j<col; j++)// creates loop to check every colum
			{
				if(life[i][j] == "X")// creates condition if array has alive cells
				{
					a++;// adds to count variable that stores amount of alive cells
				}
			}
		}
		
		if(a != 0)// creates condition if alive cells if not equal to zero
		{
			cout << "would you like to go to the next day (y/n)" << endl;// request user for choice
			cin >> choice;// stores choice
		}
		else
		{
			cout << "all your cells are dead " << endl;// informs user all cells are dead
		}
	}
	
	
	return 0;// ends function
}
	
void output(string life[][20])// function that outputs array
{	
	for(int i = 0; i< row; i++)// loop that checks every row
	{
		for(int j=0; j<col; j++)// looop that checks every colum
		{
			cout << setw(4) << life[i][j];// setw4 makes code look pretty aka makes everything even and << life[][] outputs array
		}
		cout << endl;// makes 2d aka makes more like a box
	}
	
				
	
}


void changer(string life[][20],string change[][20])// function that changes/checks array
{
	int alive;// declares alive
	
	for(int i = 0; i< row; i++)// loop that checks every row
	{
		for(int j=0; j<col; j++)// loop that checks every colum
		{
			change[i][j] = life[i][j];// makes both array equal
		}
	}
	
	for(int i = 0; i< row; i++)// loop that checks every row
	{
		for(int j=0; j<col; j++)// loop that checks every colum
		{
			alive = 0;// stores amount of alive cells
			if(i+1 <= 19 && change[i+1][j] == "X")// creates condition that function  wont leave array and checks neighboring cells
			{
				alive++;// counts amount of neighboring alive cells
		
			}
			if(i-1 >= 0 && change[i-1][j] == "X")// creates condition that function  wont leave array and checks neighboring cells
			{
				alive ++;// counts amount of neighboring alive cells
			}
			if(i-1 >= 0 && j-1 >= 0 && change[i-1][j-1] == "X")// creates condition that function  wont leave array and checks neighboring cells
			{
				alive++;// counts amount of neighboring alive cells
		
			}
			if(i+1 <= 19 && j-1 >=0 && change[i+1][j-1] == "X")// creates condition that function  wont leave array and checks neighboring cells
			{
				alive++;// counts amount of neighboring alive cells
		
			}
			
			if(i-1 >= 0 && j+1 <= 19 && change[i-1][j+1] == "X")// creates condition that function  wont leave array and checks neighboring cells
			{
				alive++;// counts amount of neighboring alive cells
		
			}
			if(j-1 >= 0 && change[i][j-1] == "X")// creates condition that function  wont leave array and checks neighboring cells
			{
				alive++;// counts amount of neighboring alive cells
		
			}
			if(j+1 <= 19 && change[i][j+1] == "X")// creates condition that function  wont leave array and checks neighboring cells
			{
				alive++;// counts amount of neighboring alive cells
		
			}
			if(i+1 <=19 && j+1 <=19 && change[i+1][j+1] == "X")// creates condition that function  wont leave array and checks neighboring cells
			{
				alive++;// counts amount of neighboring alive cells
		
			}
			
			if(change[i][j] == "X" && (alive == 2 || alive == 3))// creates condition of count of neighboring cells if 2 or 3 cell remain alive
			{
				life[i][j] = "X";// keeps cell alive
			}
			else if(change[i][j] == "O" && alive == 3)// creates condition of count of neighboring cells if first array/day no alive cells and if second day/array was exactly 3
			{
				life[i][j] = "X"; //makes alive cell
			}
			else
			{
				life[i][j] = "O";// makes dead cell
			}
	
	
		}
	
	}

}






