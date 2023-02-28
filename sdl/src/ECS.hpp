#pragma once
#ifndef ECS_HPP
#define ECS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentId = std::size_t;

inline ComponentId getComponentId()
{
  static ComponentId lastId = 0;
  return lastId++;
}

template <typename T>
inline ComponentId getComponentTypeId() noexcept
{
  static ComponentId typeId = getComponentId();
  return typeId;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component *, maxComponents>;

/* ============= Component =============== */
class Component
{
public:
  Entity *entity;

  virtual void init() = 0;
  virtual void update() = 0;
  virtual void draw() = 0;

  virtual ~Component(){};
};
/* ============= End Component =============== */

/* ============= Entity =============== */
class Entity
{
private:
  bool active = true;
  std::vector<std::unique_ptr<Component>> components;

  ComponentArray componentArray;
  ComponentBitSet componentBitSet;

public:
  void update();
  void draw();
  bool isActive();
  void destroy();

  template <typename T>
  bool hasComponent() const;

  template <typename T, typename... TArgs>
  T &addComponent(TArgs &&...mArgs);

  template <typename T>
  T &getComponent();
};
/* ============= End Entity =============== */

/* ============= Manager =============== */
class Manager
{
private:
  std::vector<std::unique_ptr<Entity>> entities;

public:
  void update();
  void draw();
  void refresh();
  Entity &addEntity();
};
/* ============= End Manager =============== */

#endif