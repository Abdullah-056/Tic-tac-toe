#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char c_marker;
int c_player;

void drawB()
{
    cout << endl << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "------------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "------------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << endl << endl;
}

bool placepoint(int slot)
{
    int row, col;

    if (slot % 3 == 0)
    {
        row = (slot / 3) - 1;
        col = 2;
    }
    else
    {
        row = (slot - 1) / 3;
        col = (slot - 1) % 3;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O')
        return true;
    else
        return false;
}

int winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return c_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return c_player;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return c_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return c_player;

    return 0;
}

void marker_player_swap()
{
    if (c_marker == 'X')
        c_marker = 'O';
    else
        c_marker = 'X';

    if (c_player == 1)
        c_player = 2;
    else
        c_player = 1;
}

void game()
{
    char mark;
    int slot, win;
    drawB();
    cout << "Player 1. Enter your marker X or O: ";
    cin >> mark;
    c_marker = mark;
    c_player = 1;

    for (int i = 0; i < 9; i++)
    {
        cout << "\nIt's " << c_player << " turn, Enter spot: ";
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "Invalid slot";
            continue;
        }

        if (!placepoint(slot))
        {
            cout << "Slot is occupied, Try again";
            i--;
            continue;
        }

        board[(slot - 1) / 3][(slot - 1) % 3] = c_marker;
        drawB();
        win = winner();

        if (win == 1)
        {
            cout << "\nPlayer 1 has won! Congratulations";
        break;}
        if(win==2){
            cout<<"\nPlayer 2 has won! Congragulation";
        break;}
        marker_player_swap();
    }
    if(winner()==0)
    cout<<"\nIt's a Tie : ";
}
int main()
{
    game();
}
