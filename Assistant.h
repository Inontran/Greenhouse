#include <Arduino.h>

#define NULL (void*)0

class Assistant
{
	public:
		Assistant(int luxmetr, int termometr_water, int termometr_air, int sensor_mist, int sensor_level_water, int mistmaker, int phitolamp, int ventilation, int heating_air);
		// ~Assistant();

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

		
		bool get_mistmaker_status();
		char *get_mistmaker_char_status();

		bool get_phytolamp_status();
		char *get_phytolamp_char_status();

		int get_ventilation_status();
		String percent_ventilation_status();
		
		int get_heating_air_status();
		String percent_heating_air_status();

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

		bool mistmaker_status, phytolamp_status;
		int ventilation_status, heating_air_status;


		float get_temperature(int pin_number);
};