#pragma once
#include <iostream>
#include <vector>
#include <cstdint>

class GameTable
{
public:
	using number_type = std::uint32_t;
	using size_type = std::uint8_t;

public:
	explicit GameTable(size_type side);

	const std::vector<std::vector<number_type>>& getTable() const noexcept;
	number_type getMaximumNumber() const noexcept;
	size_type getSide() const noexcept;

	bool isFull() const noexcept;

	void randomGenerate();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void reset(size_type side);

	number_type operator()(size_type row, size_type col) const;
	number_type& operator()(size_type row, size_type col);

	static constexpr number_type EMPTY_NUMBER = 0;

private:
	std::vector<std::vector<number_type>> table;
	number_type max_number;
	size_type side;
	size_type free_space_left;
	bool is_move;

	template<typename Iterator>
	void moveLine(Iterator begin, Iterator end);
};

template<typename Iterator>
void GameTable::moveLine(Iterator begin, Iterator end)
{
	auto focus = begin;
	for (auto cur = focus + 1; cur != end; ++cur)
	{
		if (*focus != EMPTY_NUMBER && *cur != EMPTY_NUMBER)
		{
			if (*focus == *cur)
			{
				*focus += *cur;
				if (*focus > max_number)
					max_number = *focus;
				*cur = EMPTY_NUMBER;
				free_space_left++;
				is_move = true;
			}
			else
			{
				*(++focus) = *cur;
				if (focus != cur)
				{
					*cur = EMPTY_NUMBER;
					is_move = true;
				}
			}
		}
		else if (*cur != EMPTY_NUMBER)
		{
			*focus = *cur;
			*cur = EMPTY_NUMBER;
			is_move = true;
		}
	}
}