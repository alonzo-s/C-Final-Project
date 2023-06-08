#include <string>
using namespace std;


class Library
{
private:
	string title;
	string fName;
	string lName;
	string type;
	int year;
	string genre;

public:
	Library();
	Library(string ti,
		string fn,
		string ln,
		string ty,
		int yr,
		string gn);

	// Sets for private member variables
	bool setTitle(string ti);
	bool setFname(string fn);
	bool setLname(string ln);
	bool setType(string ty);
	bool setYear(int yr);
	bool setGenre(string gn);

	// Gets for private member variables
	string getTitle();
	string getFname();
	string getLname();
	string getType();
	int getYear();
	string getGenre();
};

// default constructor
Library::Library()
{
	title = "";
	fName = "";
	lName = "";
	type = "";
	year = 0;
	genre = "";
}

// initializing constructor
Library::Library(string ti, string fn, string ln, string ty, int yr, string gn)
{
	setTitle(ti);
	setFname(fn);
	setLname(ln);
	setType(ty);
	setYear(yr);
	setGenre(gn);
}

// sets for private member variables
bool Library::setTitle(string ti)
{
	if (ti.empty())
	{
		title = "Invalid";
		return false;
	}
	title = ti;
	return true;
}
bool Library::setFname(string fn)
{
	if (fn.empty())
	{
		fName = "Invalid";
		return false;
	}
	fName = fn;
	return true;
}
bool Library::setLname(string ln)
{
	if (ln.empty())
	{
		lName = "Invalid";
		return false;
	}
	lName = ln;
	return true;
}
bool Library::setType(string ty)
{
	if (ty.empty())
	{
		type = "Invalid";
		return false;
	}
	type = ty;
	return true;
}
bool Library::setYear(int yr)
{
	if (yr < 0)
	{
		year = 0;
		return false;
	}
	year = yr;
	return true;
}
bool Library::setGenre(string gn)
{
	if (gn.empty())
	{
		genre = "Invalid";
		return false;
	}
	genre = gn;
	return true;
}

// gets for private member variables
string Library::getTitle()
{
	return title;
}
string Library::getFname()
{
	return fName;
}
string Library::getLname()
{
	return lName;
}
string Library::getType()
{
	return type;
}
int Library::getYear()
{
	return year;
}
string Library::getGenre()
{
	return genre;
}