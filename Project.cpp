#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void librarian();
void student();
void addNewBook();
void removeBook();
void listAllBooks();
void checkreservation();
void searchbook();
void requestissue();
void returnbook();
void listAllBooks1();
void searchbook1();
string tolowercase(string str);

int counter = 0;

int main()
{
	string choice1;
    string username, password;
    string username2, password2;

    cout << "--------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "                  THE LITERARY LOUNGE LIBRARY SYSTEM" << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "\n\n";
	cout << "                           ----WELCOME----" << endl;
	cout << "\n\n";
	cout << "               A library is infinity under a roof" << endl;
	cout << "\n\n\n";
	cout << "Are you a student or a Librarian (S for Student, L for Librarian) : ";
	cin >> choice1;
	cout << endl;

	while (choice1 != "S" && choice1 != "L")
	{
		cout << "Error! (S for Student, L for Librarian) : ";
		cin >> choice1;
		if (choice1 == "S" || choice1 == "L")
			break;
	}

	system("CLS");

	if (choice1 == "L") 
	{
		do
		{
			cout << "Enter Username : ";
			cin >> username;
			cout << "Enter Password : ";
			cin >> password;

			if (username == "Admin")
			{
			    if (password == "Password")
	            {
			    system("CLS");
			    cout << "--------------------------------" << endl;
			    cout << "You have successfully logged in!" << endl;
			    cout << "--------------------------------" << endl;
			    librarian();
		        }
		        else if (password != "Password")
			    {
			    system("CLS");
			    cout << "-----------------" << endl;
			    cout << "Invalid Password!" << endl;
			    cout << "-----------------" << endl;
			    }
			}
			else
			{
				system("CLS");
				cout << "----------------------" << endl;
				cout << "Invalid Login details!" << endl;
				cout << "----------------------" << endl;
			}

		}while (username != "Admin" || password != "Password");
    }


	if (choice1 == "S") 
	{
		do
		{
			cout << "Enter Username : ";
			cin >> username2;
			cout << "Enter Password : ";
			cin >> password2;

			if (username2 == "Komal")
			{
				if (password2 == "komal")
				{
					cout << endl;
					system("CLS");
					cout << "--------------------------------" << endl;
					cout << "You have successfully logged in!" << endl;
					cout << "--------------------------------" << endl;
					student();
				}
				else if (password2 != "komal")
				{
					system("CLS");
					cout << "-----------------" << endl;
					cout << "Invalid Password!" << endl;
					cout << "-----------------" << endl;
				}
			}
			else
			{
				system("CLS");
				cout << "----------------------" << endl;
				cout << "Invalid Login details!" << endl;
				cout << "----------------------" << endl;
			}
        }while (username2 != "Komal" || password2 != "komal");
    }
}

void librarian() 
{
	int choice2;
    cout << endl;
	cout << "MAIN MENU for LIBRARIAN" << endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "[1] Add a new Book" << endl;
	cout << "[2] Remove a Book" << endl;
	cout << "[3] List of all Books" << endl;
	cout << "[4] Check Reservations" << endl;
	cout << "[5] Search for a Book" << endl;
	cout << "[6] Log out" << endl;
	cout << "[0] EXIT" << endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "Enter the choice : ";
	cin >> choice2;

	while (choice2 < 0 || choice2>6)
	{
		cout << "Invalid Choice!" << endl;
		cout << "Re-Enter Choice : ";
		cin >> choice2;

		if (choice2 > 0 && choice2 < 6)
			break;
	}

    switch (choice2)
	{
	case 1:
		system("CLS");
		addNewBook();
        break;

	case 2:
		system("CLS");
		removeBook();
		break;

	case 3:
		system("CLS");
		listAllBooks();
		break;

	case 4:
		system("CLS");
		checkreservation();
		break;

	case 5:
		system("CLS");
		searchbook();
		break;

	case 6:
		system("cls");
		main();
		break;

	case 0:
		system("cls");
		cout << "Exiting... GOODBYE!\n";
		exit(0);
		break;

	default:
		system("CLS");
		cout << "Invalid Choice!";
	}
}

void student()
{
	int choice3;
    cout << endl;
	cout << "MAIN MENU for STUDENT" << endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "[1] Issue Book" << endl;
	cout << "[2] Return Book" << endl;
	cout << "[3] List of all Books" << endl;
	cout << "[4] Search for a Book" << endl;
	cout << "[5] Log out" << endl;
	cout << "[0] EXIT" << endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "Enter the choice : ";
	cin >> choice3;

	while (choice3 < 0 || choice3>5)
	{
		cout << "Invalid Choice!" << endl;
		cout << "Re-Enter Choice : ";
		cin >> choice3;

		if (choice3 > 0 && choice3 < 5)
			break;
	}

	switch (choice3)
	{
	case 1:
		system("CLS");
		requestissue();
		break;

	case 2:
		system("CLS");
		returnbook();
		break;

	case 3:
		system("CLS");
		listAllBooks1();
		break;

	case 4:
		system("CLS");
		searchbook1();
		break;

	case 5:
		system("CLS");
		main();
		break;

	case 0:
		system("CLS");
		cout << "Exiting... GOODBYE!\n";
		exit(0);
		break;

	default:
		system("CLS");
	    cout << "Invalid Choice!";
	}
}

void addNewBook() 
{
	int x;
	cout << "In which section do you want to add a book?\n";
	cout << "[1] History" << endl;
	cout << "[2] Science" << endl;
	cout << "[3] English Novels" << endl;
	cout << "[4] Religion and Spirituality" << endl;
	cout << "[5] Art and Photography" << endl;
	cout << endl;
	cout << "Enter the choice: ";
	cin >> x;

	while (x < 1 || x > 5) 
	{
		cout << "Invalid Choice!" << endl;
		cout << "Re-Enter Choice : ";
		cin >> x;

		if (x > 0 && x < 6)
			break;
	}

	if (x == 1)
	{
		cin.ignore();
		fstream file("history.txt", ios::app);
		string str;
		string str2;
		string str3;
		cout << "Enter name of book you want to add: ";
		getline(cin, str);
		cout<<"Enter Author's Name':";
		getline(cin, str2);
		cout<<"Enter Book's description:";
		getline(cin,str3);
		file << endl;
		file << str << endl;
		file << "Author: "<<str2<<endl;
		file << str3;
		system("CLS");
		cout << "Book added successfully!\n";
		file.close();
		librarian();
	}

	else if (x == 2) 
	{
		cin.ignore();
		fstream file("science.txt", ios::app);
		string str;
		string str2;
		string str3;
		cout << "Enter name of book you want to add: ";
		getline(cin, str);
		cout<<"Enter Author's Name':";
		getline(cin, str2);
		cout<<"Enter Book's description:";
		getline(cin,str3);
		file << endl;
		file << str << endl;
		file << "Author: "<<str2<<endl;
		file << str3;
		system("CLS");
		cout << "Book added successfully!\n";
		file.close();
		librarian();
	}

	else if (x == 3) 
	{
		cin.ignore();
		fstream file("english.txt", ios::app);
		string str;
		string str2;
		string str3;
		cout << "Enter name of book you want to add: ";
		getline(cin, str);
		cout<<"Enter Author's Name':";
		getline(cin, str2);
		cout<<"Enter Book's description:";
		getline(cin,str3);
		file << endl;
		file << str << endl;
		file << "Author: "<<str2<<endl;
		file << str3;
		system("CLS");
		cout << "Book added successfully!\n";
		file.close();
		librarian();
	}

	else if (x == 4)
	{
		cin.ignore();
		fstream file("religion.txt", ios::app);
		string str;
		string str2;
		string str3;
		cout << "Enter name of book you want to add: ";
		getline(cin, str);
		cout<<"Enter Author's Name':";
		getline(cin, str2);
		cout<<"Enter Book's description:";
		getline(cin,str3);
		file << endl;
		file << str << endl;
		file << "Author: "<<str2<<endl;
		file << str3;
		system("CLS");
		cout << "Book added successfully!\n";
		file.close();
		librarian();
	}

	else if (x == 5) 
	{
		cin.ignore();
		fstream file("art.txt", ios::app);
		string str;
		string str2;
		string str3;
		cout << "Enter name of book you want to add: ";
		getline(cin, str);
		cout<<"Enter Author's Name':";
		getline(cin, str2);
		cout<<"Enter Book's description:";
		getline(cin,str3);
		file << endl;
		file << str << endl;
		file << "Author: "<<str2<<endl;
		file << str3;
		system("CLS");
		cout << "Book added successfully!\n";
		file.close();
		librarian();
	}

}

void removeBook() 
{
	system("CLS");
    int x;
	cout << "From which section do you want to remove a book ? \n";
	cout << "[1] History" << endl;
	cout << "[2] Science" << endl;
	cout << "[3] English Novels" << endl;
	cout << "[4] Religion and Spirituality" << endl;
	cout << "[5] Art and Photography" << endl;
	cout << endl;
	cout << "Enter the choice: ";
	cin >> x;

	while (x < 1 || x > 5) 
	{
		cout << "Invalid Choice!" << endl;
		cout << "Re-Enter Choice : ";
		cin >> x;

		if (x > 0 && x < 6)
			break;
	}

	if (x == 1) 
	{
	    cin.ignore();
		ifstream inFile("history.txt");

		string bookName;
		cout << "Enter the name of the book to remove: ";
		getline(cin, bookName);

		ofstream outFile("temp.txt");
		string line;
        int counter1=0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) != tolowercase(bookName))
			{
				outFile << line << endl;
			}
			else
			{
			    counter1++;	
			}	
		}
		if(counter1>0)
		{
			system("cls");
			cout << "Book removed successfully!\n";
		}

		inFile.close();
		outFile.close();

		remove("history.txt");
		rename("temp.txt", "history.txt");
		librarian();
	}

	else if (x == 2) 
	{
		cin.ignore();
		ifstream inFile("science.txt");

		string bookName;
		cout << "Enter the name of the book to remove: ";
		getline(cin, bookName);

		ofstream outFile("temp.txt");
		string line;
        int counter1=0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) != tolowercase(bookName))
			{
				outFile << line << endl;
			}
			else
			{
				counter1++;
			}
		}
		if(counter1>0)
		{
			system("cls");
		    cout << "Book removed successfully!\n";
		}

		inFile.close();
		outFile.close();

		remove("science.txt");
		rename("temp.txt", "science.txt");

		librarian();
	}

	else if (x == 3) 
	{
		cin.ignore();
		ifstream inFile("english.txt");

		string bookName;
		cout << "Enter the name of the book to remove: ";
		getline(cin, bookName);

		ofstream outFile("temp.txt");
		string line;
        int counter1=0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) != tolowercase(bookName))
			{
				outFile << line << endl;
			}
			else
			{
			    counter1++;	
			}	
		}
		if(counter1>0)
		{
			system("cls");
		    cout << "Book removed successfully!\n";
		}

		inFile.close();
		outFile.close();

		remove("english.txt");
		rename("temp.txt", "english.txt");

		librarian();
	}

	else if (x == 4) 
	{
		cin.ignore();
		ifstream inFile("religion.txt");

		string bookName;
		cout << "Enter the name of the book to remove: ";
		getline(cin, bookName);

		ofstream outFile("temp.txt");
		string line;
        int counter1=0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) != tolowercase(bookName))
			{
				outFile << line << endl;
			}
			else
			{
				counter1++;
			}
		}
		if(counter1>0)
		{
			system("cls");
		    cout << "Book removed successfully!\n";
		}

		inFile.close();
		outFile.close();

		remove("religion.txt");
		rename("temp.txt", "religion.txt");

		librarian();
	}

	else if (x == 5) 
	{
		cin.ignore();
		ifstream inFile("art.txt");

		string bookName;
		cout << "Enter the name of the book to remove: ";
		getline(cin, bookName);

		ofstream outFile("temp.txt");
		string line;
        int counter1=0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) != tolowercase(bookName))
			{
				outFile << line << endl;
			}
			else
			{
				counter1++;
			}	
		}
		if(counter1>0)
		{
			system("cls");
		    cout << "Book removed successfully!\n";
		}

		inFile.close();
		outFile.close();

		remove("art.txt");
		rename("temp.txt", "art.txt");

		librarian();
	}
}

void listAllBooks() 
{
	system("CLS");
    int x;
	cout << "Of which section due you want to see the book list?\n";
	cout << "[1] History" << endl;
	cout << "[2] Science" << endl;
	cout << "[3] English Novels" << endl;
	cout << "[4] Religion and Spirituality" << endl;
	cout << "[5] Art and Photography" << endl;
	cout << "[6] All Sections" << endl;
	cout << endl;
	cout << "Enter the choice: ";
	cin >> x;

	while (x < 1 || x > 6) 
	{
		cout << "Invalid Choice!" << endl;
		cout << "Re-Enter Choice : ";
		cin >> x;

		if (x > 0 && x < 7)
			break;
	}

	cout << endl << endl;

	if (x == 1) 
	{
		system("CLS");
		ifstream file("history.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++)
			{

                cout << str[i];
			
			}
			cout << endl;
		}
		file.close();
		librarian();
	}

	if (x == 2) 
    {
    	system("CLS");
		ifstream file("science.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{
                
				cout << str[i];

			}
			cout << endl;
		}
		file.close();
		librarian();
	}

	if (x == 3) 
	{
		system("CLS");
		ifstream file("english.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++)
		    {

                cout << str[i];

			}
			cout << endl;
		}
		file.close();
		librarian();
	}

	if (x == 4) 
	{
		system("CLS");
		ifstream file("religion.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{

            	cout << str[i];

			}
			cout << endl;
		}
		file.close();
		librarian();
	}

	if (x == 5)
    {
    	system("CLS");
		ifstream file("art.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{

                cout << str[i];

			}
			cout << endl;
		}
		file.close();
		librarian();
	}

	if (x == 6)
    {
    	system("CLS");
		ifstream file("history.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{
			
				cout << str[i];

			}
			cout << endl;
		}
		file.close();
		cout << endl;
		
		ifstream file1("science.txt");
		string str1;

		while (getline(file1, str1))
		{

			for (int i = 0; i < str1.size(); i++) 
			{
			
			    cout << str1[i];

			}
			cout << endl;
		}
		file1.close();
		cout << endl;
		
		ifstream file2("english.txt");
		string str2;

		while (getline(file2, str2))
		{

			for (int i = 0; i < str2.size(); i++)
			{
			
			    cout << str2[i];

			}
			cout << endl;
		}
		file2.close();
		cout << endl;
		
		ifstream file3("religion.txt");
		string str3;

		while (getline(file3, str3))
		{

			for (int i = 0; i < str3.size(); i++)
			{
			    
				cout << str3[i];

			}
			cout << endl;
		}
		file3.close();
		cout << endl;
		
		ifstream file4("art.txt");
		string str4;

		while (getline(file4, str4))
		{

			for (int i = 0; i < str4.size(); i++) 
			{
			    
				cout << str4[i];

			}
			cout << endl;
		}
		file4.close();
		librarian();
	}

}

void checkreservation() 
{
	system("CLS");
	cout << "Number of Reservations: " << counter << endl;
	cout << endl;
	ifstream file("details.txt");
	string str;

	while (getline(file, str))
	{

		for (int i = 0; i < str.size(); i++) 
		{
		   
		   cout << str[i];

		}
		cout << endl;
	}
	librarian();
}

string tolowercase(string str)
{
    string lowercaseStr = str;
    for (int i = 0; i < str.size(); i++) 
	{
        lowercaseStr[i] = tolower(lowercaseStr[i]);
    }
    return lowercaseStr;
}

void searchbook()
{
	system("CLS");
	int x;
	cout << "From which section do you want to search a book ? \n";
	cout << "[1] History" << endl;
	cout << "[2] Science" << endl;
	cout << "[3] English Novels" << endl;
	cout << "[4] Religion and Spirituality" << endl;
	cout << "[5] Art and Photography" << endl;
	cout << endl;
	cout << "Enter the choice: ";
	cin >> x;

	while (x < 1 || x > 5) 
	{
		cout << "Invalid Choice!" << endl;
		cout << "Re-Enter Choice : ";
		cin >> x;

		if (x > 0 && x < 6)
			break;
	}

	if (x == 1) 
	{
	    cin.ignore();
		ifstream inFile("history.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("cls");
				cout << "Book found!\n";
				counter1++;
		        break;
			}
		}

		if (counter1 == 0) 
		{
			system("cls");
			cout << "Book not found!\n";
		}

		inFile.close();
		librarian();
	}

	else if (x == 2) 
	{
		cin.ignore();
		ifstream inFile("science.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("cls");
				cout << "Book found!\n";
				counter1++;
				break;
			}

		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found!\n";
		}

		inFile.close();
		librarian();
	}

	else if (x == 3) 
	{
		cin.ignore();
		ifstream inFile("english.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{ 
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("cls");
				cout << "Book found!\n";
				counter1++;
				break;
			}
		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found!\n";
		}

		inFile.close();
		librarian();
	}

	else if (x == 4) 
	{
		cin.ignore();
		ifstream inFile("religion.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				counter1++;
				break;
			}
		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found!\n";
		}

		inFile.close();
		librarian();
	}

	else if (x == 5) 
	{
		cin.ignore();
		ifstream inFile("art.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				counter1++;
				break;
			}
		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found!\n";
		}

		inFile.close();
		librarian();
	}
}

void requestissue() 
{
	system("CLS");
	cin.ignore();
	string name;
    string number;
    
	fstream file("details.txt",ios::app);
	cout << "Enter your First Name: ";
	getline(cin, name);
	cout << "Enter you contact number: ";
	cin >> number;
	
	cout << endl;

	cout << "From which section do you want to get a book?\n";
	int x;
	cout << "[1] History" << endl;
	cout << "[2] Science" << endl;
	cout << "[3] English Novels" << endl;
	cout << "[4] Religion and Spirituality" << endl;
	cout << "[5] Art and Photography" << endl;
	cout << endl;
	cout << "Enter the choice: ";
	cin >> x;

	while (x < 1 || x > 5)
    {
		cout << "Invalid Choice!" << endl;
		cout << "Re-Enter Choice : ";
		cin >> x;

		if (x > 0 && x < 6)
			break;
	}

	if (x == 1)
	{
	    cin.ignore();
		ifstream inFile("history.txt");

		string bookName;
		cout << "Enter the name of the book to reserve: ";
		getline(cin, bookName);
		
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				cout << "Request sent successfully!\n";
				file << "Name: " << name << endl;
				file << "Contact Number: " << number << endl;
				file << "Section: History" << endl;
				file << "Book Name: "<< bookName<<endl;
				file.close();
				counter++;
				counter1++;
			}

		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found! Request could not be sent!\n";
		}

		inFile.close();

	}

	else if (x == 2) 
	{
		cin.ignore();
		ifstream inFile("science.txt");

		string bookName;
		cout << "Enter the name of the book to reserve: ";
		getline(cin, bookName);
		
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				cout << "Request sent successfully!\n";
				file << "Name: " << name << endl;
				file << "Contact Number: " << number << endl;
				file << "Section: Science" << endl;
				file << "Book Name: "<< bookName<<endl;
				file.close();
				counter++;
				counter1++;
			}

		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found! Request could not be sent!\n";
		}

		inFile.close();

	}

	else if (x == 3) 
	{
		cin.ignore();
		ifstream inFile("english.txt");

		string bookName;
		cout << "Enter the name of the book to reserve: ";
		getline(cin, bookName);
		
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				cout << "Request sent successfully!\n";
				file << "Name: " << name << endl;
				file << "Contact Number: " << number << endl;
				file << "Section: English Novels" << endl;
				file << "Book Name: "<< bookName<<endl;
				file.close();
				counter++;
				counter1++;
			}

		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found! Request could not be sent!\n";
		}

		inFile.close();

	}

	else if (x == 4) 
	{
		cin.ignore();
		ifstream inFile("religion.txt");

		string bookName;
		cout << "Enter the name of the book to reserve: ";
		getline(cin, bookName);
		
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				cout << "Request sent successfully!\n";
				file << "Name: " << name << endl;
				file << "Contact Number: " << number << endl;
				file << "Section: Religion & Spirtuality" << endl;
				file << "Book Name: "<< bookName<<endl;
				file.close();
				counter++;
				counter1++;
			}

		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found! Request could not be sent!\n";
		}

		inFile.close();


	}

	else if (x == 5) 
	{
		cin.ignore();
		ifstream inFile("art.txt");

		string bookName;
		cout << "Enter the name of the book to reserve: ";
		getline(cin, bookName);
		
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				cout << "Request sent successfully!\n";
				file << "Name: " << name << endl;
				file << "Contact Number: " << number << endl;
				file << "Section: Art & Photography" << endl;
				file << "Book Name: "<< bookName<<endl;
				file.close();
				counter++;
				counter1++;
			}

		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found! Request could not be sent!\n";
		}

		inFile.close();

	}
	
	student();
}

void returnbook() 
{
	system("CLS");
	cin.ignore();
	ifstream inFile("details.txt");

	string bookName;
	cout << "Enter the name of the book you have to return: ";
	getline(cin, bookName);
	string line;

	int counter1 = 0;
	while (getline(inFile, line))
	{
		if (tolowercase(line) == tolowercase(bookName))
		{
			system("CLS");
			cout << "Book returned successfully!\n";
			counter1++;
			fstream file("details.txt", ios::app);
			file << "BOOK RETURNED Already!\n ";
			file << endl << endl;
			file.close();
			counter--;
		}
	}

	if (counter1 == 0) 
	{
		system("CLS");
		cout << "Book not found to be returned in record!\n";
	}

	inFile.close();
	student();
}

void listAllBooks1() 
{
	system("CLS");
	int x;
	cout << "Of which section due you want to see the book list?\n";
	cout << "[1] History" << endl;
	cout << "[2] Science" << endl;
	cout << "[3] English Novels" << endl;
	cout << "[4] Religion and Spirituality" << endl;
	cout << "[5] Art and Photography" << endl;
	cout << "[6] All Sections" << endl;
	cout << endl;
	cout << "Enter the choice: ";
	cin >> x;

	while (x < 1 || x > 6) 
	{
		cout << "Invalid Choice!" << endl;
		cout << "Re-Enter Choice : ";
		cin >> x;

		if (x > 0 && x < 7)
			break;
    }

	cout << endl << endl;

	if (x == 1) 
	{
		system("CLS");
		ifstream file("history.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{
			    
				cout << str[i];

			}
			cout << endl;
     	}
        file.close();
		student();
	}

	if (x == 2) 
	{
		system("CLS");
		ifstream file("science.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{
			    
				cout << str[i];

			}
			cout << endl;
		}
		file.close();
		student();
	}

	if (x == 3) 
	{
		system("CLS");
		ifstream file("english.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{
			    
				cout << str[i];

			}
			cout << endl;
	    }
		file.close();
		student();
	}

	if (x == 4) 
	{
		system("CLS");
		ifstream file("religion.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{
			    
				cout << str[i];

			}
			cout << endl;
		}
		file.close();
		student();
	}

	if (x == 5) 
	{
		system("CLS");
		ifstream file("art.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{
			    
				cout << str[i];

			}
			cout << endl;
		}
		file.close();
		student();
	}

	if (x == 6) 
	{
		system("CLS");
		ifstream file("history.txt");
		string str;

		while (getline(file, str))
		{

			for (int i = 0; i < str.size(); i++) 
			{
			    
				cout << str[i];

			}
			cout << endl;
		}
		file.close();
        cout << endl;
		
		ifstream file1("science.txt");
		string str1;

		while (getline(file1, str1))
		{

			for (int i = 0; i < str1.size(); i++) 
			{
			    
				cout << str1[i];

			}
			cout << endl;
		}
        file1.close();
		cout << endl;
		
		ifstream file2("english.txt");
		string str2;

		while (getline(file2, str2))
		{

			for (int i = 0; i < str2.size(); i++) 
			{
			    
				cout << str2[i];

			}
			cout << endl;
		}
        file2.close();
		cout << endl;
		
		ifstream file3("religion.txt");
		string str3;

		while (getline(file3, str3))
		{

			for (int i = 0; i < str3.size(); i++) 
			{
			    
				cout << str3[i];

			}
			cout << endl;
		}
        file3.close();
		cout << endl;
		
		ifstream file4("art.txt");
		string str4;

		while (getline(file4, str4))
		{

			for (int i = 0; i < str4.size(); i++) 
			{
			    
				cout << str4[i];

			}
			cout << endl;
		}
		file4.close();
		student();
	}
}

void searchbook1() 
{
	system("CLS");
	int x;
	cout << "From which section do you want to search a book ? \n";
	cout << "[1] History" << endl;
	cout << "[2] Science" << endl;
	cout << "[3] English Novels" << endl;
	cout << "[4] Religion and Spirituality" << endl;
	cout << "[5] Art and Photography" << endl;
	cout << endl;
	cout << "Enter the choice: ";
	cin >> x;

	while (x < 1 || x > 5) 
	{
		cout << "Invalid Choice!" << endl;
		cout << "Re-Enter Choice : ";
		cin >> x;

		if (x > 0 && x < 6)
			break;
	}

	if (x == 1) 
	{
	    cin.ignore();
		ifstream inFile("history.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				counter1++;
				break;
			}
		}

		if (counter1 == 0) 
		{
	        system("CLS");
			cout << "Book not found!\n";
		}

		inFile.close();
		student();
	}

	else if (x == 2) 
	{
		cin.ignore();
		ifstream inFile("science.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				counter1++;
				break;
			}
		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found!\n";
		}

		inFile.close();
		student();
	}

	else if (x == 3) 
	{
		cin.ignore();
		ifstream inFile("english.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				counter1++;
				break;
			}

		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found!\n";
		}

		inFile.close();
		student();
	}

	else if (x == 4) 
	{
		cin.ignore();
		ifstream inFile("religion.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				counter1++;
				break;
			}

		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found!\n";
		}

		inFile.close();
		student();
	}

	else if (x == 5) 
	{
		cin.ignore();
		ifstream inFile("art.txt");

		string bookName;
		cout << "Enter the name of the book to search: ";
		getline(cin, bookName);
		string line;

		int counter1 = 0;
		while (getline(inFile, line))
		{
			if (tolowercase(line) == tolowercase(bookName)) 
			{
				system("CLS");
				cout << "Book found!\n";
				counter1++;
				break;
			}
		}

		if (counter1 == 0) 
		{
			system("CLS");
			cout << "Book not found!\n";
		}

		inFile.close();
		student();
	}
}
