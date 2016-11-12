// #include <Item.h>
// using namespace std;


class Menu{
	public:
		Menu();
		Menu(char *name, int number, char **name_items);
		Menu(char *name, int number, char **name_items, char **value_items);
		~Menu();

		//getters and setters
		//геттеры и сеттеры
		void set_name_menu(char *name);
		char *get_name_menu();

		void set_name_items(char **strings);
		char **get_name_items();

		void set_value_items(char **strings);
		char **get_value_items();

		void set_submenu(Menu *menu);
		Menu **get_submenu_item();

		void set_amount_items(int number);
		int get_amount_items();
	private:
		int amount_items;
		char **name_items;
		char **value_items;
		Menu **submenu;
		char *name_menu;
};