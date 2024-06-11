#include"fruit.hpp"

Fruit::Fruit(){
  posx = 4;
  posy = 3;
  size = 80;
}

Fruit::~Fruit(){

}

void Fruit::Draw(){
  DrawRectangle(posx*size,posy*size,size,size,RED);
}

void Fruit::Update(){

}
