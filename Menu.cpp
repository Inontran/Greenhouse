#include "Menu.h"

Menu::Item::Item(){}

Menu::Item::Item(char *name, char *value, Menu *menu)
{
	Item::set_name_item(name);
	Item::set_value_item(value);
	Item::set_submenu(menu);
}

Menu::Item::~Item(){}

void Menu::Item::set_name_item(char *name)
{
	*Item::name_item = *name;
}

char *Menu::Item::get_name_item()
{
	return name_item;
}

void Menu::Item::set_value_item(char *value)
{
	*Item::value_item = *value;
}

char *Menu::Item::get_value_item()
{
	return value_item;
}

void Menu::Item::set_submenu(Menu *menu)
{
	*Item::submenu = *menu;
}

Menu *Menu::Item::get_submenu()
{
	return submenu;
}



Menu::Menu(char *name, char **name_items)
{
	Menu::set_name_menu(name);
	Item *items = new Item[sizeof(name_items)];
	for(int i = 0; i < sizeof(name_items)/2; i++){
	    // items[i] = new Item(name_items[i], ' ', new Menu);
	    items[i].set_name_item(name_items[i]);
	}
	Menu::set_items(items);
	delete [] items;
}
Menu::Menu(char *name, char **name_items, char **value_items)
{
	Menu::Menu(name, name_items);
	Item *items = get_items();
	for(int i=0; i<sizeof(value_items)/2; i++){
	    if( i == sizeof(items)/2 ){ break; }
	    items[i].set_value_item(value_items[i]);
	}
	Menu::set_items(items);
	delete [] items;
}

Menu::~Menu(){}

void Menu::set_items(Item *items)
{
	*Menu::items = *items;
}

Menu::Item *Menu::get_items()
{
	return items;
}

void Menu::set_name_menu(char *name)
{
	*name_menu = *name;
}

char *Menu::get_name_menu()
{
	return name_menu;
}

char **get_name_items()
{
	char *name_items[]
}

char **get_value_items();
Menu *get_submenu_item();