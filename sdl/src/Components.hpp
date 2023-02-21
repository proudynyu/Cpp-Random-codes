#pragma once

#include "ECS.hpp"

class PositionComponent : public Component
{
private:
  int xpos;
  int ypos;

public:
  int x() ;
  int y();

  void init() override;
  void update() override;
  void setPosition(int x, int y);
};