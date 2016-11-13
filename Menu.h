// #include <Item.h>
// using namespace std;


class Menu{
	public:
		// Menu();
		Menu(char *name, int number, char **name_items);
		Menu(char *name, int number, char **name_items, char **value_items);
		~Menu();

		//геттеры
		char *get_name_menu();
		char **get_name_items();
		char **get_value_items();
		Menu **get_submenus();
		int get_amount_items();

		void add_submenu(Menu *new_submenu, int number_item);
	private:
		int amount_items;
		char **name_items;
		char **value_items;
		Menu **submenus;
		char *name_menu;
};