#include <iostream>
#include <iomanip>

using namespace std;

void output(string map[][3]);//function to output 

const int row = 3;//makes row array 3 boxes long
const int col = 3;//makes col array 3 boxes tall 

int main()
{
	srand(time(NULL));//picks random number 
	
	string map[row][col];//array aka
	char input;//holds value in this case players choice for Multiplayer or single player
	int rowin;// row cordinates input
	int colin;//column cordinates input
	int win = 0;// holds value if theres a win , starts at zero
	int lose = 0;//holds amount if player has a loss which will be used iin function to end code if more than 0
	int p1 = 1;//variable for player has value of 1 for loop function to take turns
	int p2 = 0;//variable for player has value of 0 for loop function to take turns
	// function we will use for turns, if statements , code that with change value, conditions of if states will be those values, creates endless loop
	int wait = 0;//something random to use as condition for if statements (for code to be more organized)
	int atie = 4;//variable for storing amount of circles placed, starts at 4(because X goes first so max amount of zeros is 4)
	
	for(int i = 0; i < row; i++)//loop checks every box in row
	{	
		for(int j = 0; j < col; j++)//loop checks every box in col
		{
			map[i][j] = "⬛";// couts black box which are the spaces for either X or O
		}
	}
	cout << "Do you want to play singleplayer(s) or multiplayer(m)? ";
	cin >> input;//holds players input
	
	if(input == 's' || input == 'S')//condition if input is singleplayer
	{
		
		while(wait == 0 && win == 0 && lose == 0)//condition if player hasn't lost or won yet and if theres at least an empty spot to use
		{
			cout << "Enter row coordinate(1-3): ";
			cin >> colin;// holds users column coordinates input
			
			cout << "Enter column coordinate(1-3): ";
			cin >> rowin;// holds user row coordinates input
			
			while(map[colin - 1][rowin - 1] != "⬛")//creates loop condition = row &&column input coordinates subtacted by 1 (more like an average grapgh using cordinates )
			{
				cout << "This spot is already taken. Try again. " << endl << endl;
				
				cout << "Enter row coordinate(1-3): ";
				cin >> rowin;//collects row coordinate input
				
				cout << "Enter column coordinate(1-3): ";
				cin >> colin;//collects column coordinate input
			}
			
			map[colin - 1][rowin - 1] = "❌";//places an X on row and column input coordinates ( the coordinates are -1 to make them more like common graph coordinates)

			
			
			
			if(wait == 0)//random condition to make if statement
			{
				if(map[0][0] == "❌" && map[0][1] == "❌" && map[0][2] == "❌")// creates condition using cordinates if 3 X in the frist row
				{
					output(map);//calls function to output array
					
					cout << "You win!" << endl;// inform user they won
					
					return 0;//ends code
				}
				else if(map[1][0] == "❌" && map[1][1] == "❌" && map[1][2] == "❌")// creates condition using cordinates if 3 X in the second row
				{
					output(map);//same as above
					
					cout << "You win!" << endl;//same as above
					
					return 0;//same as above
				}
				else if(map[2][0] == "❌" && map[2][1] == "❌" && map[2][2] == "❌")// creates condition using cordinates if 3 X in the third row
				{
					output(map);
					
					cout << "You win!" << endl;
					
					return 0;
				}
				else if(map[0][0] == "❌" && map[1][0] == "❌" && map[2][0] == "❌")// creates condition using cordinates if 3 X in the first column
				{
					output(map);
					
					cout << "You win!" << endl;
					
					return 0;
				}
				else if(map[0][1] == "❌" && map[1][1] == "❌" && map[2][1] == "❌")// creates condition using cordinates if 3 X in the second column
				{
					output(map);
					
					cout << "You win!" << endl;
					
					return 0;
				}
				else if(map[0][2] == "❌" && map[1][2] == "❌" && map[2][2] == "❌")// creates condition using cordinates if 3 X in the third column
				{
					output(map);
					
					cout << "You win!" << endl;
					
					return 0;
				}
				else if(map[0][0] == "❌" && map[1][1] == "❌" && map[2][2] == "❌")// creates condition using cordinates if 3 X in diagonal line left to right
				{
					output(map);
					
					cout << "You win!" << endl;
					
					return 0;
				}
				else if(map[0][2] == "❌" && map[1][1] == "❌" && map[2][0] == "❌")// creates condition using cordinates if 3 X in diagonal line right to left
				{
					output(map);
					
					cout << "You win!" << endl;
					
					return 0;
				}
				
			if(atie== 0)//condition if atie== 0 which means there are 4 circles on the board its here after the previous function which couts an X and checks if theres a win
			{
			output(map);//calls function to output array
			
			cout<< " its a tie "<< endl;//tells user its a tie
			
			return 0;// ends function
			}
				
				
			}
			while(map[colin][rowin] != "⬛")// creates condition if row coordinates input is not an open spot/black square or column cordinates input is not an open spot/ black sqaure
			{
				rowin = rand() % 3;// makes row coordinates into a random number out of three // acts as second player or AI for singleplayer mode
				colin = rand() % 3;// makes column coordinates into a random number out of three // acts as second player or AI for singleplayer mode
			}
			
			map[colin][rowin] = "⭕";// couts a circle onto those random out of 3 coordinates in function above
			
			atie--;
			
			if(wait == 0)// random condition for if statement
			{
				if(map[0][0] == "⭕" && map[0][1] == "⭕" && map[0][2] == "⭕")// creates condition using cordinates if 3 "⭕"s in the frist row
				{
					output(map);//calls out function to output array
					
					cout << "You lose!" << endl;//couts you lose if AI meets conditions(3 "⭕"s )
					
					return 0;//ends code because player lost
				}
				else if(map[1][0] == "⭕" && map[1][1] == "⭕" && map[1][2] == "⭕")// creates condition using cordinates if 3 "⭕"s in the second row
				{
					output(map);//same as above
					
					cout << "You lose!" << endl;//same as above
					
					return 0;//same as above
				}
				else if(map[2][0] == "⭕" && map[2][1] == "⭕" && map[2][2] == "⭕")// creates condition using cordinates if 3 "⭕"s in the third row
				{
					output(map);
					
					cout << "You lose!" << endl;
					
					return 0;
				}
				else if(map[0][0] == "⭕" && map[1][0] == "⭕" && map[2][0] == "⭕")// creates condition using cordinates if 3 "⭕"s in the first column
				{
					output(map);
					
					cout << "You lose!" << endl;
					
					return 0;
				}
				else if(map[0][1] == "⭕" && map[1][1] == "⭕" && map[2][1] == "⭕")// creates condition using cordinates if 3 "⭕"s in the second column
				{
					output(map);
					
					cout << "You lose!" << endl;
					
					return 0;
				}
				else if(map[0][2] == "⭕" && map[1][2] == "⭕" && map[2][2] == "⭕")// creates condition using cordinates if 3 "⭕"s in the third column
				{
					output(map);
					
					cout << "You lose!" << endl;
					
					return 0;
				}
				else if(map[0][0] == "⭕" && map[1][1] == "⭕" && map[2][2] == "⭕")// creates condition using cordinates if 3 "⭕"s in a diagonal line left to right
				{
					output(map);
					
					cout << "You lose!" << endl;
					
					return 0;
				}
				else if(map[0][2] == "⭕" && map[1][1] == "⭕" && map[2][0] == "⭕")// creates condition using cordinates if 3 "⭕"s in a diagonal line right to left
				{
					output(map);// calls out function to output array
					
					cout << "You lose!" << endl;
				
					return 0;
				}
			}
			
			output(map);//calls output function to output array
		}
	}
	else if(input == 'm' || input == 'M')// condition if player chooses to player multiplayer
	{
	
		while(wait == 0)// condition if there more than zero free spaces/boxes
		{
			if(p1 == 1 && p2 == 0)// condition if player value is 1 and player 2 value is 0, theses are the values they start with and they change which allows for turns , This one specifically is used for player one to go 
			{
				cout << "Player 1, enter row coordinate(1-3): ";
			cin >> colin;//collects column coordinates input
			
			cout << "Player 1, enter column coordinate(1-3): ";
			cin >> rowin;//collects row coordinates input
			
			while(map[colin - 1][rowin - 1] != "⬛")//creates condition if column coordinates input and row coordinates input -1(so cordinates are more like normal coordiantes for graphs) is not an equal spot/black sqaure
			// this while loop is our safeguard/ boarders that does not allow user to pick the same spot / a spot taken/ or a spot outside of grid
			{
				cout << "This spot is already taken. Try again. " << endl << endl;
				
				cout << "Enter row coordinate(1-3): ";
				cin >> rowin;//collects row coordinates input
				
				cout << "Enter column coordinate(1-3): ";
				cin >> colin;//collects column coordinates input
			}
			map[colin - 1][rowin - 1] = "❌";// places an "❌" onto array on the row and column coordinates input
			
				
			
			if(wait == 0)// random condition for if statement
			{
				if(map[0][0] == "❌" && map[0][1] == "❌" && map[0][2] == "❌")// same as above
				{
					output(map);//same as above
					
					cout << "Player 1 wins!" << endl;//same as above
					
					return 0;//same as above
				}
				else if(map[1][0] == "❌" && map[1][1] == "❌" && map[1][2] == "❌")
				{
					output(map);
					
					cout << "Player 1 wins!" << endl;
					
					return 0;
				}
				else if(map[2][0] == "❌" && map[2][1] == "❌" && map[2][2] == "❌")
				{
					output(map);
					
					cout << "Player 1 wins!" << endl;
					
					return 0;
				}
				else if(map[0][0] == "❌" && map[1][0] == "❌" && map[2][0] == "❌")
				{
					output(map);
					
					cout << "Player 1 wins!" << endl;
					
					return 0;
				}
				else if(map[0][1] == "❌" && map[1][1] == "❌" && map[2][1] == "❌")
				{
					output(map);
					
					cout << "Player 1 wins!" << endl;
					
					return 0;
				}
				else if(map[0][2] == "❌" && map[1][2] == "❌" && map[2][2] == "❌")
				{
					output(map);
					
					cout << "Player 1 wins!" << endl;
					
					return 0;
				}
				else if(map[0][0] == "❌" && map[1][1] == "❌" && map[2][2] == "❌")
				{
					output(map);
					
					cout << "Player 1 wins!" << endl;
					
					return 0;
				}
				else if(map[0][2] == "❌" && map[1][1] == "❌" && map[2][0] == "❌")
				{
					output(map);
					
					cout << "Player 1 wins!" << endl;
					
					return 0;
				}
				p1--;//changes players 1 value (which we use to create a condition for a function for player 2 to go )
				p2++;//changes players 2 value (which we use to create a condition for a function for player 2 to go )
				

				output(map);//calls output function to output array
				
				if(atie == 0)//same as above
				{
				
				cout << " its a tie" << endl;//same as above
			 
				 return 0;//same as above
				}
				
				
				
			}
			if(p1 == 0 && p2 == 1)//conditions of players value which allows for turns
			{
				cout << "Player 2, enter row coordinate(1-3): ";
			cin >> colin;//collect column coordinates input
			
			cout << "Player 2, enter column coordinate(1-3): ";
			cin >> rowin;//collect row coordinates input
			
			while(map[colin - 1][rowin - 1] != "⬛")//same as above
			{
				cout << "This spot is already taken. Try again. " << endl << endl;
				
				cout << "Enter row coordinate(1-3): ";
				cin >> rowin;//same as above
				
				cout << "Enter column coordinate(1-3): ";
				cin >> colin;//same as above
			}
			map[colin - 1][rowin - 1] = "⭕";// couts an "⭕" to row and column coordinates input -1 (-1 is to make coordinates more like a graph coordinates)
			
			atie--;//subtracts to atie which holds amount of "⭕"s this is used to dedicate if theres a tie
			
			if(wait == 0)//random condition for if statement
			{
				if(map[0][0] == "⭕" && map[0][1] == "⭕" && map[0][2] == "⭕")//same as above
				{
					output(map);//same as above
					
					cout << "Player 2 wins!" << endl;//same as above
					
					return 0;//same as above
				}
				else if(map[1][0] == "⭕" && map[1][1] == "⭕" && map[1][2] == "⭕")
				{
					output(map);
					
					cout << "Player 2 wins!" << endl;
					
					return 0;
				}
				else if(map[2][0] == "⭕" && map[2][1] == "⭕" && map[2][2] == "⭕")
				{
					output(map);
					
					cout << "Player 2 wins!" << endl;
					
					return 0;
				}
				else if(map[0][0] == "⭕" && map[1][0] == "⭕" && map[2][0] == "⭕")
				{
					output(map);
					
					cout << "Player 2 wins!" << endl;
					
					return 0;
				}
				else if(map[0][1] == "⭕" && map[1][1] == "⭕" && map[2][1] == "⭕")
				{
					output(map);
					
					cout << "Player 2 wins!" << endl;
					
					return 0;
				}
				else if(map[0][2] == "⭕" && map[1][2] == "⭕" && map[2][2] == "⭕")
				{
					output(map);
					
					cout << "Player 2 wins!" << endl;
					
					return 0;
				}
				else if(map[0][0] == "⭕" && map[1][1] == "⭕" && map[2][2] == "⭕")
				{
					output(map);
					
					cout << "Player 2 wins!" << endl;
					
					return 0;
				}
				else if(map[0][2] == "⭕" && map[1][1] == "⭕" && map[2][0] == "⭕")
				{
					output(map);
					
					cout << "Player 2 wins!" << endl;
					
					return 0;
				}
				p1++;//changes player 1 value to meet conditions for function to work so its player ones can go again (its a loop)
				p2--;//changes player 1 value to meet conditions for function to work so its player ones can go again (its a loop) 
			}
			
			
			output(map);//calls function to output array
			
			
			}
		}
	}
	return 0;//ends code
}
}
void output(string map[][3])//output function
{
	for(int i = 0; i < row; i++)//loop checks every box in row 
	{
		for(int j = 0; j < col; j++)//loop that checks every box in column 
		{
			cout << setw(1) << map[i][j];// outputs array and set4 makes it pretty
		}
		cout << endl;// couts nothing extra space to make it pretty
	}
}