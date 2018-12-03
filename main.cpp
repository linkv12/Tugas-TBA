#include <iostream>
#include <stdlib.h>
#include <vector>

// link_v12

using namespace std;




vector<string> parse (string s) {
    vector<string> res ;
    string temp = "";
    int jum = 0;
    const int limit = 3;
    for(int i = 0 ; i < s.size() ; i++) {
        if (s[i] != ' ') {
            temp += s[i];
        } else if (s[i] == ' '){
            if (jum < limit) {
                res.push_back(temp);
                temp = "";
            } else {
                temp += ' ';
            }
            jum += 1;
        }
    }
    cout << '\t' <<temp << "the  rest \n";
    res.push_back(temp);
    return res;
    }



    int main() {


        cout << "Masukan kata : ";
        string str;
        getline(cin,str);
        vector<string> listword = parse(str);
        for (vector<string>::iterator it = listword.begin();
            it != listword.end(); it++) {
                cout << *it << '\n';
        }


    system("pause");
    return 0;
}

