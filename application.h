#ifndef __App
#define __App
#include"node.h"
#include"class_2.h"
#include"class_3.h"
#include"class_4.h"
class application : public node{
public:
    application(node* p): node(p){}
    void bild_tree_objects ( );
    int exec_app ( );
    void check_ready();
    void observe();
    void fir();
    void sig(string& s);
    void hen(string s);
    void beg();
};
#endif