#pragma once

#include "GameTable.hpp"


class BasicColumnIterator
{
public:
	BasicColumnIterator();
	BasicColumnIterator(GameTable& table, GameTable::size_type row, GameTable::size_type col) noexcept;

	bool operator==(const BasicColumnIterator& other) const noexcept;
	bool operator!=(const BasicColumnIterator& other) const noexcept;

	bool empty() const noexcept;

protected:
	GameTable* ptable = nullptr;
	GameTable::size_type row = 0;
	GameTable::size_type col = 0;
};

class ColumnIterator : public BasicColumnIterator
{
public:
	using BasicColumnIterator::BasicColumnIterator;

	GameTable::number_type operator*() const;
	GameTable::number_type& operator*();

	ColumnIterator& operator++() noexcept;
	ColumnIterator operator++(int) noexcept;

	ColumnIterator& operator+=(GameTable::size_type advance) noexcept;
};

ColumnIterator operator+(const ColumnIterator& it, GameTable::size_type advance);
ColumnIterator operator+(GameTable::size_type advance, const ColumnIterator& it);

ColumnIterator col_begin(GameTable& table, GameTable::size_type col) noexcept;
ColumnIterator col_end(GameTable& table, GameTable::size_type col) noexcept;


class ReverseColumnIterator : public BasicColumnIterator
{
public:
	using BasicColumnIterator::BasicColumnIterator;

	GameTable::number_type operator*() const;
	GameTable::number_type& operator*();

	ReverseColumnIterator& operator++() noexcept;
	ReverseColumnIterator operator++(int) noexcept;

	ReverseColumnIterator& operator+=(GameTable::size_type advance) noexcept;
};

ReverseColumnIterator operator+(const ReverseColumnIterator& it, GameTable::size_type advance);
ReverseColumnIterator operator+(GameTable::size_type advance, const ReverseColumnIterator& it);

ReverseColumnIterator col_rbegin(GameTable& table, GameTable::size_type col) noexcept;
ReverseColumnIterator col_rend(GameTable& table, GameTable::size_type col) noexcept;