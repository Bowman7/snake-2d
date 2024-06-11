#include"game.hpp"

Game::Game(){
  v_snake[BodyCount].SetID(0);
  BodyCount++;
  v_snake[BodyCount].SetID(BodyCount);
  v_snake[BodyCount].SetPosY(0);
  BodyCount++;
}

Game::~Game(){
  
}

//draw
void Game::Draw(){
  fruit.Draw();
  for(int i=0;i<BodyCount;i++){
    v_snake[i].Draw();
  }
  v_snake[0].DrawHead();
  std::cout<<"Body count: "<<BodyCount<<std::endl;
 
}
//update
void Game::Update(){
  CheckCollision();
}
//handle input
void Game::HandleInput(){

  //south
  if(IsKeyDown(KEY_S)){
    if(v_snake[0].GetPosY()<=9 && v_snake[0].GetPosY()>=0){
      v_snake[0].SetDir(2);
      v_snake[0].MoveToDir();
      for(int i=BodyCount-1;i>0;i--){
	v_snake[i].MoveToDir();
	v_snake[i].SetDir(v_snake[i-1].GetDir());
      }
    }
  }
  //east
  else if(IsKeyDown(KEY_D)){
    if(v_snake[0].GetPosX()<=9 && v_snake[0].GetPosX()>=0){
      v_snake[0].SetDir(3);
      v_snake[0].MoveToDir();
      for(int i=BodyCount-1;i>0;i--){
	v_snake[i].MoveToDir();
	v_snake[i].SetDir(v_snake[i-1].GetDir());
      }
    }
  }
  //west
   else if(IsKeyDown(KEY_A)){
    if(v_snake[0].GetPosX()<=9 && v_snake[0].GetPosX()>=0){
      v_snake[0].SetDir(4);
      v_snake[0].MoveToDir();
      for(int i=BodyCount-1;i>0;i--){
	v_snake[i].MoveToDir();
	v_snake[i].SetDir(v_snake[i-1].GetDir());
      }
    }
  }
  //north
   else if(IsKeyDown(KEY_W)){
    if(v_snake[0].GetPosX()<=9 && v_snake[0].GetPosX()>=0){
      v_snake[0].SetDir(1);
      v_snake[0].MoveToDir();
      for(int i=BodyCount-1;i>0;i--){
	v_snake[i].MoveToDir();
	v_snake[i].SetDir(v_snake[i-1].GetDir());
      }
    }
  }
}

bool Game::EventTriggered(double interval){
  double currentTime= GetTime();
  if(currentTime-lastUpdatedTime>=interval){
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}
void Game::InitInput(){
  if(EventTriggered(0.1)){
    HandleInput();
  }
}
void Game::CheckCollision(){
  if(v_snake[0].GetPosX()==fruit.GetPosX() &&
     v_snake[0].GetPosY()==fruit.GetPosY()
     ){
    AddBody();
    NewFruitPos();
    //std::cout<<"Collision"<<std::endl;
 
  }
  //std::cout<<"no Collision"<<std::endl;
}
//random num
int Game::GetRandomNum(){
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0,9);
  int random = dist6(rng);
  return random;
}
//random position
void Game::GetRandPos(){
  f_ValY = GetRandomNum();
  f_ValX = GetRandomNum();
  //std::cout<<"fx fy"<<f_ValX<<" "<<f_ValY<<std::endl;
  for(Snake snake:v_snake){
    if(snake.GetPosY()==f_ValY && snake.GetPosX()==f_ValX){
      return GetRandPos();
    }
  }
}
//ne wfruit position
void Game::NewFruitPos(){
  Fruit newFruit;
  GetRandPos();
  newFruit.SetPosY(f_ValY);
  newFruit.SetPosX(f_ValX);
  fruit = newFruit;
}
//add body
void Game::AddBody(){
  
  if(v_snake[0].GetDir() == 2){//south
    Snake temp;
    temp.SetID(BodyCount);
    temp.SetPosX(v_snake[BodyCount-1].GetPosX());
    temp.SetPosY(v_snake[BodyCount-1].GetPosY()-1);
    v_snake[BodyCount]=temp;
    BodyCount++;
  }
  //east
  if(v_snake[0].GetDir() == 3){
    Snake temp;
    temp.SetID(BodyCount);
    temp.SetPosX(v_snake[BodyCount-1].GetPosX());
    temp.SetPosY(v_snake[BodyCount-1].GetPosY()-1);
    v_snake[BodyCount]=temp;
    BodyCount++;
  }
  //west
  if(v_snake[0].GetDir() == 4){//south
    Snake temp;
    temp.SetID(BodyCount);
    temp.SetPosX(v_snake[BodyCount-1].GetPosX());
    temp.SetPosY(v_snake[BodyCount-1].GetPosY()-1);
    v_snake[BodyCount]=temp;
    BodyCount++;
  }
  //north
  if(v_snake[0].GetDir() == 1){//south
    Snake temp;
    temp.SetID(BodyCount);
    temp.SetPosX(v_snake[BodyCount-1].GetPosX());
    temp.SetPosY(v_snake[BodyCount-1].GetPosY()-1);
    v_snake[BodyCount]=temp;
    BodyCount++;
  }
}
