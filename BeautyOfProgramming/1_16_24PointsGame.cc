#include <cstring>
#include <iostream>
#include <cmath>
#include <fstream>
#include "Util_Set1.cc"
using namespace std;

bool Equal(double v1, double v2) {
    return fabs(v1-v2) < 0.000001;
}
class Element {
private:
public:
    vector<string> expressions_;
    friend class Element;
    double value_;
    Element();
    Element(unsigned int v);
    string ShowExpressions();
    void Merge(Element e);
    static bool compare(Element e1, Element e2);
    friend Element Calculate(Element &e1, Element &e2, char op);
};
Element::Element() {
    ;
}
Element::Element(unsigned int v) {
    value_ = v;
    expressions_.push_back(std::to_string(v));
}
bool Element::compare(Element e1, Element e2) {
    return e1.value_ < e2.value_;
}
string Element::ShowExpressions() {
    string res;
    for(int i=0; i<expressions_.size(); ++i) {
        res += expressions_[i] + ";\n";
    }
    return res;
}
void Element::Merge(Element e) {
    if(e.value_ != value_) {
        cout << "Frankie said: Merge on different value!" << endl;
        throw -1;
    }
    for(int i=0; i<e.expressions_.size(); ++i) {
        expressions_.push_back(e.expressions_[i]);
    }
}
Element Calculate(Element e1, Element e2, char op) {
    Element res_elem;
    switch(op) {
        case '+':
            res_elem.value_ = e1.value_ + e2.value_;
            break;
        case '-':
            res_elem.value_ = e1.value_ - e2.value_;
            break;
        case '*':
            res_elem.value_ = e1.value_ * e2.value_;
            break;
        case '/':
            if(Equal(e2.value_, 0)) {
//                cout << "Frankie said: devide by zero!" << endl;
                break;
            }
            res_elem.value_ = e1.value_ / e2.value_;
            break;
        default:
            cout << "You inputed illegal operator. Only \"+ - * /\" is legal." << endl;
            throw -1;
    }
    for(int i=0; i < e1.expressions_.size(); ++i) {
        for(int j=0; j < e2.expressions_.size(); ++j) {
            string s = "( " + e1.expressions_[i] + " " + op + " " + e2.expressions_[j] + " )";
            res_elem.expressions_.push_back(s);
        }
    }
    return res_elem;
}
template Set1<Element> Union<Element>(Set1<Element> &, const Set1<Element> &, bool (*compare)(Element, Element));
class Points24Game {
private:
    double terminal_;
    unsigned int cards_num_;
    Set1<Element> *S_;
public:
    Points24Game();
    ~Points24Game();
    Set1<Element>& Fork(int s);
    void Process();
    friend Set1<Element> Cal(Set1<Element> &s1, Set1<Element> &s2);
};
Points24Game::Points24Game() {
    cout << "Please input the value_ need to go:";
    cin >> terminal_;
    cout << "Please input the number of cards:";
    cin >> cards_num_;
    S_ = new Set1<Element>[static_cast<int>(pow(2, cards_num_)+0.5)];
//    memset(S_, 0, static_cast<int>(pow(2, cards_num_)+0.5)*sizeof(Element));
    int index_S = 1;
    for(int i=1; i<=cards_num_;++i) {
        cout << "Please input the number of " << i << "th card:";
        unsigned int card_num;
        cin >> card_num;
        S_[index_S].AddElement(Element(card_num));
        index_S *= 2;
    }
}
Points24Game::~Points24Game() {
//    delete S_;
}
Set1<Element> Cal(Set1<Element> &s1, Set1<Element> &s2) {
    Set1<Element> res_set;
    for(int i=0; i < s1.GetSetSize(); ++i) {
        for(int j=0; j < s2.GetSetSize(); ++j) {
            res_set.AddElement(Calculate(s1.GetElement(i), s2.GetElement(j), '+'));
            res_set.AddElement(Calculate(s1.GetElement(i), s2.GetElement(j), '-'));
            res_set.AddElement(Calculate(s2.GetElement(j), s1.GetElement(i), '-'));
            res_set.AddElement(Calculate(s1.GetElement(i), s2.GetElement(j), '*'));
            res_set.AddElement(Calculate(s1.GetElement(i), s2.GetElement(j), '/'));
            res_set.AddElement(Calculate(s2.GetElement(j), s1.GetElement(i), '/'));
        }
    }
    return res_set;
}
Set1<Element>& Points24Game::Fork(int s) {
    if(S_[s].GetSetSize() != 0)
        return S_[s];
    for(int i=1; i<s; ++i) {
        if((s & i) == i) {
            if(i < s-i) {
                Set1<Element> res_set = Cal(Fork(i), Fork(s-i));
                S_[s] = Union<Element>(S_[s], res_set, Element::compare);
            }
        }
    }
    return S_[s];
}
void Points24Game::Process() {
    S_[static_cast<int>(pow(2, cards_num_)-1+0.5)] = Fork(static_cast<int>(pow(2, cards_num_)-1+0.5));
    Set1<Element> *p = S_ + static_cast<int>(pow(2, cards_num_)-1+0.5);
    for(int i=0; i < p->GetSetSize(); ++i) {
        if(Equal(p->GetElement(i).value_, terminal_)) {
            cout << "Success!" << endl;
            cout << p->GetElement(i).ShowExpressions() << endl;
        }
    }
    /* ***for debug
    ofstream out_file;
    out_file.open("output.txt", ios::out);
    for(int i=0; i < p->GetSetSize(); ++i) {
        if(p->GetElement(i).value_ != terminal_) {
            out_file << "Fail!" << endl;
            out_file << p->GetElement(i).ShowExpressions() << " = " << p->GetElement(i).value_ << endl;
        }
    }
    out_file.close();
    */
    cout << "Calculate completed." << endl;
}

int main() {
    Points24Game game;
    game.Process();
    return 0;
}
