#include <Arduino.h>

#define NULL (void*)0

class Menu{
	public:
		// Menu();
		Menu(String *name, int number, String **name_items);
		Menu(String *name, int number, String **name_items, String **value_items);
		~Menu();

		//геттеры
		String *get_name_menu();
		// String get_name_menu();
		String **get_name_items();
		String **get_value_items();
		Menu *get_submenu(int number);
		int get_amount_items();
		Menu *get_parent_menu();

		// void set_parent_menu(Menu *menu);
		void add_submenu(Menu *submenu, int menu_number_item);
		void set_value_items(String *new_value, int menu_number_item);

	private:
		int amount_items;
		String **name_items;
		String **value_items;
		Menu **submenu;
		Menu *parent_menu = NULL;
		String *name_menu;
		// String name_menu;
};