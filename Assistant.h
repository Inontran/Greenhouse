#define NULL (void*)0

class Assistant
{
	public:
		Assistant();
		~Assistant();

		float get_temperature_air();
		float get_temperature_water();
		float get_level_humidity();
		int get_level_light();

	private:
		int pin_luxmetr;
		int pin_termometr_water;
		int pin_termometr_air;
		int pin_sensor_mist;
		int pin_sensor_level_water;


		float get_temperature(int pin_number);
};