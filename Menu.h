// #include <Item.h>
// using namespace std;


class Menu{
	class Item{
		public:
			Item();
			Item(char *name, char *value, Menu *menu);
			~Item();

			void set_name_item(char *name);
			char *get_name_item();

			void set_value_item(char *value);
			char *get_value_item();

			void set_submenu(Menu *menu);
			Menu *get_submenu();
		private:
			char *name_item;
			char *value_item;
			Menu *submenu;
	};

	public:
		Menu();
		Menu(char *name, char **name_items);
		Menu(char *name, char **name_items, char **value_items);
		~Menu();

		void set_items(Item *items);
		Item *get_items();

		void set_name_menu(char *name);
		char *get_name_menu();
	private:
		Item *items;
		char *name_menu;
};