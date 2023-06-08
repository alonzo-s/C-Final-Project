


/*
"C:\\Users\\NAME\\--\\Project\\..."
*/



#include "library.h"

int main()
{
	
	string sFileLine;
	vector<string> sParsedLine;
	vector<Library> lib;
	
	ifstream fin;
	ofstream fout;
	openFiles(fin, fout);
	
	while (!fin.eof())
	{
		lib.push_back(readFile(sFileLine, sParsedLine, fin));
	}
	
	int sArraySize = lib.size();
	
	//Declare variable
	char again = 'Y';
	int selection;
	string typ;
	
	// Do-While loop to display report menu.
	do{
		cout << "--------Reports Menu--------" << endl;
		cout << "1. Display Entire Library\n"
			<< "2. Sort by Ascending Order\n"
			<< "3. Search by Specific Type (movie, book, type)\n"
			<< "0. Exit Program\n" 
			<< "---------------------------------" << endl << endl;
		cout << "Enter the number of the report you wish to run: ";
		cin >> selection;

		// Validate input and checks if integer was inputted
		while (!cin || selection < 0 || selection > 3)					
		{
			if (!cin)
			{
				cout << "Integer was not inputted." << endl;
				cout << "Choose a report from the menu above "; 
				cin.clear();
				cin.ignore();
				cin >> selection;
			}
			else if(selection < 0 || selection > 3)
			{
				cout << "Invalid Input" << endl;
				cout << "Choose a report from the menu above." << endl;
				cin >> selection;
			}
		}
		
		if (selection == 3)
		{
			cout << "What type of media do you want to see a report on? (movie, book, music) ";
			cin >> typ;
			if (typ == "movie")
			{
				typ = "Movie";
			}
			else if(typ == "book")
			{
				typ = "Book";
			}
			else if(typ == "music")
			{
				typ = "Music";
			}
			fout.close();
			fout.open("C:\\Users\\Alonzo\\Desktop\\Project\\librarySpecificType.txt");
			reportHead(fout);
			for (int i=0; i < sArraySize; i++)
			{
				writeFile(lib[i], fout, typ);
			}
		}
		
		if (selection == 2)
		{
			fout.close();
			fout.open("C:\\Users\\Alonzo\\Desktop\\Project\\libraryAscending.txt");
			reportHead(fout);
			bubbleSort(lib);
			for (int i=0; i< sArraySize; i++)
			{
				writeFile(lib[i], fout);
			}
		}
		
		if (selection == 1)
		{
			fout.close();
			fout.open("C:\\Users\\Alonzo\\Desktop\\Project\\libraryMedia.txt");
			reportHead(fout);
			for (int i=0; i < sArraySize; i++)
			{
				writeFile(lib[i], fout);
			}
		}
	
		// Asks user if they wish to run another report
		cout << "Do you want to run another report?(Y/N) ";
		cin >> again;
		cout << endl;

	
	}while (again == 'Y' || again == 'y');
	// Outputs menu to user

	
	return 0;
}

void openFiles(ifstream &in, ofstream &out)
{
	in.open("C:\\Users\\Alonzo\\Desktop\\Project\\library.txt");
	if (!in)
	{
		cout << "Input file did not open." << endl;
		cout << "Program will end." << endl;
		exit(0);
	}
	
	out.open("C:\\Users\\Alonzo\\Desktop\\Project\\librarymedia.txt");
	if (!out)
	{
		cout << "Output file did not open." << endl;
		cout << "Program will end." << endl;
		exit(0);
	}
}

Library readFile(string &sLine, vector<string> &sParsed, ifstream &fin)
{
	getline(fin, sLine);
	stringstream lineStream(sLine);
	string field;
	sParsed.clear();
	
	while (getline(lineStream, field, ','))
	{
		sParsed.push_back(field);
	}
	
	return Library(sParsed[0], sParsed[1], sParsed[2], sParsed[3], stoi(sParsed[4]), sParsed[5]);
}

void writeFile(Library li, ofstream &fout)
{

	fout << left << setw(32) << li.getTitle()
		<< left << setw(15) << li.getFname()
		<< left << setw(20) << li.getLname()
		<< left << setw(10) << li.getType()
		<< left << setw(10) << li.getYear()
		<< left << setw(10) << li.getGenre()
		<< endl;
}

void reportHead(ofstream &fout)
{
	fout << "" << setw(60) << "Media Libray" << endl
		<< "====================================================================================================" << endl
		<< "Title" << setw(36) << "First Name" << setw(14) << "Last Name" << setw(16) << "Type" << setw(10) << "Year" << setw(12) << "Genre" << endl
		<< "----------------------------------------------------------------------------------------------------" << endl; 
}

void bubbleSort(vector<Library> &l)
{
	Library temp;
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < long(l.size() - 1); count++)
		{
			if (l[count].getTitle() > l[count + 1].getTitle())
			{
				temp = l[count];
				l[count] = l[count + 1];
				l[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void writeFile(Library li, ofstream &outFile, string typ)
{
	if (typ == li.getType())
	{
		outFile << left << setw(32) << li.getTitle()
		<< left << setw(15) << li.getFname()
		<< left << setw(20) << li.getLname()
		<< left << setw(10) << li.getType()
		<< left << setw(10) << li.getYear()
		<< left << setw(10) << li.getGenre()
		<< endl;
	}
}