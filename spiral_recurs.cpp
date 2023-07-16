int height(Node *root)
{
    if(root==0)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
void solve(Node *root,int level,vector<int> &ans,bool flag)
{
    if(root==NULL)
    {
        return;
    }
    if(level==1)
    {
        ans.push_back(root->data);
    }
    if(level>1)
    {
        if(flag==true)
        {
            solve(root->left,level-1,ans,flag);
            solve(root->right,level-1,ans,flag);
        }
        else
        {
            solve(root->right,level-1,ans,flag);
            solve(root->left,level-1,ans,flag);
        }
    }
}
vector<int> findSpiral(Node *root)
{
    //Your code here
    int k=height(root);
    vector<int>ans;
    bool flag=false;
    for(int i=1;i<=k;i++)
    {
        solve(root,i,ans,flag);
        flag=!flag;
    }
    return ans;
}
