#include"node.h"
node::node(node* p,string s){
    set_parent(p);
    set_name(move(s));
}
void node::set_name(string s){
    name=move(s);
}
string node::get_name()const{
    return name;
}
node* node::get_parent()const{
    return parent;
}
void node:: set_parent(node* p){
    if(p==parent) return;
    if(parent){
        auto it=find(parent->children.begin(),parent->children.end(),this);
        parent->children.erase(it);
    }
    if(p){
        p->children.push_back(this);
    }
    parent =p;
}
void node:: show()const{
    cerr<<name<<'\n';
    queue<const node*>q;
    q.push(this);
    while(!q.empty()){
        auto root=q.front();
        q.pop();
        cerr<<root->name;
        for(auto child: root->children){
            cerr<<"  "<<child->name;
            if(!child->children.empty())
                q.push(child);
        }
        if(!q.empty())cerr<<'\n';
    }
}
node:: ~node(){
    for(auto a:children)
        delete a;
}
node* node::findpr(string s){
    if(s==this->name)
        return this;
    queue<const node*>q;
    q.push(this);
    while(!q.empty()){
        auto root=q.front();
        q.pop();
        for(auto child: root->children){
            if(s==child->name)
                return child;
            if(!child->children.empty())
                q.push(child);
        }
        if(q.empty())
            return nullptr;
    }

}
int node::get_num(){
    return this->number;
}
void node::set_con(TYPE_SIGNAL si ,node* p,  TYPE_HANDLER ha){
    connects.push_back(ost{si,p,ha});
}
void node::del_con (TYPE_SIGNAL si ,node* p,  TYPE_HANDLER ha){
    for(auto t= connects.begin();t!=connects.end();++t){
        if(t->si==si && t->ptr==p && t->ha==ha){
            connects.erase(t);
            return;
        }
    }
}
void node::emit_sig(TYPE_SIGNAL si, string& com){
    TYPE_HANDLER h;
    node* object;
    (this->*si)(com);
    for(auto a:connects)
        if(a.si==si) {
            h=a.ha;
            object=a.ptr;
            (object->*h)(com);
        }
}
node* node::bi(string parent){
    node* p=this;
    if(parent[0] =='/' && parent[1]=='/') {
        parent.erase(parent.begin(),parent.begin()+2);
        p = findpr(parent);
        return p;
    }
    if(parent.find('/')==string::npos){
        p=findpr(parent);
        return p;
    }
    if(parent.size()>this->get_name().size()+1)
        parent.erase(parent.begin(),parent.begin()+this->get_name().size()+2);
    else
        return this;
    string u;
    int pos=-1;
    while(parent.size()>0){
        bool b=0;
        u="";
        pos=-1;
        for(int i=0;i<parent.size();++i){
            if(parent[i]=='/'){
                pos=i;
                break;
            }
            u+=parent[i];
        }
        for(node* a:p->children){
            if(a->get_name()==u){
                b=1;
                p=a;
                break;
            }
        }
        if(!b)
            return nullptr;
        if(pos==-1)
            break;
        parent.erase(parent.begin(),parent.begin()+pos+1);
    }
    return p;
}
void node::check(node* d,bool b=1){
    if(b)
        cerr<<'\n';
    if(d->ready>0)
        cerr<<"The object "+d->get_name()+" is ready";
    else
        cerr<<"The object "+d->get_name()+" is not ready";
    for(auto child: d->children)
        check(child);
}
void node::rec(node* ptr, string s)const{
    cerr<<'\n'<<s<<ptr->get_name();
    for(auto child: ptr->children){
        rec(child,s+"    ");
    }
}
