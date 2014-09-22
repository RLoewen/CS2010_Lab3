#include <iostream>
#include <cstdlib>
using namespace std;

void playGame();
int die();


int main( ) {
  srand(time(NULL));
  char ans;
  bool done = false;
  while ( ! done ) {
         playGame();   // YOU MUST WRITE THIS FUNCTION
         cout << " Play again (y/n) ? ";
         cin >> ans;
	cout << endl;
         if ( ans == 'n' || ans == 'N') done = true;
             else done = false;
  }
  return 0;
}
//function die() simulates rolling a dice with 6 sides then returns the value as an int
int die(){
 
return (rand() % 6 + 1); 

}
// roll() simulates rolling 2 6 sided dice then prints the results of each roll, the total and then outputs the total as an int
int roll(){
int dice_1=0;
int dice_2=0;

dice_1=die();
//cout<<dice_1<<"debug dice_1"<<endl;	// prints value in dice_1 for debugging
dice_2=die();
//cout<<dice_2<<"debug dice_2"<<endl;	// prints value in dice_2 for debugging

cout << "Player rolled " << dice_1 << " + " << dice_2 << " = " << (dice_1+dice_2)<<endl;

return (dice_1 + dice_2);

}

// playGame() uses the roll() function to get a score for every roll then evaluates it to determine whether the player 
void playGame(){


	bool over=0;
	int score=0;
	int num_rolls=0;
	int point=0;
while (!over){

	score=roll();

	// CHECK #1: 7/11 checks to see if the first roll is 7 or 11, if so player wins, then it records the # of 		rolls for possible statistics later
	if((num_rolls==0)&&(score==7||score==11))	
	{
		cout << "You rolled " << score<< ", you win!"<< endl<<endl;
		over = 1;
			
	}

	// CHECK #2: CRAPS check to see if the first roll is 2,3, or 12, if so then player rolled craps and 		looses, again rolls counted for statistics
	else if((num_rolls==0)&&(score==2||score==3||score==12))
	{
		cout << "You rolled craps, better luck next time" << endl<<endl;
		over = 1;
			
	}

	// CHECK #3: SET POINT if the first roll does not net a win/loss the player gets a point that equals 		'score', now the roll is needed to prevent the second roll from triggering the conditions in CHECK #1 and 		#2 
	
	else if((num_rolls==0)&&((score==4)||(score==5)||(score==6)||(score==8)||(score==9)||(score==10)))
	{
		cout << "Your point is: " << score << endl;
		point = score;
			 
	}
	// CHECK #4: LOOSE ON 7 if the player rolls 7 on any roll besides the first they loose
	else if((num_rolls!=0)&&(score==7))
	{
		cout << "You haven't scored your point yet, you loose!"<<endl<<endl;
		over=1;
		
	}
	// CHECK #5: HIT POINT if the player rolls their point they win
	else if((num_rolls!=0)&&(score==point))
	{
		cout << "You hit your point, you win!"<<endl<<endl;
		over=1;
		
	}
	
	num_rolls++;
	

}

}
