#include "application.h"
int main(){
    application a(nullptr);
    a.bild_tree_objects( );
    //a.check_ready();
    //a.observe();
    //a.fir();
    a.beg();
    return a.exec_app();
}