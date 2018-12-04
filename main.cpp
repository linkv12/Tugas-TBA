#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

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
            lbl = tipe(s);
            //cout << "Current lbl : " << lbl << '\n';
            //cout << "\n....Success filling lbl";
        }
        word (char *s, int lok) {
            content = s;
            loc = lok;
            lbl = tipe(s);
        }

        char tipe (string s) {
            char label = 'U';
           // Ganti string ini untuk menambah atau mengurangi kata
            string sbj[] = {"aku", "kamu" , "dia" , "kami", "mereka"};
            string pdk[] = {"makan", "minum" , "pergi" , "datang", "mengangkat"};
            string obj[] = {"nasi", "pintu" , "air" , "payung", "kuliah"};
            string ket[] = {"di sekolah", "di kamar" , "ke telkom" , "bulan", "nilai"};

            // test subject
            for (int i = 0;i < (sizeof(sbj)/sizeof(*sbj)) ; i++) {
                //cout << "\n testing is subject";
                int sizeofs = s.size();
                int sizeofit = sbj[i].size();
                if (sizeofit == sizeofs) {
                    for (int j = 0; i < sbj[i].size(); i++) {
                        if (sbj[i][j] != s[j]) {
                            break;
                        }
                        lbl = 'S';
                    //cout << "Subject identified as " << s << "\n";
                    return 'S';
                    }
                }
            }

            //test predikat
            for (int i = 0;i < (sizeof(pdk)/sizeof(*pdk)) ; i++) {
                //cout << "\n testing is predikat";
                int sizeofs = s.size();
                int sizeofit = pdk[i].size();
                if (sizeofit == sizeofs) {
                    for (int j = 0; i < pdk[i].size(); i++) {
                        if (pdk[i][j] != s[j]) {
                            break;
                        }
                        lbl = 'P';
                    //cout << "Predikat identified as " << s << "\n";
                    return 'P';
                    }
                }
            }

            //test object
            for (int i = 0;i < (sizeof(obj)/sizeof(*obj)) ; i++) {
                //cout << "\n testing is Object";
                int sizeofs = s.size();
                int sizeofit = obj[i].size();
                if (sizeofit == sizeofs) {
                    for (int j = 0; i < obj[i].size(); i++) {
                        //cout << "screening object : " << obj[i];
                        if (obj[i][j] != s[j]) {
                            break;
                        }
                        lbl = 'O';
                    //cout << "Object identified as " << s << "\n";
                    return 'O';
                    }
                }
            }

            //test keterangan
            for (int i = 0;i < (sizeof(ket)/sizeof(*ket)) ; i++) {
                //cout << "\n testing is Keterangan";
                int sizeofs = s.size();
                int sizeofit = ket[i].size();
                if (sizeofit == sizeofs) {
                    for (int j = 0; i < ket[i].size(); i++) {
                        if (ket[i][j] != s[j]) {
                            break;
                        }
                    //cout << "Keterangan identified as " << s << "\n";
                    lbl = 'K';
                    return 'K';
                    }
                }
            }
            return label;
        }

};


bool isSenteceLegal (string s) {
    string legal[] = {"SP" , "SPO", "SPK", "SPOK"};
    if (s != "") {
        int sizeofs = s.size();
        bool isLegal = false;
        for (int i = 0; i < (sizeof(legal)/sizeof(*legal)); i++) {
            if (s[i] != 'U') {
                bool temp = true;
                if (sizeofs == legal[i].size()) {
                    for (int j = 0; j < sizeofs ; j++) {
                        if (legal[i][j] == 'U') {
                            temp = temp && false;
                        } else if (legal[i][j] == s[j]) {
                            temp = temp && true;
                        }
                    }
                } else {
                    temp = false;
                }
            isLegal = isLegal || temp;
            //cout << "isLegal  : " << isLegal ;

            } else {
                return false;
            }
        }
    return isLegal;
    } else {
        return false;
    }
    return false;
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




  int main() {
        while (true) {
            cout << "Subject    : {\"aku\", \"kamu\" , \"dia\" , \"kami\", \"mereka\"} \n";
            cout << "Predikat   : {\"makan\", \"minum\" , \"pergi\" , \"datang\", \"mengangkat\"}\n";
            cout << "Object     : {\"nasi\", \"pintu\" , \"air\" , \"payung\", \"kuliah\"}\n";
            cout << "Keterangan : {\"di sekolah\", \"di kamar\" , \"ke telkom\" , \"bulan\", \"nilai\"}\n";
            cout << "Masukan kata : ";
            string str;
            getline(cin,str);
            str = removePeriod(str);
            //cout << "After cleaning  : " << str << "\n";
            vector<string> listword = parse(str);
            word listw[listword.size()];
            int now = 0;
            //int limit = listword.size();
            for (vector<string>::iterator it = listword.begin();
                it != listword.end(); it++) {
                //cout << *it << '\n';
                string stop = *it;
                listw[now] = word(stop,now);
                //cout << "\n\tintializer success";
                now ++;
            }
            //string yy = listw[0].getContent();
            //cout << yy << "sadasd \n";


            string sentStruct = "";
            //cout << sentStruct << "\n\n\n\n\n\n\n";
            for (int i = 0 ; i < listword.size(); i++) {
                //for (int i = 0; i < sentStruct.size() ; i++) {
                sentStruct += listw[i].getLbl();
               // cout << "content " << i << " " << listw[i].getContent()<<"\n";
               // cout << "label " << i << " " << listw[i].getLbl()<<"\n";
               // cout << "loc " << i << " " << listw[i].getLoc()<<"\n";
            //}
            }
            cout << "Struct is "<<sentStruct << "\n";
            //sentStruct = "SPOK";
            if (isSenteceLegal(sentStruct)) {
                cout << "Kalimat ini valid...\n";
            } else {
                cout << "Kalimat tidak valid ...\n";
            }
            system("pause");
            system("cls");
        }


    return 0;
}
//SP----SPO-----SPK-------SPOK


