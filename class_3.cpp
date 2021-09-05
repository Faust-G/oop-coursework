#include"class_3.h"
class_3::class_3(node* p,string s="class_3"): node(p,move(s)){
    this->number=3;
    /*int r;
    cin>>r;
    this->ready=r;*/
}
void class_3::hen1(string s){
    dec=atoi(s.c_str());
}
void class_3::hen2(string s){
    op=s;
}
void class_3::hen3(string s){
    string u=to_string(dec);
    if(op=="+")
        dec=dec + atoi(s.c_str());
    if(op=="-")
        dec=dec - atoi(s.c_str());
    if(op=="*")
        dec=dec * atoi(s.c_str());
    if(op=="%")
        dec=dec % atoi(s.c_str());
    s=u+' '+op+' '+s+" = "+to_string(dec);
    this->emit_sig(signal(class_3::sig1),s);
}
/*void class_3::sig(string& s){
	s="Text: " + name + " -> "+s;
}
void class_3::hen(string s){
	s="Signal to " + name+' '+s;
	cerr<<'\n'<<s;
}*/