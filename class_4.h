#ifndef __C4
#define __C4
#include"node.h"
class class_4 : public node{
public:
    explicit class_4(node* p=nullptr,string s="class_4"): node(p,move(s)){}
    void hen1(string s){
        cerr<<s;
    };
};
#endif