#include "GameTable.hpp"
#include "ColumnIterator.hpp"

#include <algorithm>

GameTable::GameTable(size_type side)
	: side(side)
	, max_number(0)
	, table(side, std::vector<number_type>(side, EMPTY_NUMBER))
	, free_space_left(side * side)
	, is_move(true)
{
	srand(unsigned(time(0)));
}

const std::vector<std::vector<GameTable::number_type>>& GameTable::getTable() const noexcept
{
	return table;
}

GameTable::number_type GameTable::getMaximumNumber() const noexcept
{
	return max_number;
}

GameTable::size_type GameTable::getSide() const noexcept
{
	return side;
}

bool GameTable::isFull() const noexcept
{
	return !free_space_left;
}

void GameTable::randomGenerate()
{
	srand(unsigned(time(0)));

	if (is_move)
	{
		number_type randomNumber = std::rand() % 10 ? 2 : 4; // 2 ��� 4
		size_type randomIndex = std::rand() % free_space_left;
		size_type counter = 0;

		bool isFound = false;
		for (auto line = table.begin(); line != table.end() && !isFound; ++line)
		{
			for (auto it = line->begin(); it != line->end() && !isFound; ++it)
			{
				if (*it == EMPTY_NUMBER)
				{
					if (counter == randomIndex)
					{
						*it = randomNumber;
						free_space_left--;
						isFound = true;
					}
					counter++;
				}
			}
		}
	}
	is_move = false;
}

void GameTable::moveLeft()
{
	for (auto& line : table)
		moveLine(std::begin(line), std::end(line));
}

void GameTable::moveRight()
{
	for (auto& line : table)
		moveLine(std::rbegin(line), std::rend(line));
}

void GameTable::moveUp()
{
	for (std::size_t col = 0; col < table.size(); ++col)
		moveLine(col_begin(*this, col), col_end(*this, col));
}

void GameTable::moveDown()
{
	for (std::size_t col = 0; col < table.size(); ++col)
		moveLine(col_rbegin(*this, col), col_rend(*this, col));
}

void GameTable::reset(size_type side)
{
	this->side = side;
	max_number = 0;
	table.resize(side);
	for (auto& line : table)
	{
		line.resize(side, EMPTY_NUMBER);
		std::fill(std::begin(line), std::end(line), EMPTY_NUMBER);
	}
	free_space_left = side * side;
	is_move = true;
}

GameTable::number_type GameTable::operator()(size_type row, size_type col) const
{
	return table.at(row).at(col);
}

GameTable::number_type& GameTable::operator()(size_type row, size_type col)
{
	return table.at(row).at(col);
}

