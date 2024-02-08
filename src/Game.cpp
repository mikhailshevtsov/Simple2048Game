#include "Game.hpp"

Game::Game()
	: table(DefaultSide)
{
	setlocale(LC_ALL, "Rus");
}

void Game::run()
{
	while (true)
	{
		bool set_side = false;
		GameTable::size_type side = DefaultSide;
		while (!set_side)
		{
			system("cls");

			std::cout << "Choose side of game table (escape to exit)\n";
			for (GameTable::size_type i = 3; i <= 12; ++i)
				std::cout << (side == i ? "->" : "  ") << "[" << (int)i << "]\n";

			switch (waitKey())
			{
			case Key::Up:
				if (side == 3)
					side = 12;
				else
					side--;
				break;
			case Key::Down:
				if (side == 12)
					side = 3;
				else
					side++;
				break;
			case Key::Enter:
				set_side = true;
				break;
			case Key::Escape:
				std::cout << "Buy" << std::endl;
				return;
				break;
			}
		}
		set_side = false;
		if (side != DefaultSide)
			table.reset(side);

		GameState game_state = GameState::OK;
		while (game_state == GameState::OK)
		{
			system("cls");
			
			table.randomGenerate();
			showTable();

			switch (waitKey())
			{
			case Key::Left:
				table.moveLeft();
				break;
			case Key::Right:
				table.moveRight();
				break;
			case Key::Up:
				table.moveUp();
				break;
			case Key::Down:
				table.moveDown();
				break;
			case Key::Escape:
				game_state = GameState::Exit;
				break;
			}

			if (table.getMaximumNumber() == 2048)
				game_state = GameState::MaxNumber;
			else if (table.isFull())
				game_state = GameState::Full;
		}

		switch (game_state)
		{
		case GameState::Full:
			std::cout << "The table is full. Press any key to continue.\n";
			break;
		case GameState::MaxNumber:
			std::cout << "You have achived " << table.getMaximumNumber() << ". Press any key to continue.\n";
			break;
		case GameState::Exit:
			std::cout << "You have decided to exit the game. Buy. Press any key to continue.\n";
			break;
		default:
			break;
		}
		std::cin.get();
	}
}


void Game::showTable()
{
	for (std::size_t i = 0; i < table.getSide() * 16 + 1; ++i)
		std::cout << "-";
	std::cout << "\n";
	for (GameTable::size_type row = 0; row < table.getSide(); ++row)
	{
		for (GameTable::size_type col = 0; col < table.getSide(); ++col)
		{
			std::cout << "|\t";
			if (table(row, col) != GameTable::EMPTY_NUMBER)
				std::cout << table(row, col);
			std::cout << "\t";
		}
		std::cout << "|\n";
		for (std::size_t i = 0; i < table.getSide() * 16 + 1; ++i)
			std::cout << "-";
		std::cout << "\n";
	}
}
