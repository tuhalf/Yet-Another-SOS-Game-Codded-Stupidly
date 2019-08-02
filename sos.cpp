#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class xox {
  public:
    xox() {
      std::cout << "Board created"<<endl;
     // resetTable();
    }
    void startGame(){
        int res =2;
        //char read;
        resetTable();
       // std::cout << "Are you x or o?"<< endl;
       // std::cin >> read;
       // chooseX(read);
        printBoard();
        while(checkState()==0){
            if (isDraw()){
                res = 0;
                break;
            }
            userGetPlace();
            if(checkState()==0)
                computerMove();
                else{
                    res = 1;
                    break;
                    }
        }
        std::cout<< resPrint[res];
    }
    void setBoardSize(int newSize){
      if (newSize>=3)
        size=newSize;
      else
        std::cout << "Size can't be smaller than 3"<<endl;
    }
      int getBoardSize(){
      return size;
    }
  void printBoard() {
    for (int i = 0; i < size; i++) {
      for (int k = 0; k < size; k++) {
        std::cout <<'\t' << board[i][k];
      }
      std::cout << endl<<endl;
    }
    std::cout << "----"<< endl;
  }
  

  void resetTable() {
    for (int i = 0; i < size; i++) {
      for (int k = 0; k < size; k++) {
        board[i][k] = ']';
      }
    }
  }

  private:
    string resPrint[3]= {"Draw!!","You Win!","PC Wins!"};
    int size = 3;
    char board[99][99];
    char userChar = 'x';
    char pcChar = 'o';
    int winner[2];
    int notLoose[2];
    void computerMove() {
        int place[2];
        if(pcChar=='x'){
        if(board[1][1]==']'){
            place[0]=1;
            place[1]=1;  
            placePos(place,pcChar);
        }else if(board[1][1]==userChar){

        }
        }else{
            winForO();
            noLooseForO();
            if(winner[1]!=99){
                placePos(winner,pcChar);
            }
           /*  else if(board[1][1]==']'&& (isCenterWin())){ //|| !isCenterNested()
            place[0]=1;
            place[1]=1;  
            placePos(place,pcChar);
            }*/else if(notLoose[1]!=99){
                placePos(notLoose,pcChar);
            }

        }
        
    }
    bool isDraw(){
        int zeroCount = 0;
        for (int i = 0; i < size; i++) {
           for (int k = 0; k < size; k++) {
                if(board[i][k]== ']' )
                            zeroCount++;
        }}
        if (zeroCount==0)
                return 1;
        else 
                return 0;
    }

    void chooseX(char c){
        if(c=='x'){
            userChar = 'x';
            pcChar = 'o';
        }else{
            userChar = 'o';
            pcChar = 'x';
        }
    }
   /*  bool isCenterWin(){
        bool result=0;
        for (int i = 0; i < size; i++) {
           for (int k = 0; k < size; k++) {
                if(i==0 && k==1 && board[i][k]== 'x' && board[i+2][k]=='x')
                return 1;
                else if(i==1 && k==0 && board[i][k]== 'x' && board[i][k+2]=='x')
                return 1;
                else if(i==0 && k==0 && board[i][k]== 'x' && board[i+2][k+2]=='x')
                return 1;
                else if(i==2 && k==2 && board[i][k]== 'x' && board[i-2][k-2]=='x')
                return 1;
        }
        
    }return result;
    }*/
    void winForO(){
        winner[0] = 99;
        winner[1] = 99;
        for (int i = 0; i < size; i++) {
           for (int k = 0; k < size; k++) {
              if(k<=size-3 && board[i][k]== 'x' && board[i][k+1]==']' && board[i][k+2]=='x'){
                winner[0] = i;
                winner[1] = k+1;
                }
                else if(i<=size-3 && board[i][k]== 'x' && board[i+1][k]==']' && board[i+2][k]=='x'){
                winner[0] = i+1;
                winner[1] = k;
                }
                else if(i<=size-3 && k<=size-3 && board[i][k]== 'x' && board[i+1][k+1]==']' && board[i+2][k+2]=='x'){
                winner[0] = i+1;
                winner[1] = k+1;
                }
                else if(i>=2 && k>=2 && board[i][k]== 'x' && board[i-1][k-1]==']' && board[i-2][k-2]=='x'){
                winner[0] = i-1;
                winner[1] = k-1;
                }
        }
    }
    }
    int noLooseForO(){
        notLoose[0] = 99;
        notLoose[1] = 99;
        for (int i = 0; i < size; i++) {
           for (int k = 0; k < size; k++) {
                if(board[i][k]==']' && i<=size-3 && k<=size-3 && i>=1 && k>=1 && ((board[i-1][k]!='x' &&board[i+1][k]!='x'&&board[i][k+1]!='x'&&board[i][k-1]!='x'&&board[i+1][k+1]!='x'&&board[i+1][k-1]!='x'))){
                notLoose[0] = i;
                notLoose[1] = k;
                return 0;
                std::cout << "A"<< endl;}
                else if(board[i][k]==']' && (i==0 || i== size-1) && (k!=0 && k!= size-1) && board[i][k]== ']' && board[i][k-1]!='x' && board[i][k+1]!='x'){
                notLoose[0] = i;
                notLoose[1] = k;
                return 0;
                std::cout << "B"<< endl;}else if(board[i][k]==']' && (k==0 || k== size-1) && (i!=0 && i!= size-1) && board[i][k]== ']' && board[i-1][k]!='x' && board[i+1][k]!='x'){
                notLoose[0] = i;
                notLoose[1] = k;
                return 0;
                std::cout << "C"<< endl;}else if(board[i][k]==']' && ((i==0&&k==0) || (i==size-1&&k==size-1) || (i==0&&k==size-1) || (i==size-1&&k==0))){
                notLoose[0] = i;
                notLoose[1] = k;
                return 0;
                std::cout << "D"<< endl;}else if(board[i][k]==']'){
                notLoose[0] = i;
                notLoose[1] = k;
                return 0;
                std::cout << "E"<< endl;}
        }
    }
    }
  /*  bool isCenterNested(){
        bool result=0;
        for (int i = 0; i < size; i++) {
           for (int k = 0; k < size; k++) {
                if(i==0 && k==1 && board[i][k]== 'x' && board[i+2][k]!='x')
                return 1;
                else if(i==1 && k==0 && board[i][k]== 'x' && board[i][k+2]!='x')
                return 1;
                else if(i==0 && k==0 && board[i][k]== 'x' && board[i+2][k+2]!='x')
                return 1;
                else if(i==2 && k==2 && board[i][k]== 'x' && board[i-2][k-2]!='x')
                return 1;
        }
        
    }return result;
    } */

    int checkState() {
        int result =0;

        for (int i = 0; i < size; i++) {
           for (int k = 0; k < size; k++) {
              if(k<=size-3 && board[i][k]== 'x' && board[i][k+1]=='o' && board[i][k+2]=='x')
                return 1;
                else if(i<=size-3 && board[i][k]== 'x' && board[i+1][k]=='o' && board[i+2][k]=='x')
                return 1;
                else if(i<=size-3 && k<=size-3 && board[i][k]== 'x' && board[i+1][k+1]=='o' && board[i+2][k+2]=='x')
                return 1;
                else if(i>=2 && k>=2 && board[i][k]== 'x' && board[i-1][k-1]=='o' && board[i-2][k-2]=='x')
                return 1;
        }
    }

        return result;
    }

    bool checkIfRight(int place[2]){
        if(board[place[0]][place[1]]== ']')
        return 1;
        else
        return 0;
        
    }

    void placePos(int place[2], char player) {
          board[place[0]][place[1]] = player; 
          printBoard();
  }

  void userGetPlace(){
      int place[2];
      if(checkState()==0){
          std::cout << "Insert x Position"<< endl;
          std::cin >>place[1];
          std::cout << "Insert y Position"<< endl;
          std::cin >>place[0];
          if(checkIfRight(place))
                            placePos(place,userChar);
            else {
                std::cout << "This place is not empty. Retype the coordinates"<< endl;
                userGetPlace();
            }
            
      }

  }

};

int main() {
  xox Myxox;
  char continueQ = 'y';
  int mySize =3;
  std::cout <<"What is your board size?"<<endl;
  std::cin >> mySize;
  Myxox.setBoardSize(mySize);
  std::cout <<"Size is set to "<< Myxox.getBoardSize() <<endl;
  while (continueQ=='y'){
  Myxox.startGame();
  std::cout <<"Restart the game?(Y/N)"<<endl;
  std::cin >> continueQ;
    }
}
