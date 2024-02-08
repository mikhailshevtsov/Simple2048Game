#include "ColumnIterator.hpp"

// BasicColumnIterator

BasicColumnIterator::BasicColumnIterator() = default;

BasicColumnIterator::BasicColumnIterator(GameTable& table, GameTable::size_type row, GameTable::size_type col) noexcept
	: ptable(&table), row(row), col(col) {}

bool BasicColumnIterator::operator==(const BasicColumnIterator& other) const noexcept
{
	return this->ptable == other.ptable && this->row == other.row && this->col == other.col;
}

bool BasicColumnIterator::operator!=(const BasicColumnIterator& other) const noexcept
{
	return !operator==(other);
}

bool BasicColumnIterator::empty() const noexcept
{
	return ptable == nullptr;
}


// ColumnIterator

GameTable::number_type ColumnIterator::operator*() const
{
	return (*ptable)(row, col);
}

GameTable::number_type& ColumnIterator::operator*()
{
	return (*ptable)(row, col);
}

ColumnIterator& ColumnIterator::operator++() noexcept
{
	++row;
	return *this;
}

ColumnIterator ColumnIterator::operator++(int) noexcept
{
	ColumnIterator copy(*this);
	++row;
	return copy;
}

ColumnIterator& ColumnIterator::operator+=(GameTable::size_type advance) noexcept
{
	row += advance;
	return *this;
}

ColumnIterator operator+(const ColumnIterator& it, GameTable::size_type advance)
{
	ColumnIterator copy(it);
	copy += advance;
	return copy;
}

ColumnIterator operator+(GameTable::size_type advance, const ColumnIterator& it)
{
	return it + advance;
}

ColumnIterator col_begin(GameTable& table, GameTable::size_type col) noexcept
{
	return ColumnIterator(table, 0, col);
}

ColumnIterator col_end(GameTable& table, GameTable::size_type col) noexcept
{
	return ColumnIterator(table, table.getSide(), col);
}


// ReverseColumnIterator

GameTable::number_type ReverseColumnIterator::operator*() const
{
	return (*ptable)(row - 1, col);
}

GameTable::number_type& ReverseColumnIterator::operator*()
{
	return (*ptable)(row - 1, col);
}

ReverseColumnIterator& ReverseColumnIterator::operator++() noexcept
{
	--row;
	return *this;
}

ReverseColumnIterator ReverseColumnIterator::operator++(int) noexcept
{
	ReverseColumnIterator copy(*this);
	--row;
	return copy;
}

ReverseColumnIterator& ReverseColumnIterator::operator+=(GameTable::size_type advance) noexcept
{
	row -= advance;
	return *this;
}

ReverseColumnIterator operator+(const ReverseColumnIterator& it, GameTable::size_type advance)
{
	ReverseColumnIterator copy(it);
	copy += advance;
	return copy;
}

ReverseColumnIterator operator+(GameTable::size_type advance, const ReverseColumnIterator& it)
{
	return it + advance;
}

ReverseColumnIterator col_rbegin(GameTable& table, GameTable::size_type col) noexcept
{
	return ReverseColumnIterator(table, table.getSide(), col);
}

ReverseColumnIterator col_rend(GameTable& table, GameTable::size_type col) noexcept
{
	return ReverseColumnIterator(table, 0, col);
}
