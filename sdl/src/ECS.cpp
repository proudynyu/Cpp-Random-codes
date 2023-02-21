#include "ECS.hpp"

/* ============ Entity definitions =============== */
void Entity::update()
{
  for (auto &component : components)
    component->update();
  for (auto &component : components)
    component->draw();
}

void Entity::draw() {}

void Entity::destroy()
{
  active = false;
}

bool Entity::isActive()
{
  return active;
}

template <typename T>
bool Entity::hasComponent() const
{
  return componentBitSet[getComponentTypeId<T>()];
}

template <typename T, typename... TArgs>
T &Entity::addComponent(TArgs &&...mArgs)
{
  T *component(new T(std::forward<TArgs>(mArgs)...));
  component->entity = this;
  std::unique_ptr<Component> uPtr{component};
  components.emplace_back(std::move(uPtr));

  componentArray[getComponentTypeId<T>()] = component;
  componentBitSet[getComponentTypeId<T>()] = true;

  component->init();
  return *component;
}

template <typename T>
T &Entity::getComponent()
{
  auto ptr(componentArray[getComponentTypeId<T>()]);
  return *static_cast<T *>(ptr);
}
/* ============ End Entity definitions =============== */

/* ============ Manager definitions =============== */

void Manager::update()
{
  for (auto &e : entities)
    e->update();
}

void Manager::draw()
{
  for (auto &e : entities)
    e->draw();
}

void Manager::refresh()
{
  entities.erase(
      std::remove_if(
          std::begin(entities),
          std::end(entities),
          [](const std::unique_ptr<Entity> &mEntity)
          {
            return !mEntity->isActive();
          }));
  std::end(entities);
}

Entity &Manager::addEntity()
{
  Entity *e = new Entity();
  std::unique_ptr<Entity> uPtr{e};
  entities.emplace_back(std::move(uPtr));
  return *e;
}

/* ============ End Manager definitions =============== */