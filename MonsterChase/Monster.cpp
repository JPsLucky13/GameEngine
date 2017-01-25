
#include "Monster.h"
#include "MonsterController.h"

Monster::Monster()
{
	monsterName = _strdup("");
	controller = new MonsterController();
}

Monster::Monster(const char * i_monsterName) {
	monsterName = _strdup(i_monsterName);
	controller = new MonsterController();
}

Monster::~Monster() {
	if(monsterName)
	{
	free(monsterName);
	monsterName = NULL;
	}

	if (controller)
	{
	delete(controller);
	controller = NULL;
	}
}

Monster::Monster(const Monster & i_other):
	monsterName(_strdup(i_other.monsterName ? i_other.monsterName : "Monster")),
	controller(new MonsterController(i_other.controller->GetGameObject()))
{
	controller->SetFocusObject(i_other.controller->GetFocusObject());
}

Monster & Monster::operator=(const Monster & i_other)
{
	if (monsterName)
		free(monsterName);


	monsterName = _strdup(i_other.monsterName ? i_other.monsterName : "Monster");


	if (controller)
	{
		delete controller;
	}
	controller = new MonsterController(i_other.controller->GetGameObject());
	controller->SetFocusObject(i_other.controller->GetFocusObject());
	return *this;
}

Monster::Monster(Monster && i_other) :
	monsterName(i_other.monsterName),
	controller(i_other.controller)
{
	i_other.monsterName = nullptr;
	i_other.controller = nullptr;
}

Monster & Monster::operator=(Monster && i_other)
{
	std::swap(monsterName, i_other.monsterName);
	std::swap(controller, i_other.controller);

	return *this;
}

//Get the monster position
Engine::Vector2D Monster::GetPosition() const { return controller->GetPosition(); }

void Monster::SetController(MonsterController * c_Controller)
{
	controller = c_Controller;
}

MonsterController * Monster::GetMonsterController()
{
	return controller;
}

void Monster::SetPosition(const Engine::Vector2D & i_Position)
{
	controller->SetPosition(i_Position);
}

void Monster::UpdateMonster() { controller->UpdateGameObject(); }
void Monster::PositionFormat() { controller->PositionFormat(); }