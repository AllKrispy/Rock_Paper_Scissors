#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;
int main()
{
    int userScore=0,AIscore=0,random=0,roundNum=0,winScore=0,matchNum=0,nameNum=0;
    string choice;
    string welcome = "\n\n\t\t\t\t\t\t\t\tWelcome\n\t\t\t\t\t\tThis is a game of Rock-Paper-Scissors";
    string rules = "\n\n\tRules:\n\n\t\t1.Do not mess with the code.\n\n\t\t2.Enter your name.\n\n\t\t3.Enter Rock, Paper or Scissor\n\n\t\t4.Every win against the AI will give you 20 points.\n\n\t\t5.The game will be a best of 5.\n\n\t\t\t\t\t\tLet the game begin!\n\n\t\t";
    string name = "nAME";
    string ansChoice;
    string yesNo;
    string userChoice;
    string AIchoice;
    string winner;
    bool isTrue=true,isPlay=true,correctChoice=true,isCorrect=false,isPlaying=true;
    system ("color 17");
    /*
        Color codes
        {
            0 = Black       8 = Gray
            1 = Blue        9 = Light Blue
            2 = Green       A = Light Green
            3 = Aqua        B = Light Aqua
            4 = Red         C = Light Red
            5 = Purple      D = Light Purple
            6 = Yellow      E = Light Yellow
            7 = White       F = Bright White
        }
    */
    do
    {
        cout << welcome
             << "\n\n\t\tPlay\n\n\t\tRules\n\n\t\tExit"
             << "\n\n\t\t\tWhat would you like to do?: ";
        cin  >> choice;
        if (choice=="Play" || choice=="play" || choice=="PLAY")
        {
            system("pause");
            system("cls");
            matchNum++;
            isPlaying=true;
            while (isPlaying!=false)
            {
                roundNum=0;
                cout << welcome;
                if (nameNum==0)
                {
                    cout << "\n\n\tEnter your name: ";
                    cin  >> name;
                    nameNum++;
                }
                cout << "\n\n\t\t\t\t\t\t\t\tMatch "<<matchNum;
                isPlay=true;
                while(isPlay!=false)
                {
                    roundNum++;
                    cout << "\n\n\t\t\t\t\t\tRound "<< roundNum << "\n\t\t\t"<< name <<"'s Score: "<< userScore << "\t\t\tAI's Score: "<< AIscore;
                    correctChoice=true;
                    while (correctChoice!=false)
                    {
                        cout << "\n\n\t\tRock, Paper or Scissors: ";
                        cin  >> ansChoice;
                        if(ansChoice=="Rock" || ansChoice=="rock" || ansChoice=="ROCK" || ansChoice=="Paper" || ansChoice=="paper" || ansChoice=="PAPER" || ansChoice=="Scissors" || ansChoice=="scissors" || ansChoice=="SCISSORS")
                        {
                            userChoice = (ansChoice=="Rock" || ansChoice=="rock" || ansChoice=="ROCK")?"Rock":(ansChoice=="Paper" || ansChoice=="paper" || ansChoice=="PAPER")?"Paper":"Scissors";
                            correctChoice=false;
                        }
                        else
                        {
                            cout << "\n\n\t\tPlease make a correct selection of Rock, Paper or Scissors.";
                        }
                    }
                    srand(time(0));
                    random = rand() % 3 + 1;
                    if(random==1)
                        AIchoice = "Rock";

                    else if(random==2)
                        AIchoice = "Paper";

                    else
                        AIchoice = "Scissors";

                    cout << "\n\n\t\tAI chose: "<<AIchoice;
                    if((userChoice=="Rock" && AIchoice=="Scissors") || (userChoice=="Paper" && AIchoice=="Rock") || (userChoice=="Scissors" && AIchoice=="Paper"))
                    {
                        userScore+=20;
                        cout << "\n\n\t\t\t\t"<<name<<" won round "<<roundNum<<".";
                    }
                    else if((userChoice=="Scissors" && AIchoice=="Rock") || (userChoice=="Rock" && AIchoice=="Paper") || (userChoice=="Paper" && AIchoice=="Scissors"))
                    {
                        AIscore+=20;
                        cout << "\n\n\t\t\t\tAI won round "<<roundNum<<".";
                    }
                    else if(userChoice==AIchoice)
                    {
                        cout << "\n\n\t\t\t\tRound "<<roundNum<<" tied. Rematch";
                        roundNum--;
                    }
                    if(roundNum==5)
                    {
                        if (userScore>AIscore)
                        {
                            winner=name;
                            winScore=userScore-AIscore;
                            cout << "\n\n\t\t\t\tYAY! "<<name<<" won the match by "<<winScore<<" points.";
                        }
                        else if (userScore==AIscore)
                        {
                            winner="TIE";
                            cout << "\n\n\t\t\t\tMatch tied.";
                        }
                        else
                        {
                            winner="AI";
                            winScore=AIscore-userScore;
                            cout << "\n\n\t\t\t\t"<<name<<" lost the match from AI by "<<winScore<<" points.";
                        }
                        while(isCorrect==false)
                        {
                            cout << "\n\n\t\tDo you want to play again?(y/n): ";
                            cin  >> yesNo;
                            if (yesNo=="Y" || yesNo=="y")
                            {
                                matchNum++;
                                userScore = 0;
                                AIscore = 0;
                                roundNum=0;
                                cout << welcome;
                                isCorrect=true;
                                isPlay=false;
                            }
                            else if(yesNo=="N" || yesNo=="n")
                            {
                                userScore = 0;
                                AIscore = 0;
                                isCorrect=true;
                                isPlay=false;
                                isPlaying=false;
                            }
                            else
                            {
                                isCorrect=false;
                                cout << "Make a correct selection";
                            }
                        }
                    }
                }
                cout << "\n\n\t\t";
                system("pause");
                system("cls");
            }
        }
        else if (choice=="Rules" || choice=="rules" || choice=="RULES")
        {
            system("pause");
            system("cls");
            cout << welcome << rules;
            system("pause");
            system("cls");

        }
        else if (choice=="Exit" || choice=="exit" || choice=="EXIT")
        {
            if(winner!="TIE" && matchNum!=0)
            {
                cout << "\n\n\t\tPrevious match's("<<matchNum<<") winner: "<< winner
                     << "\n\n\t\tThank You For Playing!:-)";
            }
            else if (matchNum==0)
                cout << "\n\n\t\tNo matches played";
            else
                cout << "\n\n\t\tPrevious match was tied";
            isTrue=false;
        }
        else
        {
            cout << "\n\t\t\t\tPlease Make a Proper selection like -- Play, play, Exit, exit, Rules or rules.\n\n\t\t";
            system("pause");
            system("cls");
        }
    }while(isTrue!=false);
    return 0;
}
