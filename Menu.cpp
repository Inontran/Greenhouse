#include "Menu.h"

Menu::Menu(){}

Menu::Menu(char *name, int number, char **name_items)
{
	Menu::set_name_menu(name);
	Menu::set_amount_items(number);
	Menu::set_name_items(name_items);
	
}
Menu::Menu(char *name, int number, char **name_items, char **value_items)
{
	Menu::set_name_menu(name);
	Menu::set_amount_items(number);
	Menu::set_name_items(name_items);
	Menu::set_value_items(value_items);
}

Menu::~Menu(){}


//getters and setters
//геттеры и сеттеры
void Menu::set_name_menu(char *name)
{
	Menu::name_menu = name;
	// *Menu::name_menu = "main menu";
	// *Menu::name_menu = new char("main menu");
	// *Menu::name_menu = new char(name);
}
char *Menu::get_name_menu()
{
	return Menu::name_menu;
	// return "main menu";
}



void Menu::set_name_items(char **strings)
{
	Menu::name_items = strings;
}
char **Menu::get_name_items()
{
	// return Menu::name_items;
	// char *menu_strings[] = { "actions", "data", "settings" };
	char **menu_strings = new char *[3];
	menu_strings[0] = "actions";
	menu_strings[1] = "data";
	menu_strings[2] = "settings";
	return menu_strings;
}



void Menu::set_value_items(char **strings)
{
	**Menu::value_items = strings;
}
char **Menu::get_value_items()
{
	return Menu::value_items;
}



void Menu::set_submenu(Menu *menu)
{
	**Menu::submenu = *menu;
}

Menu **Menu::get_submenu_item()
{
	return Menu::submenu;
}


void Menu::set_amount_items(int number)
{
	Menu::amount_items = number;
}
int Menu::get_amount_items()
{
	return Menu::amount_items;
}