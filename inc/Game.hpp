#pragma once

#include <iostream>
#include <Windows.h>

#include "GameTable.hpp"
#include "Controller.hpp"

class Game
{
public:
	Game();

	void run();

private:
	GameTable table;

	enum class GameState { OK, Full, MaxNumber, Exit };
	static constexpr GameTable::size_type DefaultSide = 4;

	void showTable();
};