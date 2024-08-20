#include<iostream>
#include<string>
using namespace std;

int main()
{
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    
    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int row = -1;
    int col = -1;
    char winner = ' ';
    
    //print game board
    for (int i = 0; i < 9; i++)
    {
          cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if(winner != ' ')
        {
            break;
        }
        //get player input
        cout<<"Current Player is :" << currentPlayer << endl;

        while(true)
        {
            cout<<"Enter row and col (0-2) to input X or O : ";
            cin>> row>> col;
            if(row < 0 || row >2 || col < 0 || col > 2){
                cout<< "Invalid input, Please try again."<<endl;
            }else if(board[row][col] != ' '){
                cout<< "Tile is Full, Please try again."<<endl;
            }
            else{
                break;
            }

            //reset row and col values
            
            row=-1;
            col=-1;
            cin.clear(); //clear error flags
            cin.ignore(10000, '\n'); //discard values
            //(skips to the next new line \n upto 10000 char)already in input stream

        }
        board[row][col] = currentPlayer;
            currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        //to check winner 
        //rows

        for(int row = 0; row < 3; row++){
            if(board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]){
                winner = board[row][0];
                break;
            }
        }

        //columns

        for(int col = 0; col < 3; col++){
            if(board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col])
            {
                winner = board[0][col];
                break;
            }
        }

        if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            winner = board[0][0];
        }
        else if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            winner = board[0][2];
        }
    } 

   if(winner != ' ')
   {
    cout<<"Congratulations!!!\n"<<"Player"<<winner<<" is the winner"<<endl;
    cout<<"Bye Bye, Thanks for Playing\n";
    cout<<"Developed by Sahil Khude\n";
   }else{
    cout<<"Draw!!\n";
    cout<<"Bye Bye, Thanks for Playing\n";
    cout<<"Developed by Sahil Khude\n";
   }
}
