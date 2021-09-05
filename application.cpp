#include"application.h"
void application::bild_tree_objects(){
    node* c;
    for(int i=0;i<3;++i){
        if(i==0)
            c=new class_2(nullptr,"2");
        if(i==1)
            c=new class_3(nullptr,"3");
        if(i==2)
            c=new class_4(nullptr,"4");
        c->set_parent(this);
    }
    /*string parent, child;
    cin>>parent;
    set_name(parent);
    int number;
    node* c;
    while(true){
        cin>>parent;
        if(parent=="endtree")
            break;
        node* p=this->bi(parent);
        cin>>child;
        cin>>number;
        if(number==2)
            c=new class_2(nullptr,child);
        if(number==3)
            c=new class_3(nullptr,child);
        if(number==4)
            c=new class_4(nullptr,child);
        if(number==5)
            c=new class_5(nullptr,child);
        if(number==6)
            c=new class_6(nullptr,child);
        c->set_parent(p);
    }*/
}
void application::fir(){
    string s,s1;
    while(true){
        node* p=this;
        cin>>s;
        if(s=="//")
            return;
        if(s[0] =='/' && s[1]=='/'){
            s.erase(s.begin(),s.begin()+2);
            p=findpr(s);
            s="//"+s;
        }
        else
            p=this->bi(s);
        if(p==nullptr)
            cerr<<'\n'<<s+" Object not found";
        else
            cerr<<'\n'<<s+" Object name: "<<p->get_name();
    }
}

int application::exec_app (){
    node* p1=this->bi("2");
    string s,u;
    getline(cin,s);
    u=s;
    u.erase(u.begin()+u.find(' '),u.end());
    s.erase(s.begin(),s.begin()+s.find(' ')+1);
    p1->emit_sig(signal(class_2::sig1),u);
    while(true){
        u=s;
        u.erase(u.begin()+u.find(' '),u.end());
        s.erase(s.begin(),s.begin()+s.find(' ')+1);
        p1->emit_sig(signal(class_2::sig2),u);
        u=s;
        if(u.find(' ')!=string::npos){
            u.erase(u.begin()+u.find(' '),u.end());
            s.erase(s.begin(),s.begin()+s.find(' ')+1);
        }
        else
            s="";
        p1->emit_sig(signal(class_2::sig3),u);
        if(s.size()!=0)
            cerr<<'\n';
        else
            break;
    }
    //this->show();
    /*cerr<<'\n'<<"Emit signals";
    while(true){
        string s;
        cin>>s;
        if(s=="endsignals")
            return 0;
        node* p=this->bi(s);
        cin>>s;
        int ch1=p->get_num();
        if(ch1==1)
            p->emit_sig(signal(application::sig),s);
        if(ch1==2)
            p->emit_sig(signal(class_2::sig),s);
        if(ch1==3)
            p->emit_sig(signal(class_3::sig),s);
    }*/
}
void application::check_ready(){
    cerr<<"Test result"<<'\n';
    this->check(this,0);
}
void application::observe(){
    cerr<<"Object tree";
    this->rec(this,"");
}
void application::sig(string& s){
    s="Text: " + name + " -> "+s;
}
void application::hen(string s){
    s="Signal to " + name+' '+s;
    cerr<<'\n'<<s;
}
void application::beg(){
    node* p2;
    for(auto a:children){
        int ch1=a->get_num();
        if(ch1==2){
            p2=this->bi("3");
            a->set_con(signal(class_2::sig1),p2,headler(class_3::hen1));
            a->set_con(signal(class_2::sig2),p2,headler(class_3::hen2));
            a->set_con(signal(class_2::sig3),p2,headler(class_3::hen3));
        }
        if(ch1==3){
            p2=this->bi("4");
            a->set_con(signal(class_3::sig1),p2,headler(class_4::hen1));
        }
    }
    /*cerr<<'\n'<<"Set connects";
    int num;
    string s,u;
    node* p1;
    node* p2;
    while(true){
        cin>>num;
        if(num==0)
            return;
        cin>>s>>u;
        p1=this->bi(s);
        p2=this->bi(u);
        cerr<<'\n'<<num<<' '+p1->get_name()+' '+p2->get_name();
        int ch1=p1->get_num();
        int ch2=p2->get_num();
        if(ch1==1){
            if(ch2==1)
                p1->set_con(signal(application::sig),p2,headler(application::hen));
            if(ch2==2)
                p1->set_con(signal(application::sig),p2,headler(class_2::hen));
            if(ch2==3)
                p1->set_con(signal(application::sig),p2,headler(class_3::hen));
        }
        if(ch1==2){
            if(ch2==1)
                p1->set_con(signal(class_2::sig),p2,headler(application::hen));
            if(ch2==2)
                p1->set_con(signal(class_2::sig),p2,headler(class_2::hen));
            if(ch2==3)
                p1->set_con(signal(class_2::sig),p2,headler(class_3::hen));
        }
        if(ch1==3){
            if(ch2==1)
                p1->set_con(signal(class_3::sig),p2,headler(application::hen));
            if(ch2==2)
                p1->set_con(signal(class_3::sig),p2,headler(class_2::hen));
            if(ch2==3)
                p1->set_con(signal(class_3::sig),p2,headler(class_3::hen));
        }
    }*/
}