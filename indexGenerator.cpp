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
};

vector<Post> history;

void readIndex();
void writeIndex();
void writeToHTML();
string getHTMLFormat(Post input);
string getIndexFormat(Post input);


string getIndexFormat(Post input)
{
    return input.date + "|" + input.title + "|" + input.link;
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

