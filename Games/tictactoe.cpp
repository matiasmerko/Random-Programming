#include <iostream>
#include <conio.h>
using namespace std;


char fusha[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='x';bool wasx=true;

void draw(){
    cout<<"Click numbers from 1 to 9 for your turn"<<endl;
    cout<<" "<<fusha[0][0]<<" | "<<fusha[0][1]<<" | "<<fusha[0][2]<<endl;    
    cout<<"-------------\n";
    cout<<" "<<fusha[1][0]<<" | "<<fusha[1][1]<<" | "<<fusha[1][2]<<endl;    
    cout<<"-------------\n";
    cout<<" "<<fusha[2][0]<<" | "<<fusha[2][1]<<" | "<<fusha[2][2]<<endl;    
}

bool gameOver(){
    if(fusha[0][0]==fusha[0][1]&& fusha[0][0]==fusha[0][2]){return true;}
    if(fusha[1][0]==fusha[1][1]&& fusha[1][0]==fusha[1][2]){return true;}
    if(fusha[2][0]==fusha[2][1]&& fusha[2][0]==fusha[2][2]){return true;}
    if(fusha[0][1]==fusha[1][1]&& fusha[0][1]==fusha[2][2]){return true;}
    if(fusha[0][2]==fusha[1][1]&& fusha[0][2]==fusha[2][0]){return true;}
    if(fusha[0][0]==fusha[1][0]&& fusha[0][0]==fusha[2][0]){return true;}
    if(fusha[0][1]==fusha[1][1]&& fusha[0][1]==fusha[2][1]){return true;}
    if(fusha[0][2]==fusha[1][2]&& fusha[0][2]==fusha[2][2]){return true;}
	return false;
}

void input(){
    if(_kbhit()){
        if(wasx){turn='o';wasx=false;}
        else{turn='x';wasx=true;}
        switch(_getch()){
            case '1':
            if(fusha[0][0]!='x' && fusha[0][0]!='o')
                fusha[0][0]=turn;
            else
                if(wasx){wasx=false;}
                else{wasx=true;}
            break;
            case '2':
            if(fusha[0][1]!='x' && fusha[0][1]!='o')
                fusha[0][1]=turn;
            else
                if(wasx){wasx=false;}
                else{wasx=true;}
            break;
            case '3':
            if(fusha[0][2]!='x' && fusha[0][2]!='o')
                fusha[0][2]=turn;
            else
                if(wasx){wasx=false;}
                else{wasx=true;}
            break;
            case '4':
            if(fusha[1][0]!='x' && fusha[1][0]!='o')
                fusha[1][0]=turn;
            else
                if(wasx){wasx=false;}
                else{wasx=true;}
            break;
            case '5':
            if(fusha[1][1]!='x' && fusha[1][1]!='o')
                fusha[1][1]=turn;
            else
                if(wasx){wasx=false;}
                else{wasx=true;}
            break;
            case '6':
            if(fusha[1][2]!='x' && fusha[1][2]!='o')
                fusha[1][2]=turn;
            else
                if(wasx){wasx=false;}
                else{wasx=true;}
            break;
            case '7':
            if(fusha[2][0]!='x' && fusha[2][0]!='o')
                fusha[2][0]=turn;
            else
                if(wasx){wasx=false;}
                else{wasx=true;}
            break;
            case '8':
            if(fusha[2][1]!='x' && fusha[2][1]!='o')
                fusha[2][1]=turn;
            else
                if(wasx){wasx=false;}
                else{wasx=true;}
            break;
            case '9':
            if(fusha[2][2]!='x' && fusha[2][2]!='o')
                fusha[2][2]=turn;
            else
                if(wasx){wasx=false;}
                else{wasx=true;}
            break;
        }
        system("cls");
        draw();
    }    
}


int main()
{
    draw();
    while(!gameOver()){
        input();
	gameOver();
    }
    cout<<"game over"<<endl;
    return 0;
}