#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<string> parse (string s) ;
bool cek (string slist, string s);
bool isSentenceValid (string s);
string removePeriod (string s) ;

class word {
    private :
        string content;
        char lbl;
        int loc;

    public :
        string getContent () {
            return content;
        }

        char getLbl () {
            return lbl;
        }

        int getLoc () {
            return loc;
        }

        word() { }
        word (string s, int lok) {
            //cout << "\n\tinitializing";
            content = s;
            //cout << "\n....Success filling content";
            loc = lok;
            //cout << "\n....Success filling loc";
            lbl = stringRec(s);
            //cout << "Current lbl : " << lbl << '\n';
            //cout << "\n....Success filling lbl";
        }
        word (char *s, int lok) {
            content = s;
            loc = lok;
            lbl = stringRec(s);
        }

        char stringRec (string s) {
        //cout << "\nstringRec is runing.....\n";
        char label = 'U';
        string sbj[] = {"aku", "kamu" , "dia" , "kami", "mereka"};
        string pdk[] = {"makan", "minum" , "pergi" , "datang", "mengangkat"};
        string obj[] = {"nasi", "pintu" , "air" , "payung", "kuliah"};
        string ket[] = {"di sekolah", "di kamar" , "ke telkom" , "bulan", "nilai"};
        // for (int i = 0;i < (sizeof(sbj)/sizeof(*sbj)); i++) {
        //    cout << sbj[i];
        //}


        if (s == "") {
            //cout << "/nS is empty";
            return 'U';
        } else {
            // cout << "Something is running\n";
            //cout << sbj[0] ;
            for (int i = 0; i < (sizeof(sbj)/sizeof(*sbj)); i++) {
                if (cek(sbj[i],s)) {
                    label =  'S';
                    break;
                }
            }
            for (int i = 0; i < (sizeof(pdk)/sizeof(*pdk)); i++) {
                if (cek(pdk[i],s)) {
                    label =  'P';
                    break;
                }
            }
            for (int i = 0; i < (sizeof(obj)/sizeof(*obj)); i++) {
                if (cek(obj[i],s)) {
                    label =  'O';
                    break;
                }
            }
            for (int i = 0; i < (sizeof(ket)/sizeof(*ket)); i++) {
                if (cek(ket[i],s)) {
                    label =  'K';
                    break;
                }
            }
        }
        return label;
    }

};

int main () {
    while (true) {
        system("cls");
        cout << "Subject    : {\"aku\", \"kamu\" , \"dia\" , \"kami\", \"mereka\"} \n";
        cout << "Predikat   : {\"makan\", \"minum\" , \"pergi\" , \"datang\", \"mengangkat\"}\n";
        cout << "Object     : {\"nasi\", \"pintu\" , \"air\" , \"payung\", \"kuliah\"}\n";
        cout << "Keterangan : {\"di sekolah\", \"di kamar\" , \"ke telkom\" , \"bulan\", \"nilai\"}\n";

        cout << "\nKata : ";
        string s;
        getline(cin,s);
        vector<string> stringVector = parse(removePeriod(s));
        word listw[stringVector.size()];
        int now = 0;
        //int limit = listword.size();
        string sentenceStruct = "";
        for (vector<string>::iterator it = stringVector.begin();
            it != stringVector.end(); it++) {
            //cout << *it << '\n';
            string stop = *it;
            listw[now] = word(stop,now);
            sentenceStruct = sentenceStruct + listw[now].getLbl();
            //cout << "\n\tintializer success";
            now ++;
        }
        cout << "Stucture Kalimat : " << sentenceStruct << '\n';
        if (isSentenceValid(sentenceStruct)) {
            cout << "Kalimat ini valid...\n";
        } else {
            cout << "Kalimat ini tidak valid...\n";
        }
        //cout << sentenceStruct << '\n';
       // cout << '\n' << s ;
       // cout << "\n" << stringRec(s) << '\n';
        system("pause");
    }
    return 0;
}




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
   // cout << '\t' <<temp << " the  rest \n";
    res.push_back(temp);
    return res;
}

bool cek (string slist, string s) {
    bool isInArray = false;
    string tempString = slist;
    if (s.size() != tempString.size()) {

    } else {
        vector<char> kc;
        vector<char> sc;
        for (int i = 0; i < tempString.size();i++) {
            kc.push_back(tempString[i]);
            sc.push_back (s[i]);
        }
        bool isEqual = true;
        for (int h = 0; h < kc.size(); h++) {
            isEqual = isEqual && (kc[h] == sc[h]);
        }
        isInArray = isInArray || isEqual;
    }
    return isInArray;
}


bool isSentenceValid (string s) {
    string legal[] = {"SP" , "SPO", "SPK", "SPOK"};
    bool valid = false;
    for (int i = 0 ; i < 4; i++) {
        valid = valid || (cek(legal[i],s));
    }
    return valid;
}

string removePeriod (string s) {
    //cout << "last character : " << s[s.size()-1] << '\n';

    if (s[s.size()-1] != '.') {
        return s;
    } else {
        string result = "";
        for (int i = 0 ; i < s[s.size()-1] ; i++) {
            //cout << "size of s : " << s.size();
            if (s[i] != '.') {
                //cout << "\n" << s[i] << "\n";
                result += s[i];
            } else if (s[i] == '.') {
                break;
            }
        }
        return result;
    }

}
