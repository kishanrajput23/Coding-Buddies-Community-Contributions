#include <iostream>
#include <fstream>

using namespace std;

int bookOptions() {
	cout << "1. Add Book"<< endl;
	cout << "2. Update Book"<< endl;
	cout << "3. Delete Book"<< endl;
	cout << "4. Show All Books"<< endl;
	cout << "0. Exit"<< endl;
	cout << "--- Choose any one option ---" << endl;
	cout << "Enter one option: ";

	int selectedOption = 0;
	cin >> selectedOption;
	cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); 

	return selectedOption;
}


void addBook() {
	string bookTitle, bookAuthor, bookDetail, line;
	int count = 0;

	cout << endl << "--- Provide Book Details ---" << endl;
	cout << "Title: ";
	getline(cin, bookTitle);
	cout << "Author: ";
	getline(cin, bookAuthor);

	// reading file for number of books
	ifstream countData("library.dat");
	while (getline(countData, line)) {
		count++;
	}

	countData.close();

	// open file for writing
	ofstream writeToLibrary;

    writeToLibrary.open("library.dat", ios::app);

	bookDetail = to_string(count) + ", " + bookTitle + ", " + bookAuthor;

	// write
	writeToLibrary << bookDetail << endl;

	// close the opened file.
    writeToLibrary.close();
	
   	cout << "Book added: " << bookDetail << endl; 
}


void UpdateBook() {
	cout << endl << "--- Update Book ---" << endl;
	string id;
	cout << "Enter Book ID: ";
	cin >> id;
	cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); 

	bool bookExist = false;
	ifstream data("library.dat");
	ofstream temp;
	temp.open("temp.dat", ios::app); //Temporary file

	if(!data || !temp)
    {
        cout << "Error opening files!" << endl;
        return;
    }

	string strTemp;
    while(getline(data, strTemp))
    {   
		size_t found = strTemp.find(id); 
		if (found != string::npos) {
			string title, author;

			cout << "Book: " << strTemp << endl; 

			cout << "New Book Title: ";
			getline(cin, title);
			cout << "New Book Author: ";
			getline(cin, author);

			strTemp = id + ", " + title + ", " + author;
			bookExist = true;
		}
		temp << strTemp << endl;
	}

	data.close();
	temp.close();

	if(bookExist) {
		// delete old file
		if( remove( "library.dat" ) != 0 )
			perror( "Error deleting file" );

		// rename new file to old file
		if ( rename("temp.dat", "library.dat")) {
			perror("Error renaming");
			return;
		}

		cout << "Book Details Updated" << endl; 

	} else cout << "No book found with ID " << id << endl;
}


void DeleteBook() {
	cout << endl << "--- Delete Book ---" << endl;
	string id;
	cout << "Enter Book ID: ";
	cin >> id;
	cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); 

	bool bookExist = false;
	ifstream data("library.dat");
	ofstream temp;
	temp.open("temp.dat", ios::app); //Temporary file

	if(!data || !temp)
    {
        cout << "Error opening files!" << endl;
        return;
    }

	string strTemp;
	bool delBook = false;
    while(getline(data, strTemp))
    {   
		size_t found = strTemp.find(id); 
		if (found != string::npos) {
			cout << "Book: " << strTemp << endl; 
			bookExist = true;
			delBook = true;
		}
		if(delBook) {
			delBook = false;
			continue;
		}
		temp << strTemp << endl;
	}

	data.close();
	temp.close();

	if(bookExist) {

		// delete old file
		if( remove( "library.dat" ) != 0 )
			perror( "Error deleting file" );

		// rename new file to old file
		if ( rename("temp.dat", "library.dat")) {
			perror("Error renaming");
			return;
		}

		cout << "Book Deleted" << endl; 

	} else cout << "No book found with ID " << id << endl;
}


void showBooks() {
	cout << "--- List of books ---" << endl;

	ifstream data("library.dat");
    string row;
    while(getline(data, row))
    {   
        cout << row << endl;
    }
}


void bookActions(int option) {
	switch(option) {
		case 1: 
			addBook();
			break;
		case 2: 
			UpdateBook();
			break;
		case 3: 
			DeleteBook();
			break;
		case 4: 
			showBooks();
			break;
	}
}


void home () {
	int option = bookOptions();
	if (option != 0 && option <= 4) {
		bookActions(option);
	} else if (option > 4) {
		cout << endl << "!!! Enter Valid Option !!!" << endl;
		option = bookOptions();
	} else {
	 	exit(0);
	}
}


int main () {
	cout << "*** WELCOME ***";
	string yn;
	while(true) {
		cout << endl << "--- Library Management System ---" << endl;
		home();
		cout << endl << "continue? (y/n) :";
		cin >> yn;
		if(yn != "y") break;
	}
	return 0;
}
