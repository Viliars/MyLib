#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED


strunct tree{
tree *ch[28];
bool t;
tree()
{
    memset(ch,0,sizeof(ch));
    t=false;
}

};

tree* build(vector<string> const &t)
{
    tree* root=new tree();
    for(auto c:t)
    {
        tree* curr=root;
        for(auto q:c)
        {
            if(curr->ch[q-'a']==nullptr)
            {
                if(curr->t)
                {
                    ok=false; return root;
                }
                curr->ch[q-'a']=new tree;
            }
            curr=curr->ch[q-'a'];
        }
        curr.t=true;
    }
}

bool check(const tree* root,const string& s)
{
    tree* curr=root;
    for(auto q:s)
    {
        if(curr->ch[q-'a']==nullptr) return false;
        if(curr->t) curr=root;
    }
    return curr==root;
}


#endif // TREE_H_INCLUDED
