

#include<iostream>
#include<conio.h>
#include<windows.h>
#include <unistd.h>
#include<fstream>
using namespace std;

void Logic();
bool GameOver=false;
enum eDirection {STOP=0, UP, DOWN, LEFT, RIGHT};
eDirection dir;
 string arr[15][15];
    int x,y;
    int n=3,m=2;
    char move;
    int score=0;

void newBoard(){
    system("cls");

    for( x=0;x<15;x++){
        for( y=0;y<15;y++){
    if(x==0 || x==14) {
                arr[x][y]="#";
            }
            else if(y==0 || y==14){
        
                arr[x][y] ="#";
                
            }
            else if(x==5 && y>2 && y<10){
                arr[x][y]="#";
            }
            else if(x==9 && y>2 && y<10){
                arr[x][y]="#";
            }
         
            else if(y==9 && x>2 && x<10){
                arr[x][y]="#";
            }

             else if(y==12 && x>2 && x<10){
                arr[x][y]="#";
            }
            else if(y==1 && x>6 && x<10){
                arr[x][y]="#";
            }

            else {
               
                arr[x][y]='.';}
        }
    }

}
void Draw(){
    system("cls");
    for( x=0;x<15;x++){
        for( y=0;y<15;y++){

            if(arr[x][y]==" ") continue;
            if(x==0 || x==14) {
                arr[x][y]="#";
            }
            else if(y==0 || y==14){
        
                arr[x][y] ="#";
                
            }
            else if(x==5 && y>2 && y<10){
                arr[x][y]="#";
            }
            else if(x==9 && y>2 && y<10){
                arr[x][y]="#";
            }
         
            else if(y==9 && x>2 && x<10){
                arr[x][y]="#";
            }

             else if(y==12 && x>2 && x<10){
                arr[x][y]="#";
            }
            else if(y==1 && x>6 && x<10){
                arr[x][y]="#";
            }

            else {
               
                arr[x][y]='.';}
        }
    }
      arr[n][m]='@';
    cout<<"\t\t\tScore:" <<score;
    cout<<endl;
     for( x=0;x<15;x++){
        for( y=0;y<15;y++){
            cout<<arr[x][y]<<" ";
        }
        cout<<endl;
    }
}

void input(){
   
    if(_kbhit())
    {
       
        switch(_getch())
        {
           // cout<<"L"<<endl;
            case 'w':
                dir=UP;
                break;
            case 's':
                dir=DOWN;
                //Logic();
                break;
            case 'a':
                dir=LEFT;
                //Logic();
                break;
            case 'd':
                dir=RIGHT;
                //Logic();
                break;
            default:
                break;
        }
    }
}

void Logic(){

    

    switch(dir)
    {
        case UP:
            n--;
            if(arr[n][m]=="#" || arr[n][m]=="0")
                {
                     GameOver=true;
                    //w
                     break;
                 }
     //   if(n>0){
           
             if(arr[n][m]==".") score++;
              arr[n+1][m]=" ";
       // }
            break;
        case DOWN:
           n++;
            if(arr[n][m]=="#" || arr[n][m]=="0")
                {
                     GameOver=true;
                //    break;
                 }
        //if(n<15){
             if(arr[n][m]==".") 
                score++;
                arr[n-1][m]=" ";
             
            
       // }
        break;
        case RIGHT:
          m++;
           if(arr[n][m]=="#" || arr[n][m]=="0")
                {
                     GameOver=true;
                    // break;
                 }
                 if(arr[n][m]==".") score++;
                  arr[n][m-1]=" ";
      //  if(m<15){
          
             
       // }
            break;
        case LEFT:
           m--;
            if(arr[n][m]=="#" || arr[n][m]=="0")
                {
                     GameOver=true;
                    // break;
                 }
                   if(arr[n][m]==".") score++;
        //if(m>0){
                     arr[n][m+1]=" ";
           
             
       // }
            break;
        default:
            break;
    }
    

}


 int main()
 {
    p:
    while(!GameOver)
    {
        Draw();
        input();
        Logic();
        usleep(500000);
    }
    fstream file,file1;
    int score1;
    file.open("pacman.txt",ios::in);
    if(!file){
        file.open("pacman.txt",ios::app|ios::out);
        file<<score<<" ";
        file.close();
    }else
    {
        file>>score1;
        while(file)
        {
            if(score>score1)
            {
                file1.open("pacman1.txt", ios::app| ios::out);
                cout<<"Congratulation you have scored maximum score till now..."<<endl;
                score1=score;
                file1<<score1<<" ";
                file1.close();
                file.close();
                remove("pacman.txt");
                rename("pacman1.txt", "pacman.txt");
                break;
            }
            file>>score1;
        }
        file.close();
    }
    char i;
    cout<<"If you want to play again press any button except 'o'";
    cin>>i;
    if(i=='o')
    exit(0);
    else
    {
        score=0;
        GameOver= false;
        m=3;
        n=2;
        
        // system("cls");
        // Draw();
            newBoard();
        goto p;
    }
    return 0;
 }
