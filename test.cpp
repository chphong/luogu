#include <iostream>
#include <vector>

using namespace std;

int isalpha(char ch) {return ch>='a' && ch<='z';}
int isdigit(char ch) {return ch>='0' && ch<='9';}

int check(char pre, char suf) {
    return (isalpha(pre)&&isalpha(suf) || isdigit(pre)&&isdigit(suf));
}

int main() {
    int p1, p2, p3;
    string str;
    cin >> p1 >> p2 >> p3 >> str;
    
    vector<char> res;
    
    for (int i = 0; i<str.size(); i++) {
        char ch = str[i];
        char pre, suf;
        if (ch=='-' && i>0 && i<str.size()-1) {
            pre = str[i-1];
            suf = str[i+1];
            if (check(pre, suf)) {
                if (pre>=suf) {
                    res.push_back(ch);
                } else if(pre+1==suf) {
                    
                } else {
                    // 使用参数
                    int len = suf-pre-1;
                    if (p1==3) {
                        for (int j=0; j<len*p2; j++) {
                            res.push_back('*');
                        }
                    } else {
                        if (isalpha(pre) && p1==2) {
                            pre = 'A'+pre-'a';
                            suf = 'A'+suf-'a';
                        }
                        
                        if (p3==1) {
                            for (int j = pre+1; j<suf; j++) {
                                for (int k = 0; k<p2; k++) {
                                    res.push_back((char)j);
                                }
                            }
                        } else {
                            for (int j = suf-1; j>pre; j--) {
                                for (int k = 0; k<p2; k++) {
                                    res.push_back((char)j);
                                }
                            }
                        }
                        
                    }
                }
            } else {
                res.push_back(ch);
            }
        } else {
            res.push_back(ch);
        }
        
    }
    
    for(char ch:res) cout << ch;
    
    return 0;
}