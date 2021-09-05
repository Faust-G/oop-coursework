#ifndef __Main
#define __Main
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<unordered_map>
using namespace std;
class node;
typedef void (node::*TYPE_SIGNAL) (string&);
typedef void (node::*TYPE_HANDLER) (string);
#define signal(signal_f) ((TYPE_SIGNAL) (&signal_f))
#define headler(head_f) ((TYPE_HANDLER) (&head_f))
class node{
protected:
    int number=1;
    int ready=1;
    string name;
    node* parent{};
    vector<node*>children;
    struct ost{
        TYPE_SIGNAL si;
        node* ptr;
        TYPE_HANDLER ha;
    };
   vector<ost> connects;
public:
    explicit node(node* p=nullptr,string s="Node");
    void set_name(string);
    int get_num();
    void set_con(TYPE_SIGNAL ,node* p,  TYPE_HANDLER);
    void del_con (TYPE_SIGNAL ,node* p, TYPE_HANDLER);
    void emit_sig(TYPE_SIGNAL , string& com);
    string get_name() const;
    void set_parent(node*);
    node* get_parent()const;
    void show() const;
    virtual ~node();
    node*  findpr(string);
    void check(node* d,bool b);
    void rec (node*, string)const;
    node* bi(string);
};
#endif