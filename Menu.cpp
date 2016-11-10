#include "Menu.h"

Menu::Menu(){}

Menu::Menu(char *name, char **name_items)
{
	Menu::set_name_menu(name);
	Menu::set_name_items(name_items);
	
}
Menu::Menu(char *name, char **name_items, char **value_items)
{
	Menu::set_name_menu(name);
	Menu::set_name_items(name_items);
	Menu::set_value_items(value_items);
}

Menu::~Menu(){}


//getters and setters
//геттеры и сеттеры
void Menu::set_name_menu(char *name)
{
	*Menu::name_menu = *name;
}

char *Menu::get_name_menu()
{
	return *Menu::name_menu;
}

void Menu::set_name_items(char **values)
{
	**Menu::name_items = **values;
}

char **Menu::get_name_items()
{
	return **Menu::name_items;
}


void Menu::set_value_items(char **values)
{
	**Menu::value_items = **values;
}

char **Menu::get_value_items()
{
	return **Menu::value_items;
}

void Menu::set_submenu(Menu *menu)
{
	*Menu::submenu = *menu;
}

Menu *Menu::get_submenu_item()
{
	return Menu::submenu;
}