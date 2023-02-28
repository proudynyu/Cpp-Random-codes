#include "PositionComponent.hpp"

/* ================ Position Component ============== */


int PositionComponent::x()
{
  return xpos;
};

int PositionComponent::y()
{
  return ypos;
};

void PositionComponent::x(int x)
{
  xpos = x;
};

void PositionComponent::y(int y)
{
  ypos = y;
};


void PositionComponent::init()
{
  xpos = 0;
  ypos = 0;
}

void PositionComponent::update()
{
  xpos++;
  ypos++;
}

void PositionComponent::setPosition(int x, int y)
{
  xpos = x;
  ypos = y;
}
/* ================ End Position Component ============== */