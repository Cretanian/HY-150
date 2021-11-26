#include "std_lib_facilities.h" // loading the library so I can use functions that I need

void function_show(int y, int x) { //function type void that shows with graphics the map to the user

	for (int row = 9; row >= 0; row--) {
		for (int col = 0; col < 10; col++) {

			cout << "[";

			if (x == col && y == row) {

				cout << "o ";

			}
			else {

				cout << "  ";

			}
			cout << "]";
		}
		cout << endl ;

	}

}

//----------------------------------------------------------------------

char function_menu(char move) { //char function that takes the move from the user and shows the menu

	do {	//loop that showing the menu and checks for incorrect inputs
		cout << endl << "Select move:" << endl;
		cout << "1. 'w' : translate the point by + 1 on the Y axis" << endl;
		cout << "2. 's' : translate the point by -1 on the Y axis" << endl;
		cout << "3. 'd' : translate the point by +1 on the X axis" << endl;
		cout << "4. 'a' : translate the point by -1 on the X axis" << endl;
		cout << "5. 'q' : terminating character. The program ends" << endl;
		cin >> move;

		if (move != 'w' && move != 's' && move != 'd' && move != 'a' && move != 'q') {

			cout << endl << "Don't know this -"<< move <<"- character sorry..Check the menu and try again!" << endl << endl;
		}
		keep_window_open();
	} while (move != 'w' && move != 's' && move != 'd' && move != 'a' && move != 'q');

	return move;

}

//----------------------------------------------------------------------




int main() //starts the main program
{
	char move = ' ';  //initialization 
	int y = 0, x = 0; //initialization
	do {	//basic loop of the program

		move = function_menu(move);

		if (move == 'q') { //checking if the user wants to leave the program

			cout << "Final Position!" << " Y:" << y << " X:" << x << endl;
			function_show(y, x);
			keep_window_open();

		}
		else {	//if the user types a correct letter we start checking witch one 

			if (move == 'w') {  //adds to Y axis if it's not more than 10

				if (y + 1 < 10) {
					y = y + 1;
					cout << "Current Position!" << " Y:" << y << " X:" << x << endl;

				}
				else {
					cout << "You can't go forward in the Y axis" << endl;
				}

			}
			else if (move == 's') {	//decreas to Y axis if it's not less than 0

				if (y - 1 >= 0) {
					y = y - 1;
					cout << "Current Position!" << " Y:" << y << " X:" << x << endl;

				}
				else {
					cout << "You can't go further back in the Y axis " << endl;
				}

			}
			else if (move == 'd') {		//adds to X axis if it's not more than 10

				if (x + 1 < 10) {
					x = x + 1;
					cout << "Current Position!" << " Y:" << y << " X:" << x << endl;

				}
				else {
					cout << "You can't go forward in the X axis" << endl;
				}

			}
			else if (move == 'a') {		//decreas to Y axis if it's not less than 0

				if (x - 1 >= 0) {
					x = x - 1;
					cout << endl << "Current Position!" << " Y:" << y << " X:" << x << endl;

				}
				else {
					cout << endl << "You can't go further back in the X axis " << endl << endl;
				}
			}
						
		}

		function_show(y, x);

	} while (move != 'q'); //checks if the user typed to leave the program

}