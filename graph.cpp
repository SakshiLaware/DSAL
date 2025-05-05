#include<iostream>
#include<queue>
using namespace std;

class graph
{
    public:
    string  city[5];
    int M[5][5];
    int n;
    graph()
    {
        cout<<"\nEnter number of cities";
        cin>>n;
    }
    void create();
    void initialize();
    void display();
    void connected();


};

void graph::initialize()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            M[i][j]=0;
        }
    }
}

void graph::create()
{
    int a,b;
    char s[10],d[10],ch;
    for(int i=0;i<n;i++)
    {
        cout<<"enter city name";
        cin>>city[i];
    }

    do{
    cout<<"enter the starting city";
    cin>>s;
    int i=0;
    while(city[i]!=s)
    {
        i++;
    }
    a=i;

    cout<<"enter the destination city";
    cin>>d;
     i=0;
    while(city[i]!=d)
    {
        i++;
    }
    b=i;

    cout<<"enter amount of time required";
    cin>>M[a][b];
    M[b][a]=M[a][b];

    cout<<"enter y for adding time for more cityand n for directly displaying th matrix\n";
    cin>>ch;
    }while(ch=='y');
}


void graph::display()
{
    for(int i=0;i<n;i++)
    {
        cout<<city[i]<<" ";
    }
    cout<<"\n";

    for(int i=0;i<n;i++)
    {   cout<<city[i]<<" ";
        for(int j=0;j<n;j++)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void graph::connected()
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j && M[i][j]==0 || M[j][i]==0)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        cout<<"\nGraph is connected";
    }
    else
    {
        cout<<"\nGraph is not connected";
    }
}


int main()
{
    graph ob;
    ob.initialize();
    ob.create();
    ob.display();
    ob.connected();
    return 0;
}