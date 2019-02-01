#ifndef TEXTPICTURE_PICTURE_H
#define TEXTPICTURE_PICTURE_H

#include <vector>
#include <cstring>
using std::string;
using std::vector;

void SplitString(const string& s, vector<string>& v, const string& c);
class picture {
public:
    friend picture& operator+(picture& p, string& s) {
        vector<string> v1;
        SplitString(p.pic, v1, "\n");
        for (int i = 0 ; i < v1.size() ; i++) {
            v1[i] += s;
        }
        p.pic = "";
        for (int i = 0 ; i < v1.size() - 1 ; i++) {
            p.pic += v1[i] + "\n";
        }
        p.pic += v1[v1.size() - 1];
        return p;
    }
    friend picture& operator+(string& s, picture& p) {
        return p + s;
    }
    picture() : pic("") {}
    picture(string*, int l);
    string value() {
        return pic;
    }
    string frame();
    picture& connectionL(picture&);
    picture& connectionP(picture&);
    picture(const picture&);
    picture& operator-=(picture&);
    picture& operator|=(picture&);
    picture& operator=(picture&);
    picture& operator+=(string&);
private:
    string pic;
};
picture& operator-(picture&, picture&);
picture& operator|(picture&, picture&);

#endif //TEXTPICTURE_PICTURE_H
