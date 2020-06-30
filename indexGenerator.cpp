#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

#define DOMAIN_NAME  "jacobsblog.github.io";

struct Post
{
    string title;
    string link;
    string date;
    int numDate;
};

vector<Post> history;

string intDateToString(int intFormat);
void readIndex();
void writeIndex();
void writeToHTML();
string getHTMLFormat(Post input);
string getIndexFormat(Post input);

string intDateToString(int intFormat)
{
    string day, month, year;
    day = to_string(intFormat % 100);
    intFormat /= 100;

    //find month
    switch (intFormat % 100)
    {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 11:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
    
    default:
        month = "INVALID MONTH";
        break;
    }
    intFormat /= 100;

    //get year
    year = "20" + to_string(intFormat % 100);

    return month + " " + day + ", " + year;
}

string getIndexFormat(Post input)
{
    return input.numDate + "|" + input.title + "|" + input.link;
}

string getHTMLFormat(Post input)
{
    return "<li>" + input.date + " - <a href=\"" + input.link
           + ">" + input.title + "</a></li>";
}

void writeIndex()
{
    std::ofstream ofs;
    ofs.open("./history.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofstream indexOut("./history.txt");
    for (auto it = history.begin(); it < history.end(); it++)
    {
        indexOut << getIndexFormat(*it) << endl;
    }
}

void writeToHTML()
{
    std::ofstream ofs;
    ofs.open("./chrono_index.html", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofstream htmlOut("./chrono_index.html");
    ifstream headerIn("./html_header.txt");

    // place header
    string temp;
    while (!headerIn.eof())
    {
        headerIn >> temp;
        htmlOut << temp << " ";
    }
    htmlOut << endl << endl << "<body>\n <h1>Blog History</h1>\n"
            << "<h3><a href=\"./index.html\">Back to Home</a></h3>\n"
            << "<hr>\n";

}

