#include"std_lib_facilities.h"//loading the main library
#include"vector"//loading the vector library cause I use vectors
#include"math.h"//loading tha math.h library cause I need it for abs


double add(double a, double b, double sum) {//double function that returns the distance between two points
	
	sum = abs(b - a);
	
	return sum;
}


double recursion(double *a, double *b,int size, double sum) {//calling head recursion function to calculate the distance


	if (size>=0) {
		
		return (add(a[size],b[size],size) + abs(recursion(&a[0], &b[0], size - 1, sum)));
	}
	else if(size==-1) {

		return sum;
	}
	 
}

double Manhattan_Distance(double *A, double *B, int size) {
		
	double sum=0 ;

	return recursion(&A[0], &B[0], size, sum);
}


double get_number(double numb,int i,int point) { //double function that initialazing the vectors with the given points


	do { //loop that difines the same number axis with the correct inputs and inform the user 
		if (point == 1) {
			cout << "Give me the " << i << "st number for the first point in domain [0, 10]!" << endl;
		}
		else {
			cout << "Give me the " << i << "st number for the second point in domain [0, 10]!" << endl;

		}

		cin >> numb;

		if (numb > 10 || numb < 0) {
			cout << "Wrong input..Try again!" << endl;
		}

	} while (numb > 10 || numb < 0);

	return numb;
}


int main() //starts the program
{
	vector<double> A;//first point vector
	vector<double> B;//second point vector
	A.reserve(20);//reserve the cells to protect the memory
	B.reserve(20);//reserve the cells to protect the memory

	double dist = 0; //variable tha contains the distance


	// initialize the vectros in this block
	{
		int i = 1,point=0;
		char flag = 'a';
		double numb = 0;

		while (flag != 'q') {

			point = 1;
			A.push_back(get_number(numb, i, point)); // take numbers for the first point


			point = 2;
			B.push_back(get_number(numb, i, point)); // take numbers for the second point

			cout << "Press 'q' to stop! " << endl; //char that ends the block
			cin >> flag;

			++i; //moving in the next axis

			if (i == 20) { //ending the block based on reserve
				cout << "Can't give another number..Sorry!" << endl;
				flag = 'q';
			}

		}
	}
	//end of the block

	dist = (Manhattan_Distance(&A[0], &B[0], A.size())*0.1);//getting the distance from the function
	cout << "The Manhattan Distance for the given points A,B is d(A,B)= " << dist << endl;//informing
	keep_window_open();
	keep_window_open();
}//end of program