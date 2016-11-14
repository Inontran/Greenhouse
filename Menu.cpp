#include "Menu.h"

// Menu::Menu(){}

Menu::Menu(char *name, int number, char **name_items)
{
	Menu::name_menu = name;
	Menu::amount_items = number;
	Menu::name_items = new char *[number];
	Menu::submenu = new Menu *[number];
	Menu::value_items = new char *[number];
	for(int i=0; i<number; i++) 
	{
		Menu::name_items[i] = name_items[i];
		Menu::value_items[i] = "";
	}
	
}
Menu::Menu(char *name, int number, char **name_items, char **value_items)
{
	Menu::name_menu = name;
	Menu::amount_items = number;
	Menu::name_items = new char *[number];
	Menu::value_items = new char *[number];
	for(int i=0; i<number; i++) 
	{
		Menu::name_items[i] = name_items[i];
		Menu::value_items[i] = value_items[i];
	}
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

Menu **Menu::get_submenu()
{
	return Menu::submenu;
}

int Menu::get_amount_items()
{
	return Menu::amount_items;
}

Menu *Menu::get_parent_menu()
{
	return Menu::parent_menu;
}



void Menu::add_submenu(Menu *submenu, int number_item)
{
 	Menu::submenu[number_item-1] = new Menu(submenu->get_name_menu(), submenu->get_amount_items(), submenu->get_name_items(), submenu->get_value_items());
}