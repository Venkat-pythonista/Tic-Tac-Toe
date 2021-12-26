#include<iostream>
using namespace  std;
char c[3][3];
void board()
{
    cout<<" 7  |  8  |  9 "<<endl;
    cout<<"---   ---   ---"<<endl;
    cout<<" 4  |  5  |  6 "<<endl;
    cout<<"---   ---   ---"<<endl;
    cout<<" 1  |  2  |  3 "<<endl;
}
void printboard()
{
    cout<<" "<<c[2][0]<<"  |  "<<c[2][1]<<"  |  "<<c[2][2]<<" "<<endl;
    cout<<"---   ---   ---"<<endl;
    cout<<" "<<c[1][0]<<"  |  "<<c[1][1]<<"  |  "<<c[1][2]<<" "<<endl;
    cout<<"---   ---   ---"<<endl;
    cout<<" "<<c[0][0]<<"  |  "<<c[0][1]<<"  |  "<<c[0][2]<<" "<<endl;
}

void empty_board()
{
    for (int i = 0;i<3; ++i)
        for (int j = 0; j<3; ++j)
            c[i][j] = ' ';
}
void game()
{
    board();
    cout<<" "<<endl;
    cout<<"***Game starts***"<<endl;
    int count=0;
    int re,i,j;
    char turn;
    turn='X';
    do
    {
        cout<<"It is"<<" "<<turn<<" "<<"turn now"<<endl;
        int choice;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        cout<<" "<<endl;

        count+=1;
        if(choice<=3)
        {
            if(c[0][choice-1] == ' ')
                c[0][choice-1] = turn;
            else
            {
                cout<<"Choice entered already"<<endl;
                count -= 1;
                continue;
            }
        }
        else if(choice>3 && choice <=6)
        {
            if (c[1][choice-4] == ' ')
                c[1][choice-4]= turn;
            else
            {
                cout<<"Choice entered already"<<endl;
                count -= 1;
                continue;
            }
        }
        else if(choice>6 && choice <=9)
        {
            if(c[2][choice-7] == ' ')
                c[2][choice-7]= turn;
            else
            {
                cout<<"Choice entered already"<<endl;
                count -= 1;
                continue;
            }
        }
        else
        {
            cout<<"Invalid number"<<endl;
            continue;
        }
        if(count>=5)
        {
            if((c[2][0]==c[2][1]) && (c[2][1] == c[2][2]) && (c[2][1] != ' ')) //1st row
            {
                cout<<"*******"<<turn<<" "<<"wins"<<"*******"<<endl;
                printboard();
                break;
            }
            else if((c[1][0]==c[1][1]) && (c[1][1] == c[1][2]) && (c[1][1] != ' ')) // 2nd row
            {
                cout<<"*******"<<turn<<" "<<"wins"<<"*******"<<endl;
                printboard();
                break;
            }
            else if((c[0][0]==c[0][1]) && (c[0][1] == c[0][2]) && (c[0][1] != ' ')) // 3rd row
            {
                cout<<"*******"<<turn<<" "<<"wins"<<"*******"<<endl;
                printboard();
                break;
            }
            else if((c[2][0]==c[1][0]) && (c[1][0] == c[0][0]) && (c[1][0] != ' ')) // 1st column
            {
                cout<<"*******"<<turn<<" "<<"wins"<<"*******"<<endl;
                printboard();
                break;
            }
            else if((c[2][1] == c[1][1]) && (c[1][1] == c[0][1]) && (c[1][1] != ' ')) //2nd column
            {
                cout<<turn<<" "<<"wins"<<endl;
                printboard();
                break;
            }
            else if((c[2][2] == c[1][2]) && (c[1][2] == c[0][2]) && (c[1][2] != ' ')) //3rd column
            {
                cout<<"*******"<<turn<<" "<<"wins"<<"*******"<<endl;
                printboard();
                break;
            }
            else if ((c[2][0] == c[1][1]) && (c[1][1] == c[0][2]) && (c[1][1] != ' ')) // left to right diagonal
            {
                cout<<"*******"<<turn<<" "<<"wins"<<"*******"<<endl;
                printboard();
                break;
            }
            else if ((c[2][2] == c[1][1]) && (c[1][1] == c[0][0]) && (c[1][1] != ' ')) // right to left diagonal
            {
                cout<<"*******"<<turn<<" "<<"wins"<<"*******"<<endl;
                printboard();
                break;
            }
        }
        printboard();

        if(count==9)
            cout<<"Tie"<<endl;

        if(turn=='X')
            turn='O';
        else
            turn='X';
        }while(count<9);

        cout<<"Do u want to play again? 1-yes / 2-no"<<endl;
        cin>>re;
        if(re==1)
        {
            empty_board();
            game();
        }
}
int main()
{
    empty_board();
    game();
    return 0;

}
