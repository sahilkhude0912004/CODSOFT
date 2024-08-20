//Here  is a program for number guessing game using c++

#include<iostream>  
#include<cstdlib>
#include<ctime>

using namespace std;
int main()
{
    srand(time(NULL));

    int random_no ,  guess , no_of_guess=0;//some declarations
    
    cout<<"Welcome to the Number Guessing Game";

    random_no = rand() % 100 +1; //A simple Logic to generate a random number

    do{
        cout<<endl<<"Please enter your Guess in between(1-100)"<<endl;
        cin>>guess;
        no_of_guess++;

        if(guess < random_no)
        {
            cout<<"Guess a Larger Number."<<endl;
        }
        else if(guess > random_no)
        {
            cout<<"Guess a Smaller Number."<<endl;
        }
        else
        {
            cout<<endl<<"Congratulations !!! "<<endl<<"You have Successfully guessed the number in  "<<no_of_guess<<"  attempts";
        }
    }while(guess != random_no);

    cout<<endl<<"Bye Bye, Thanks for playing"<<endl;
    cout<<"Developed by Sahil Khude"<<endl; 

}

//End