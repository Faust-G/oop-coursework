#include"class_2.h"
class_2::class_2(node* p,string s="class_2"): node(p,move(s)){
    this->number=2;
    /*int r;
    cin>>r;
    this->ready=r;*/
}
/*void class_2::sig(string& s){
	s="Text: " + name + " -> "+s;
}*/
void class_2::hen(string s){
    s="Signal to " +name+' '+s;
    cerr<<'\n'<<s;
}