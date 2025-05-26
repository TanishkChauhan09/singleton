#include<iostream>

using namespace std;

// class demo{
//     int a;

//     public:
//     void getdata()
//     {
//         cout<<"Enter the No.:";
//         cin>>a;
//     }
//     void putdata()
//     {
//         cout<<"\n Value is:"<<a;
//     }

//     demo operator+(demo bb)
//     {
//         demo ans;
//         ans.a = a+bb.a;
//         return ans;
//     }
// };

// int main()
// {
//     demo aa,bb;
//     aa.getdata();
//     bb.getdata();
//     demo cc = aa+bb;
//     cc.putdata();

//     return 0;
// }

int main()
{
    int a,b,c;
    cout<<"Enter two numbers:";
    cin>>a>>b;

    try
    {
        if(b!=0)
        {
            c = a/b;
            cout<<"Division of two numbers is:"<<c<<endl;
        }
        else
        {
            throw(b);
        }
    }
    catch(int b)
    {
        cout<<"Divide by "<<b<<" not possible";
    }
    

}