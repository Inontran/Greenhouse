#define NULL (void*)0

class Menu{
	public:
		// Menu();
		Menu(char *name, int number, char **name_items);
		Menu(char *name, int number, char **name_items, char **value_items);
		~Menu();

		//геттеры
		char *get_name_menu();
		// String get_name_menu();
		char **get_name_items();
		char **get_value_items();
		Menu *get_submenu(int number);
		int get_amount_items();
		Menu *get_parent_menu();

		// void set_parent_menu(Menu *menu);
		void add_submenu(Menu *submenu, int menu_number_item);
		void set_value_items(char *new_value, int menu_number_item);
	private:
		int amount_items;
		char **name_items;
		char **value_items;
		Menu **submenu;
		Menu *parent_menu = NULL;
		char *name_menu;
		// String name_menu;
};