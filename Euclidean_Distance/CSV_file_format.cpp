#include"std_lib_facilities.h"
#include"time.h"
#include"fstream"
#include"string"
#include"windows.h"
#include"ctime"
#include "stdio.h"



class User {

public:

	string name;
	string Iname;
	double age;


	//Default Constructor
	
	User() {
		
		 username=" ";
		 password=" ";		 
		 name=" ";
		 Iname = " ";
		 age=0.0;


	}
	

	void setUsername(string name) {

		username = name;
		Iname = name; //for me so I can check something before I put it into username

	}

	void setPassword(string pass) {

		password = pass;


	}


	string getUsername() {		
		 
		return username;

	}

	string getPassword() {		

		return password;

	}

	~User() {};


private:
	//Member Variables

	string username;
	string password;

};



class Announcement {
public:

	string UserID;
	string message;
	string date;
};


int main(){

	string password;

	double age;
	char flag = 'T';
	int stop = 1;

	User Uinst_n;
	Announcement Ainst_u;
	Announcement Ainst_m;
	Announcement Ainst_d;

	ofstream myfile;
	myfile.open("announcements.csv");
	myfile << "UserID, Announcement, Date" << endl;


	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);


	cout << "Give me a name:";
	getline(cin, Ainst_u.UserID);

	cout << "Give me password:";
	cin >> password;

	Uinst_n.setUsername(Ainst_u.UserID);
	Uinst_n.setPassword(password);



	do {

		

		if (stop == 9) {

			flag = 'T';
			cout << "Give me a name:";
			getline(cin, Ainst_u.UserID);
			getline(cin, Ainst_u.UserID);

			cout << "Give me password:";
			cin >> password;

			Uinst_n.setUsername(Ainst_u.UserID);
			Uinst_n.setPassword(password);


		}


		do {

			if (flag != 'q') {

				cout << "Give message" << endl;
				getline(cin, Ainst_m.message);
			    getline(cin, Ainst_m.message);

				Ainst_d.date = asctime(timeinfo);

				myfile << Uinst_n.getUsername() << "," << Ainst_m.message << "," << Ainst_d.date << endl;
			}

			if (flag != 'q') {

				cout << "Do you want to stop? --> Press q" << endl;
				cin >> flag;

			}


		} while (flag != 'q');

		cout << "Press 0 to stop or press 9 to change the User" << endl;
		cin >> stop;

	} while (stop != 0);



	

	myfile.close();
	keep_window_open();

}