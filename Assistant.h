#define NULL (void*)0

class Assistant
{
	public:
		Assistant(int luxmetr, int termometr_water, int termometr_air, int sensor_mist, int sensor_level_water, int mistmaker, int phitolamp, int ventilation);
		~Assistant();

		float get_temperature_air();
		float get_temperature_water();
		float get_level_humidity();
		int get_level_light();
		bool water_exists();
		bool mist_exists();

		void power_on_mistmaker();
		void power_off_mistmaker();

		void power_on_phytolamp();
		void power_off_phytolamp();

		void power_on_ventilation(int level_power);
		void power_off_ventilation();

		void power_on_heating_air(int level_power);
		void power_off_heating_air();

	private:
		int pin_luxmetr;
		int pin_termometr_water;
		int pin_termometr_air;
		int pin_sensor_mist;
		int pin_sensor_level_water;

		int pin_mistmaker;
		int pin_phytolamp;
		int pin_ventilation;
		int pin_heating_air;

		float get_temperature(int pin_number);
};