#include "Menu.h"

// Menu::Menu(){}

Menu::Menu(char *name, int number, char **name_items)
{
	Menu::set_name_menu(name);
	Menu::set_amount_items(number);
	// Menu::set_name_items(name_items);
	Menu::name_items = new char *[number];
	for(int i=0; i<number; i++) Menu::name_items[i] = name_items[i];
	
}
Menu::Menu(char *name, int number, char **name_items, char **value_items)
{
	Menu::set_name_menu(name);
	Menu::set_amount_items(number);
	// Menu::set_name_items(name_items);
	// Menu::set_value_items(value_items);
	Menu::name_items = new char *[number];
	Menu::value_items = new char *[number];
	for(int i=0; i<number; i++) 
	{
		Menu::name_items[i] = name_items[i];
		Menu::value_items[i] = value_items[i];
	}
	
}

Menu::~Menu(){}


//геттеры и сеттеры
void Menu::set_name_menu(char *name)
{
	Menu::name_menu = name;
}
char *Menu::get_name_menu()
{
	return Menu::name_menu;
}



void Menu::set_name_items(char **strings)
{
	Menu::name_items = strings;
}
char **Menu::get_name_items()
{
	return Menu::name_items;
	// char *menu_strings[] = { "actions", "data", "settings" };
	// char **menu_strings = new char *[3];
	// menu_strings[0] = "actions";
	// menu_strings[1] = "data";
	// menu_strings[2] = "settings";
	// return menu_strings;
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