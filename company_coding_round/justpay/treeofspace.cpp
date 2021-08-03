#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

struct node 
{
    string val;
    bool islocked;
    int id;
    vector<node*> children;
    unordered_set<node*> des_locked;
    node *parent;
    node(string v):val(v),parent(NULL),islocked(false),des_locked(0){}
    node(string v,node *par):val(v),parent(par),islocked(false),des_locked(0){}
};
bool lock(node *temp,int uid)
{
    if( temp->des_locked.size() > 0 || temp->islocked)
        return false;
    node *t = temp->parent;
    while(t)
    {
        if(t->islocked)
            return false;
        t = t->parent;
    }
    temp->islocked = true;
    temp->id = uid;
    t = temp->parent;
    while(t)
    {
        t->des_locked.insert(temp);
        t = t->parent;
    }
    return true;
}
bool unlock(node *temp,int uid)
{
    if(!(temp->islocked) || temp->id != uid)
        return false;
    temp->islocked = false;
    node *t = temp->parent;
    while(t)
    {
        t->des_locked.erase(temp);
        t = t->parent;
    }
    return true;
}
bool upgrade(node *temp,int uid)
{
    if(temp->islocked || temp->des_locked.size() == 0)
        return false;
    unordered_set<node*> children_locked = temp->des_locked;
    for(auto it = children_locked.begin(); it != children_locked.end();it++)
    {
       if((*it)->id != uid)
            return false;
    }
    for(auto it = children_locked.begin(); it != children_locked.end();it++)
    {
        unlock(*it,uid);
    }
    temp->islocked = true;
    temp->id = uid;
    node *t = temp->parent;
    while(t)
    {
        t->des_locked.insert(temp);
        t = t->parent;
    }
    return true;
}
int main()
{
    int N,m,Q;
    cin>>N>>m>>Q;
    unordered_map<string,node*> tree;
    string s;
    cin>>s;
    tree[s] = new node(s);
    queue<node*> q;
    q.push(tree[s]);
    int count = 1;
    while(!q.empty() && count<N)
    {
        node *par = q.front();
        q.pop();
        int n = N-count;
        if(n >= m)
        {
            for(int i=0;i<m;i++)
            {
                cin>>s;
                tree[s] = new node(s,par);
                par->children.push_back(tree[s]);
                q.push(tree[s]);
                count++;
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cin>>s;
                tree[s] = new node(s,par);
                par->children.push_back(tree[s]);
                q.push(tree[s]);
                count++;
            }
        }
    }
    // operation value uid
    // operation : 1.lock   2.unlock   3.upgrade
    // value: string denoting the unique name of a node in the m-ary tree
    // uid: an integer
    while(Q--)
    {
        int operation,uid;
        string value;
        cin>>operation;
        cin>>value;
        cin>>uid;
        bool ans;
        if(operation == 1)
            ans = lock(tree[value],uid);
        else if(operation == 2)
            ans = unlock(tree[value],uid);
        else
            ans = upgrade(tree[value],uid);
        if(ans)
            cout<<"true";
        else
            cout<<"false";
        cout<<endl;
    }
}
