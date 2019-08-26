#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split(string input, char ch) {
    vector<string> rslt;
    string temp = "";

    bool preQ = false;

    string newin = "";
    for(int i = 0;i < input.size();i++) {
        auto it = input[i];
        if(it == '"' && (i+1 < input.size() && input[i+1] == '"')) {
            newin += "*";
            i++;
        } else {
            newin += it;
        }
    }
    input = newin;

    for(int i = 0;i < input.size();i++) {
        auto it = input[i];

        if(!preQ) {
            if(it == '"') {
                //if(i+1 >= input.size() || input[i+1] != '"')
                preQ = true;
                temp += it;
            } else if (it != ch) {
                temp += it;
            } else {
                //if(temp.size() > 0)
                    rslt.push_back(temp);
                temp = "";
            }
        } else {
            if(it == '"') {
                temp += it;
                //rslt.push_back(temp);
                //temp = "";
                preQ = false;
            } else {
                temp += it;
            }
        }
    }

    //if(temp.size() > 0)
        rslt.push_back(temp);

    vector<string> newrslt;
    for(const auto & tt : rslt) {
        string temp = "";
        for(const auto & item : tt) {
            if(item == '"') {
                continue;
            } else if(item == '*') {
                temp.push_back('"');
            } else {
                temp += item;
            }
        }
        newrslt.push_back(temp);
    }

    return newrslt;
}

int main() {
    ifstream infile;
    infile.open("input001.txt");
//
//    ofstream outfile;
//    outfile.open("output001.txt");

    string line;
    while(getline(infile, line)) {
        auto rslt = split(line, ',');
        cout<<line<<endl;
        for(const auto & it : rslt) {
            cout << it << "= ";
        }
        cout << " "<<rslt.size()<< endl;

        string output = "";

        //John "Mo", 23 years old, is from Seattle, WA and is interested in biking and hiking.;
        output += rslt[0] + ", " + rslt[6] + " years old, is from " + rslt[5] + " and is interested in " + rslt[3] + ".";
        cout<<output<<endl;
    }

    return 0;
}