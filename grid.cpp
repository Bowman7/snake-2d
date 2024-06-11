#include"raylib.h"

class Grid{
public:
  Grid(){
    xOffset = 0;
    yOffset = 0;
    size = 80;
  }
  ~Grid(){};
  void InitGrid(){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	grid[i][j]=0;
      }
    }
  };
  void DrawGrid(){
    int xOff = 0;
    int yOff = 0;
    for(int j=0;j<10;j++){
      for(int i=0;i<10;i++){
	DrawRectangle(i*size+5,j*size+5,size-5,size-5,GREEN);
      }
    }
  };
private:
  int grid[10][10];
  int xOffset;
  int yOffset;
  int size;
};

