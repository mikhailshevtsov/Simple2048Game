#include "Controller.hpp"

#include <conio.h>

Key waitKey()
{
	int key = _getch();

	if (key == 224) // Arrow key
		return static_cast<Key>(_getch());

	return static_cast<Key>(key);
}
