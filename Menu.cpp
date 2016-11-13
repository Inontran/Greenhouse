#include "Menu.h"

// Menu::Menu(){}

Menu::Menu(char *name, int number, char **name_items)
{
	Menu::name_menu = name;
	Menu::amount_items = number;
	// Menu::set_name_items(name_items);
	Menu::name_items = new char *[number];
	for(int i=0; i<number; i++) 
	{
		Menu::name_items[i] = name_items[i];
	}
	Menu::submenus = new Menu *[number];
}
Menu::Menu(char *name, int number, char **name_items, char **value_items)
{
	Menu::name_menu = name;
	Menu::amount_items = number;
	// Menu::set_name_items(name_items);
	// Menu::set_value_items(value_items);
	Menu::name_items = new char *[number];
	Menu::value_items = new char *[number];
	for(int i=0; i<number; i++) 
	{
		Menu::name_items[i] = name_items[i];
		Menu::value_items[i] = value_items[i];
	}
	
	Menu::submenus = new Menu *[number];

}

Menu::~Menu(){}


//геттеры
char *Menu::get_name_menu()
{
	return Menu::name_menu;
}

char **Menu::get_name_items()
{
	return Menu::name_items;
}


char **Menu::get_value_items()
{
	return Menu::value_items;
}

Menu **Menu::get_submenus()
{
	return Menu::submenus;
}

int Menu::get_amount_items()
{
	return Menu::amount_items;
}



void add_submenu(Menu *new_submenu, int number_item)
{
	Menu::submenus[number_item] = new_submenu;
}