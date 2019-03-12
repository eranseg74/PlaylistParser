#include <iostream>
#include <string>

using namespace std;

string trim(string str) {

    string retVal = str;
    int lastPos = retVal.length() - 1;

    bool found = true;

    while(found == true && lastPos >= 0) {
        if(retVal.substr(lastPos, 1) == " ") {
            retVal = retVal.erase(lastPos, 1);
        } else if(retVal.substr(0, 1) == " ") {
            retVal = retVal.erase(0, 1);
        } else {
            found = false;
        }
        lastPos = retVal.length() - 1;
    }
    return retVal;
}

int main()
{
    while(true) {
        cout << "Enter a track or 'Q' to quit." << endl;
        string fullName = "";
        getline(cin, fullName);
        if(fullName == "q") {
            break;
        } else if (fullName.length() < 5){
            cout << "Please enter a track with more then five characters" << endl;
        } else {
            string artist = "";
            string title = "";
            size_t found = fullName.find(":");
            if(found != string::npos) {
                artist = trim(fullName.substr(0, found));
                title = trim(fullName.substr(found + 1, fullName.length() - found));
            } else {
                found = fullName.find("-");
                if(found != string::npos) {
                    title = trim(fullName.substr(0, found - 1));
                    artist = trim(fullName.substr(found + 1, fullName.length() - found - 1));
                } else {
                    int pos = -1;
                    found = fullName.find("by");
                    // Looping until the last occurrence of 'by'
                    while(found != string::npos) {
                        if(fullName.at(found - 1) == ' ' && fullName.at(found + 2) == ' ') {
                            pos = found;
                        }
                        found = fullName.find("by", found + 2);
                    }
                    if(pos != -1) {
                        title = trim(fullName.substr(0, pos - 1));
                        artist = trim(fullName.substr(pos + 2, fullName.length() - pos - 1));
                    } else { // Deals with all other options
                        cout << "Bad input" << endl;
                        title = "Empty";
                        artist = "Empty";
                    }
                }
            }
            cout << "TITLE: " << title << endl;
            cout << "ARTIST: " << artist << endl;
            cout << endl;
        }
    }
    return 0;
}
