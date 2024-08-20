//Here is a program for simple calculator

#include<iostream>

using namespace std;

int main()
{
    float a,b,c;
    int choice;
    cout<<"Enter 1st Number :";
    cin>>a;
    cout<<"Enter 2nd Number :";
    cin>>b;
    do{
        cout<<"\n\n\n1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.DIVISION\n5.EXIT\n";
        cout<<"Enter your choice :\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                c=a+b;
                cout<<"The Addition is :"<<c<<endl;
                break;
            case 2:
                c=a-b;
                cout<<"The Subtraction is :"<<c<<endl;
                break;
            case 3:
                c=a*b;
                cout<<"The Multiplication is :"<<c<<endl;
                break;
            case 4:
                c=a/b;
                cout<<"The Division is :"<<c<<endl;
                break;

        }
    }while(choice!=5);

    cout<<"Bye Bye, Thanks for visiting the simple calculator\n";
    cout<<"Developed by Sahil Khude\n";
}

//End