#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include "clui.h"
#include <string.h>
using namespace std;
struct player
{
    char name[20];
    int point;
    char jadval[20][20];
};
struct bomb_direction
{
    int b_row;
    int b_column;
};
bomb_direction bmb_dir_arr[160];
player player_arr[10];
int player_number=0;
int player_count=0;
void swap(int& a,int& b)
{
    int temp=a;
    a=b;
    b=temp;
}
void bubble_sort(int a[], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(a[j+1]>a[j])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}
void start()
{
    player_count++;
    change_color_rgb(51, 133, 212);
    printf("++++  %c WELCOME TO MINESWEEPER %c  ++++\n\n", 2,2);
    reset_color();
    delay(500);
    change_color_rgb(21, 230, 223);
    cout<<"Please enter your name : (1 to 20 characters   !!no space!!)"<<endl;
    reset_color();
    cin>>player_arr[player_number].name;
    clear_screen();    
}
void jadval(int level)
{
    clear_screen();
    cout<<"Player : ";
    change_color_rgb(232, 255, 59);
    cout<<player_arr[player_number].name<<endl;
    reset_color();
    cout<<"Points : ";
    change_color_rgb(232, 255, 59);
    cout<<player_arr[player_number].point<<endl;
    reset_color();
    int temp_limit;
    if(level==1)
        temp_limit=5;
    if(level==2)
        temp_limit=12;
    if(level==3)
        temp_limit=20;
    for(int i=0;i<temp_limit;i++)
    {
        for(int j=0;j<temp_limit;j++)
        {
            if(player_arr[player_number].jadval[i][j]=='F')
            {
                change_color_rgb(41, 214, 90);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]=='B')
            {
                change_color_rgb(240, 105, 105);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==49)
            {
                change_color_rgb(235, 232, 70);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==50)
            {
                change_color_rgb(227, 168, 66);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==51)
            {
                change_color_rgb(227, 130, 66);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==52)
            {
                change_color_rgb(213, 71, 252);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==53)
            {
                change_color_rgb(131, 71, 252);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==54)
            {
                change_color_rgb(237, 0, 162);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==55)
            {
                change_color_rgb(219, 11, 136);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==56)
            {
                change_color_rgb(184, 9, 146);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else
            cout<<player_arr[player_number].jadval[i][j]<<" ";
        }
        cout<<endl;
    }
    change_color_rgb(21, 230, 223);
    cout<<"Now chose your spot"<<endl;
    cout<<"<w> : up   <s> : down   <a> : left   <d> : right"<<endl;
    cout<<"< > : open   <F> : flag/unflag   <Q> : quit without save"<<endl;
    reset_color();        
}
void jadval_costum(int row,int column)
{
    clear_screen();
    cout<<"Player : ";
    change_color_rgb(232, 255, 59);
    cout<<player_arr[player_number].name<<endl;
    reset_color();
    cout<<"Points : ";
    change_color_rgb(232, 255, 59);
    cout<<player_arr[player_number].point<<endl;
    reset_color();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(player_arr[player_number].jadval[i][j]=='F')
            {
                change_color_rgb(41, 214, 90);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]=='B')
            {
                change_color_rgb(240, 105, 105);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==49)
            {
                change_color_rgb(235, 232, 70);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==50)
            {
                change_color_rgb(227, 168, 66);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==51)
            {
                change_color_rgb(227, 130, 66);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==52)
            {
                change_color_rgb(213, 71, 252);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==53)
            {
                change_color_rgb(131, 71, 252);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==54)
            {
                change_color_rgb(237, 0, 162);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==55)
            {
                change_color_rgb(219, 11, 136);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else if(player_arr[player_number].jadval[i][j]==56)
            {
                change_color_rgb(184, 9, 146);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
                reset_color();
            }
            else
            cout<<player_arr[player_number].jadval[i][j]<<" ";
        }
        cout<<endl;
    }
    change_color_rgb(21, 230, 223);
    cout<<"Now chose your spot"<<endl;
    cout<<"<w> : up   <s> : down   <a> : left   <d> : right"<<endl;
    cout<<"< > : open   <F> : flag/unflag   <Q> : quit without save"<<endl;
    reset_color();     
}
bool input_error(char action,int y,int x,int level)
{
    if(action!='w' && action!='d' && action!='s' && action!='a' && action!=' ' && action!='F' && action!='Q')
    {
        play_beep();
        change_color_rgb(235, 47, 47);
        cout<<"ERROR : NOT IN OPTIONS :("<<endl;
        reset_color();
        delay(1000);
        jadval(level);
        cursor_to_pos(y,x);
        return true;
    }
    return false;
}
bool input_error_costum(char action,int y,int x,int row,int column)
{
    if(action!='w' && action!='d' && action!='s' && action!='a' && action!=' ' && action!='F' && action!='Q')
    {
        play_beep();
        change_color_rgb(235, 47, 47);
        cout<<"ERROR : NOT IN OPTIONS :("<<endl;
        reset_color();
        delay(1000);
        jadval_costum(row,column);
        cursor_to_pos(y,x);
        return true;    
    }
    return false;    
}
int menu()
{
    cout<<"Player : ";
    change_color_rgb(232, 255, 59);
    cout<<player_arr[player_number].name<<endl<<endl;
    reset_color();
    change_color_rgb(21, 230, 223);
    delay(200);
    cout<<"1. New Game"<<endl;
    delay(200);
    cout<<"2. Load Game"<<endl;
    delay(200);
    cout<<"3. Change Name"<<endl;
    delay(200);
    cout<<"4. Leader Board"<<endl;
    delay(200);
    cout<<"5. Quit"<<endl;
    reset_color();
    int menu_choice;
    cin>>menu_choice;
    while(menu_choice<1 || menu_choice>5)
    {
        play_beep();
        change_color_rgb(235, 47, 47);
        cout<<"ERROR : NOT IN OPTIONS :("<<endl;
        reset_color();
        delay(500);
        cin>>menu_choice;
    }
    clear_screen();
    return menu_choice;
}
int load_game()
{
    change_color_rgb(21, 230, 223);
    cout<<"Choose a save slot :"<<endl<<endl;
    reset_color();
    for(int i=0;i<player_count;i++)
    {
        delay(100);
        cout<<i+1<<". ";
        change_color_rgb(232, 255, 59);
        cout<<player_arr[i].name;
        reset_color();
        cout<<"    Points : ";
        change_color_rgb(232, 255, 59);
        cout<<player_arr[i].point<<endl;
        reset_color();
    }
    int save_choice;
    cin>>save_choice;
    clear_screen();
    return save_choice;
}
int change_name()
{
    clear_screen();
    change_color_rgb(21, 230, 223);
    cout<<"Write your new name : "<<endl;
    reset_color();
    char temp[20];
    cin>>temp;
    for(int i=0;i<player_count;i++)
    {
        for(int j=0;temp[j]!='\0';)
        {
            if(temp[j]!=player_arr[player_number].name[j])
                break;
            j++;
            if(temp[j]==player_arr[player_number].name[j] && temp[j]=='\0')
            {
                clear_screen();
                return i;
            }
        }        
    }
    player_number++;
    for(int i=0;temp[i]!='\0';i++)
    {
        player_arr[player_number].name[i]=temp[i];
    }
    player_count++;
    clear_screen();
    return player_number;
}
void leaderboard()
{
    int temp_arr[10];
    int i=0;
    for(;i<player_count;i++)
    {
        temp_arr[i]=player_arr[i].point;
    }
    bubble_sort(temp_arr,player_count);
    for(int j=0;j<player_count;)
    {
        for(int k=0;k<player_count;k++)
        {
            if(player_arr[k].point==temp_arr[j])
            {
                delay(250);
                cout<<j+1<<". ";
                change_color_rgb(232, 255, 59);
                cout<<player_arr[k].name;
                reset_color();
                cout<<"    Points : ";
                change_color_rgb(232, 255, 59);
                cout<<temp_arr[j++]<<endl;
                reset_color();
            }
        }
    }
    delay(3000);
    change_color_rgb(21, 230, 223);
    cout<<"Press any key to inter menu"<<endl;
    reset_color();
    char press=getch();
    clear_screen();
}
int Game_mode()
{
    cout<<"Player : ";
    change_color_rgb(232, 255, 59);
    cout<<player_arr[player_number].name<<endl<<endl;
    reset_color();
    change_color_rgb(21, 230, 223);
    delay(200);
    cout<<"1. Easy"<<endl;
    delay(200);
    cout<<"2. Medium"<<endl;
    delay(200);
    cout<<"3. Hard"<<endl;
    delay(200);
    cout<<"4. Costum"<<endl;
    reset_color();
    int level_choice;
    cin>>level_choice;
    while(level_choice<1 || level_choice>4)
    {
        play_beep();
        change_color_rgb(235, 47, 47);
        cout<<"ERROR : NOT IN OPTIONS :("<<endl;
        reset_color();
        delay(500);
        cin>>level_choice;
    }
    clear_screen();
    return level_choice;
}
void bombs_spots_costum(int costum_row,int costum_column,int costum_bomb_number)
{
    srand(time(NULL));
    for(int i=0;i<costum_bomb_number;i++)
    {
        bmb_dir_arr[i].b_row = rand()%costum_row;
        bmb_dir_arr[i].b_column = rand()%costum_column;
    }
    for(int i=0;i<costum_bomb_number;i++)
    {
        for(int j=0;j<costum_bomb_number;j++)
        {
            if(i!=j)
            {
                while(bmb_dir_arr[i].b_row==bmb_dir_arr[j].b_row && bmb_dir_arr[i].b_column==bmb_dir_arr[j].b_column)
                {
                    bmb_dir_arr[j].b_row = rand()%costum_row;
                    bmb_dir_arr[j].b_column = rand()%costum_column;
                    j=-1;
                }
            }
        }
    }
}
void lost_game_costum(int row,int column,int bombs_count)
{
    clear_screen();
    for(int i=0;i<bombs_count;i++)
    {
        player_arr[player_number].jadval[bmb_dir_arr[i].b_row][bmb_dir_arr[i].b_column]='B';   
    }
    jadval_costum(row,column);
    change_color_rgb(219, 29, 29);
    cout<<"!!!!!! BOOOOOOOOOMMMM !!!!!!"<<endl;
    delay(900);
    cout<<"         YOU LOST :*("<<endl;
    delay(1500);
    reset_color();
    change_color_rgb(21, 230, 223);
    cout<<"Press any key to inter menu"<<endl;
    reset_color();
    char press=getch();
    clear_screen();
}
void win_game_costum(int row,int column,int bombs_count)
{
    clear_screen();
    for(int i=0;i<bombs_count;i++)
    {
        player_arr[player_number].jadval[bmb_dir_arr[i].b_row][bmb_dir_arr[i].b_column]='B';    
    }
    jadval_costum(row,column);
    change_color_rgb(38, 212, 44);
    cout<<"@#$%^&*";
    reset_color();
    change_color_rgb(38, 186, 212);
    cout<<"   !! WINNER !!   ";
    reset_color();
    change_color_rgb(38, 212, 44);
    cout<<"*&^%$#@"<<endl;
    reset_color();
    delay(1500);
    change_color_rgb(21, 230, 223);
    cout<<"Press any key to inter menu"<<endl;
    reset_color();
    char press=getch();
    clear_screen();
}
bool open_slot_costum(int y,int x,int row,int column,int bombs_count,int& round_counter)
{
    int add_point=150;
    if(player_arr[player_number].jadval[y][x]=='F')
    {
        play_beep();
        change_color_rgb(235, 47, 47);
        cout<<"ERROR : You cant open a Flag slot !"<<endl;
        reset_color();
        delay(3000);
        jadval_costum(row,column);
        cursor_to_pos(y+3,x*2+1);
        return true;
    }
    if(player_arr[player_number].jadval[y][x]=='-')
    {
        for(int i=0;i<bombs_count;i++)
        {
            if(bmb_dir_arr[i].b_row==y && bmb_dir_arr[i].b_column==x)
            {
                lost_game_costum(row,column,bombs_count);
                return false;
            }
        }
        int nearby_bombs=0;
        for(int i=0;i<bombs_count;i++)
        {
            if(bmb_dir_arr[i].b_row==y-1 && bmb_dir_arr[i].b_column==x-1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y && bmb_dir_arr[i].b_column==x-1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y+1 && bmb_dir_arr[i].b_column==x-1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y+1 && bmb_dir_arr[i].b_column==x)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y+1 && bmb_dir_arr[i].b_column==x+1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y && bmb_dir_arr[i].b_column==x+1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y-1 && bmb_dir_arr[i].b_column==x+1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y-1 && bmb_dir_arr[i].b_column==x)
                nearby_bombs++;
        }
        player_arr[player_number].jadval[y][x]=nearby_bombs+48;
        player_arr[player_number].point+=add_point;
        round_counter++;
        if(round_counter==(row*column - bombs_count))
        {
            win_game_costum(row,column,bombs_count);
            return false;
        }
        jadval_costum(row,column);
        cursor_to_pos(y+3,x*2+1);
        return true;
    }    
}
void play_costum(int row,int column,int bombs_count)
{
    int round_counter=0;
    cursor_to_pos(3,1);
    char action=getch();
    while(input_error_costum(action,3,1,row,column))
        action=getch();        
    int cursor_x=1,cursor_y=3;
    while(1)
    {
        while(action=='w' || action=='d' || action=='s' || action=='a')
        {
            if(action=='w')
            {
                if(cursor_y==3)
                    cursor_y=row+2;
                else
                    cursor_y--;
                cursor_to_pos(cursor_y,cursor_x);
            }
            if(action=='d')
            {
                if(cursor_x==column*2-1)
                    cursor_x=1;
                else
                    cursor_x+=2;
                cursor_to_pos(cursor_y,cursor_x);
            }
            if(action=='s')
            {
                if(cursor_y==row+2)
                    cursor_y=3;
                else
                    cursor_y++;
                cursor_to_pos(cursor_y,cursor_x);
            }
            if(action=='a')
            {
                if(cursor_x==1)
                    cursor_x=column*2-1;
                else
                    cursor_x-=2;
                cursor_to_pos(cursor_y,cursor_x);
            }
            action=getch();
        }
        if(action=='F')
        {
            if(player_arr[player_number].jadval[cursor_y-3][cursor_x/2]=='F')
            {
                player_arr[player_number].jadval[cursor_y-3][cursor_x/2]='-';
                jadval_costum(row,column);
                cursor_to_pos(cursor_y,cursor_x); 
            }
            else if(player_arr[player_number].jadval[cursor_y-3][cursor_x/2]!='-')
            {
                play_beep();
                change_color_rgb(235, 47, 47);
                cout<<"ERROR: choose an empty spot!!"<<endl;
                reset_color();
                delay(1000);
                jadval_costum(row,column);
                cursor_to_pos(cursor_y,cursor_x);        
            }
            else
            {
                player_arr[player_number].jadval[cursor_y-3][cursor_x/2]='F';
                jadval_costum(row,column);
                cursor_to_pos(cursor_y,cursor_x);
            }    
            action=getch();
        }
        if(action==' ')
        {
            if(player_arr[player_number].jadval[cursor_y-3][cursor_x/2]!='-')
            {
                play_beep();
                change_color_rgb(235, 47, 47);
                cout<<"ERROR: choose an empty spot!!"<<endl;
                reset_color();
                delay(1000);
                jadval_costum(row,column);
                cursor_to_pos(cursor_y,cursor_x);   
            }
            else
            {
                bool game_check=open_slot_costum(cursor_y-3,cursor_x/2,row,column,bombs_count,round_counter);
                if(game_check==false)
                    return;
            }        
            action=getch();
        }
        if(action=='Q')
        {
            clear_screen();
            return;
        }
        while(input_error_costum(action,cursor_y,cursor_x,row,column))
            action=getch();
    }    
}
void pre_play(int level_choice)
{
    cout<<"Player : ";
    change_color_rgb(232, 255, 59);
    cout<<player_arr[player_number].name<<endl;
    reset_color();
    cout<<"Points : ";
    change_color_rgb(232, 255, 59);
    cout<<player_arr[player_number].point<<endl;
    reset_color();
    if(level_choice==1)
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                player_arr[player_number].jadval[i][j]='-';
                delay(75);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    if(level_choice==2)
    {
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<12;j++)
            {
                player_arr[player_number].jadval[i][j]='-';
                delay(30);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    if(level_choice==3)
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                player_arr[player_number].jadval[i][j]='-';
                delay(10);
                cout<<player_arr[player_number].jadval[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    if(level_choice==4)
    {
        change_color_rgb(21, 230, 223);
        cout<<"Enter the number of your rows and columns : "<<endl;
        reset_color();
        int costum_row,costum_column;
        cin>>costum_row>>costum_column;
        while((costum_row>20 || costum_row<5) || (costum_column>20 || costum_column<5))
        {
            clear_screen();
            play_beep();
            change_color_rgb(235, 47, 47);
            cout<<"ERROR : !! OUT OF RANGE !!"<<endl;
            reset_color();
            delay(500);
            change_color_rgb(21, 230, 223);
            cout<<"Enter the number of your rows and columns : "<<endl;
            reset_color();
            cin>>costum_row>>costum_column;
        }
        clear_screen();
        cout<<"Player : ";
        change_color_rgb(232, 255, 59);
        cout<<player_arr[player_number].name<<endl;
        reset_color();
        cout<<"Points : ";
        change_color_rgb(232, 255, 59);
        cout<<player_arr[player_number].point<<endl;
        reset_color();
        change_color_rgb(21, 230, 223);
        cout<<"Enter the number of your !BOMBS! ("<<(costum_column*costum_row)/5<<" to "<<(costum_column*costum_row*2)/5<<")"<<endl;
        reset_color();
        int costum_bomb_number;
        cin>>costum_bomb_number;
        while(costum_bomb_number>((costum_column*costum_row*2)/5) || costum_bomb_number<((costum_column*costum_row)/5))
        {
            clear_screen();
            play_beep();
            change_color_rgb(235, 47, 47);
            cout<<"ERROR : !! OUT OF RANGE !!"<<endl;
            reset_color();
            delay(500);
            change_color_rgb(21, 230, 223);
            cout<<"Player : ";
            change_color_rgb(232, 255, 59);
            cout<<player_arr[player_number].name<<endl<<endl;
            reset_color();
            cout<<"Enter the number of your !BOMBS! ("<<(costum_column*costum_row)/5<<" to "<<(costum_column*costum_row*2)/5<<")"<<endl;
            reset_color();
            cin>>costum_bomb_number;    
        }
        bombs_spots_costum(costum_row,costum_column,costum_bomb_number);
        clear_screen();
        cout<<"Player : ";
        change_color_rgb(232, 255, 59);
        cout<<player_arr[player_number].name<<endl;
        reset_color();
        cout<<"Points : ";
        change_color_rgb(232, 255, 59);
        cout<<player_arr[player_number].point<<endl;
        reset_color();
        for(int i=0;i<costum_row;i++)
        {
            for(int j=0;j<costum_column;j++)
            {
                player_arr[player_number].jadval[i][j]='-';
                if(costum_column*costum_row>=25 && costum_column*costum_row<85)
                    delay(75);
                if(costum_column*costum_row>=80 && costum_column*costum_row<200)
                    delay(30);
                if(costum_column*costum_row>=200 && costum_column*costum_row<=400)
                    delay(10);
                cout<<player_arr[player_number].jadval[i][j]<<" ";    
            }
            cout<<endl;
        }
        change_color_rgb(21, 230, 223);
        cout<<"Now chose your spot"<<endl;
        cout<<"<w> : up   <s> : down   <a> : left   <d> : right"<<endl;
        cout<<"< > : open   <F> : flag/unflag   <O> : save and quit   <Q> : quit without save"<<endl;
        reset_color();
        play_costum(costum_row,costum_column,costum_bomb_number);
    }
    if(level_choice!=4)
    {
        change_color_rgb(21, 230, 223);
        cout<<"Now chose your spot"<<endl;
        cout<<"<w> : up   <s> : down   <a> : left   <d> : right"<<endl;
        cout<<"< > : open   <F> : flag/unflag   <O> : save and quit   <Q> : quit without save"<<endl;
        reset_color();
    }
}    
void bombs_spots(int level)
{
    srand(time(NULL));
    if(level==1)
    {
        for(int i=0;i<4;i++)
        {
            bmb_dir_arr[i].b_row = rand()%5;
            bmb_dir_arr[i].b_column = rand()%5;
        }
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i!=j)
                {
                    while(bmb_dir_arr[i].b_row==bmb_dir_arr[j].b_row && bmb_dir_arr[i].b_column==bmb_dir_arr[j].b_column)
                    {
                        bmb_dir_arr[j].b_row = rand()%5;
                        bmb_dir_arr[j].b_column = rand()%5;
                        j=-1;
                    }
                }
            }
        }
    }
    if(level==2)
    {
        for(int i=0;i<28;i++)
        {
            bmb_dir_arr[i].b_row = rand()%12;
            bmb_dir_arr[i].b_column = rand()%12;
        }
        for(int i=0;i<28;i++)
        {
            for(int j=0;j<28;j++)
            {
                if(i!=j)
                {
                    while(bmb_dir_arr[i].b_row==bmb_dir_arr[j].b_row && bmb_dir_arr[i].b_column==bmb_dir_arr[j].b_column)
                    {
                        bmb_dir_arr[j].b_row = rand()%12;
                        bmb_dir_arr[j].b_column = rand()%12;
                        j=0;
                    }
                }
            }
        }    
    }
    if(level==3)
    {
        for(int i=0;i<96;i++)
        {
            bmb_dir_arr[i].b_row = rand()%20;
            bmb_dir_arr[i].b_column = rand()%20;
        }
        for(int i=0;i<96;i++)
        {
            for(int j=0;j<96;j++)
            {
                if(i!=j)
                {
                    while(bmb_dir_arr[i].b_row==bmb_dir_arr[j].b_row && bmb_dir_arr[i].b_column==bmb_dir_arr[j].b_column)
                    {
                        bmb_dir_arr[j].b_row = rand()%20;
                        bmb_dir_arr[j].b_column = rand()%20;
                        j=0;
                    }
                }
            }
        }
    }
}
void lost_game(int level)
{
    
    if(level==1)
    {
        for(int i=0;i<4;i++)
        {
            player_arr[player_number].jadval[bmb_dir_arr[i].b_row][bmb_dir_arr[i].b_column]='B';
        }
    }
    if(level==2)
    {
        for(int i=0;i<28;i++)
        {
            player_arr[player_number].jadval[bmb_dir_arr[i].b_row][bmb_dir_arr[i].b_column]='B';
        }
    }
    if(level==3)
    {
        for(int i=0;i<96;i++)
        {
            player_arr[player_number].jadval[bmb_dir_arr[i].b_row][bmb_dir_arr[i].b_column]='B';
        }
    }
    jadval(level);
    change_color_rgb(219, 29, 29);
    cout<<"!!!!!! BOOOOOOOOOMMMM !!!!!!"<<endl;
    delay(900);
    cout<<"         YOU LOST :*("<<endl;
    delay(1500);
    reset_color();
    change_color_rgb(21, 230, 223);
    cout<<"Press any key to inter menu"<<endl;
    reset_color();
    char press=getch();
    clear_screen();
}
void win_game(int level)
{
    clear_screen();
    if(level==1)
    {
        for(int i=0;i<4;i++)
        {
            player_arr[player_number].jadval[bmb_dir_arr[i].b_row][bmb_dir_arr[i].b_column]='B';
        }
    }
    if(level==2)
    {
        for(int i=0;i<28;i++)
        {
            player_arr[player_number].jadval[bmb_dir_arr[i].b_row][bmb_dir_arr[i].b_column]='B';
        }
    }
    if(level==3)
    {
        for(int i=0;i<96;i++)
        {
            player_arr[player_number].jadval[bmb_dir_arr[i].b_row][bmb_dir_arr[i].b_column]='B';
        }
    }
    jadval(level);
    change_color_rgb(38, 212, 44);
    cout<<"@#$%^&*";
    reset_color();
    change_color_rgb(38, 186, 212);
    cout<<"   !! WINNER !!   ";
    reset_color();
    change_color_rgb(38, 212, 44);
    cout<<"*&^%$#@"<<endl;
    reset_color();
    delay(1500);
    change_color_rgb(21, 230, 223);
    cout<<"Press any key to inter menu"<<endl;
    reset_color();
    char press=getch();
    clear_screen();    
}
bool open_slot(int y,int x,int level,int& round_counter)
{
    int bombs_count;
    int max_round;
    int add_point;
    if(level==1)
    {
        bombs_count=4;
        max_round=21;
        add_point=50;
    }
    if(level==2)
    {
        bombs_count=28;
        max_round=116;
        add_point=100;
    }
    if(level==3)
    {
        bombs_count=96;
        max_round=308;
        add_point=200;
    }
    if(player_arr[player_number].jadval[y][x]=='F')
    {
        play_beep();
        change_color_rgb(235, 47, 47);
        cout<<"ERROR : You cant open a Flag slot !"<<endl;
        reset_color();
        delay(3000);
        jadval(level);
        cursor_to_pos(y+3,x*2+1);
        return true;
    }
    if(player_arr[player_number].jadval[y][x]=='-')
    {
        for(int i=0;i<bombs_count;i++)
        {
            if(bmb_dir_arr[i].b_row==y && bmb_dir_arr[i].b_column==x)
            {
                lost_game(level);
                return false;
            }
        }
        int nearby_bombs=0;
        for(int i=0;i<bombs_count;i++)
        {
            if(bmb_dir_arr[i].b_row==y-1 && bmb_dir_arr[i].b_column==x-1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y && bmb_dir_arr[i].b_column==x-1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y+1 && bmb_dir_arr[i].b_column==x-1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y+1 && bmb_dir_arr[i].b_column==x)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y+1 && bmb_dir_arr[i].b_column==x+1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y && bmb_dir_arr[i].b_column==x+1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y-1 && bmb_dir_arr[i].b_column==x+1)
                nearby_bombs++;
            if(bmb_dir_arr[i].b_row==y-1 && bmb_dir_arr[i].b_column==x)
                nearby_bombs++;
        }
        player_arr[player_number].jadval[y][x]=nearby_bombs+48;
        player_arr[player_number].point+=add_point;
        round_counter++;
        if(round_counter==max_round)
        {
            win_game(level);
            return false;
        }
        jadval(level);
        cursor_to_pos(y+3,x*2+1);
        return true;
    }    
}
void play(int level)
{
    int y_limit;
    int x_limit;
    int round_counter=0;
    if(level==1)
    {
        y_limit=7;
        x_limit=9;
    }
    if(level==2)
    {
        y_limit=14;
        x_limit=23;
    }
    if(level==3)
    {
        y_limit=22;
        x_limit=39;
    }
    cursor_to_pos(3,1);
    char action=getch();
    while(input_error(action,3,1,level))
        action=getch();        
    int cursor_x=1,cursor_y=3;
    while (1)
    {
        while(action=='w' || action=='d' || action=='s' || action=='a')
        {
            if(action=='w')
            {
                if(cursor_y==3)
                    cursor_y=y_limit;
                else
                    cursor_y--;
                cursor_to_pos(cursor_y,cursor_x);
            }
            if(action=='d')
            {
                if(cursor_x==x_limit)
                    cursor_x=1;
                else
                    cursor_x+=2;
                cursor_to_pos(cursor_y,cursor_x);
            }
            if(action=='s')
            {
                if(cursor_y==y_limit)
                    cursor_y=3;
                else
                    cursor_y++;
                cursor_to_pos(cursor_y,cursor_x);
            }
            if(action=='a')
            {
                if(cursor_x==1)
                    cursor_x=x_limit;
                else
                    cursor_x-=2;
                cursor_to_pos(cursor_y,cursor_x);
            }
            action=getch();
        }
        if(action=='F')
        {
            if(player_arr[player_number].jadval[cursor_y-3][cursor_x/2]=='F')
            {
                player_arr[player_number].jadval[cursor_y-3][cursor_x/2]='-';
                jadval(level);
                cursor_to_pos(cursor_y,cursor_x);
            }     
            else if(player_arr[player_number].jadval[cursor_y-3][cursor_x/2]!='-')
            {
                play_beep();
                change_color_rgb(235, 47, 47);
                cout<<"ERROR: choose an empty spot!!"<<endl;
                reset_color();
                delay(1000);
                jadval(level);
                cursor_to_pos(cursor_y,cursor_x); 
            }
            else
            {
                player_arr[player_number].jadval[cursor_y-3][cursor_x/2]='F';
                jadval(level);
                cursor_to_pos(cursor_y,cursor_x);
            }    
            action=getch();
        }
        if(action==' ')
        {
            if(player_arr[player_number].jadval[cursor_y-3][cursor_x/2]!='-')
            {
                play_beep();
                change_color_rgb(235, 47, 47);
                cout<<"ERROR: choose an empty spot!!"<<endl;
                reset_color();
                delay(1000);
                jadval(level);
                cursor_to_pos(cursor_y,cursor_x);   
            }
            else
            {
                bool game_check=open_slot(cursor_y-3,cursor_x/2,level,round_counter);
                if(game_check==false)
                    return;
            }        
            action=getch();
        }
        if(action=='Q')
        {
            clear_screen();
            return;
        }
        while(input_error(action,cursor_y,cursor_x,level))
            action=getch();  
    }    
}
int main()
{
    init_clui();
    start();
    int menu_choice=menu();
    while(menu_choice!=5)
    {
        while(menu_choice==1)
        {
            int Game_mode_choice=Game_mode();
            pre_play(Game_mode_choice);
            if(Game_mode_choice!=4)
            {
                bombs_spots(Game_mode_choice);
                play(Game_mode_choice);
            }
            menu_choice=menu();
        }
        if(menu_choice==2)
        {
            player_number=load_game()-1;
            menu_choice=1;    
        }
        if(menu_choice==3)
        {
            player_number=change_name();
            menu_choice=menu();
        }
        if(menu_choice==4)
        {
            leaderboard();
            menu_choice=menu();
        }
    }
    if(menu_choice==5)
    {
        change_color_rgb(237, 12, 12);
        printf("%c", 3);
        reset_color();
        change_color_rgb(158, 237, 12);
        printf(" SEE YOU SOON ");
        reset_color();
        change_color_rgb(237, 12, 12);
        printf("%c", 3);
        reset_color();
        delay(5000);
        return 0;
    }    
}