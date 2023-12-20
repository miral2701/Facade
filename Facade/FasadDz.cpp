#include <iostream>
#include <string>
using namespace std;
/*
 * Фасад предоставляет унифицированный интерфейс вместо набора интерфейсов некоторой подсистемы.
 * Фасад определяет интерфейс более высокого уровня, который упрощает использование подсистемы.
 * Разбиение на подсистемы облегчает проектирование сложной системы в целом.
 * Общая цель всякого проектирования - свести к минимуму зависимость подсистем друг от друга и обмен информацией между ними.
 * Один из способов решения этой задачи - введение объекта фасад, предоставляющий единый упрощенный интерфейс к более сложным системным средствам.

 Классы подсистемы:
 - реализуют функциональность подсистемы;
 - выполняют работу, порученную объектом Facade;
 - ничего не «знают» о существовании фасада, то есть не хранят ссылок на него.
  */
class GPU
{
public:
	void Start()
	{
		cout << "запуск.\n";
	}
	void CheckConectionWithDisplay()
	{
		cout << "проверка связи с монитором.\n";
	}
	void ShowRAMData() {
		cout << " вывод данных об оперативной памяти\n";
	}
	void ShowCDRederData() {
		cout << " вывод информации об устройстве чтения дисков\n";
	}
	void ShowVinchesterData() {
		cout << "  вывод данных о винчестере.\n";
	}
	void ShowGoodBuyMassage() {
		cout << "вывести на монитор данные прощальное сообщение\n";
	}
};

class RAM
{
public:
	void Start()
	{
		cout << " запуск устройств.\n";
	}
	void Analis() {
		cout << " : анализ памяти.\n";

	}
	void Clear() {
		cout << " очистка памяти.\n";
	}

};

class Vinchester
{
public:
	void Start()
	{
		cout << "запуск.\n";
	}
	void Check() {
		cout << "проверка загрузочного сектора.\n";
	}
	void Stop() {
		cout << " остановка устройства.\n";
	}

};

class CDReader
{
public:
	void Start()
	{
		cout << "запуск.\n";
	}
	void checkCD()
	{
		cout << " проверка наличия диска\n";
	}
	void Return() {
		cout << " вернуть в исходную позицию.\n";
	}
};

class PowerUnit
{
public:
	void serveVoltage()
	{
		cout << "подать питание\n";
	}
	void serveVoltageToGPU()
	{
		cout << "подать питание на видеокарту\n";
	}
	void serveVoltageToRAM()
	{
		cout << "подать питание на оперативную память\n";
	}
	void serveVoltageToCDReader()
	{
		cout << "подать питание на устройство чтения дисков\n";
	}
	void serveVoltageToVinchester()
	{
		cout << " подать питание на винчестер\n";
	}
	void stopVoltageToGPU()
	{
		cout << "прекратить питание видео карты.\n";
	}
	void stopVoltageToRAM()
	{
		cout << " прекратить питание оперативной памяти\n";
	}
	void stopVoltageToCDReader()
	{
		cout << "прекратить питание устройства чтения дисков.\n";
	}
	void stopVoltageToVinchester()
	{
		cout << " прекратить питание винчестера.\n";
	}
	void Stop() {
		cout << "выключение.\n";
	}
};

class Sensors
{
public:
	void checkVoltage()
	{
		cout << " проверить напряжение\n";
	}
	void checkTemperatureInPowerunit()
	{
		cout << "  проверить температуру в блоке питания.\n";
	}
	void checkTemperatureInGPU()
	{
		cout << "  проверить температуру в видеокарте.\n";
	}
	void checkTemperatureInRAM()
	{
		cout << "  проверить температуру в оперативной памяти.\n";
	}
	void checkTemperatureForAll()
	{
		cout << " проверить температуру всех систем.\n";
	}
};
/*
 * Facade - фасад:
- «знает», каким классам подсистемы адресовать запрос;
- делегирует запросы клиентов подходящим объектам внутри подсистемы;
 */

class Computer
{
	GPU gpu;
	RAM ram;
	Vinchester vinchester;
	CDReader cdreader;
	PowerUnit powerunit;
	Sensors sensors;
public:
	Computer(GPU gpu, RAM ram, Vinchester vinchester, CDReader cdreader, PowerUnit powerunit, Sensors sensors)
	{
		this->gpu = gpu;
		this->ram = ram;
		this->vinchester = vinchester;
		this->cdreader = cdreader;
		this->powerunit = powerunit;
		this->sensors = sensors;
	}
	void Start()
	{
		powerunit.serveVoltage();
		sensors.checkVoltage();
		sensors.checkTemperatureInPowerunit();
		sensors.checkTemperatureInGPU();
		powerunit.serveVoltageToGPU();
		gpu.Start();
		gpu.CheckConectionWithDisplay();
		sensors.checkTemperatureInRAM();
		powerunit.serveVoltageToRAM();
		ram.Start();
		ram.Analis();
		gpu.ShowRAMData();
		powerunit.serveVoltageToCDReader();
		cdreader.Start();
		cdreader.checkCD();
		gpu.ShowCDRederData();
		powerunit.serveVoltageToVinchester();
		vinchester.Start();
		vinchester.Check();
		gpu.ShowVinchesterData();
		sensors.checkTemperatureForAll();
	}
	void Stop()
	{
		vinchester.Stop();
		ram.Clear();
		ram.Analis();
		gpu.ShowGoodBuyMassage();
		cdreader.Return();
		powerunit.stopVoltageToGPU();
		powerunit.stopVoltageToRAM();
		powerunit.stopVoltageToCDReader();
		powerunit.stopVoltageToVinchester();
		sensors.checkVoltage();
		powerunit.Stop();
	}
};



int main()
{
	setlocale(LC_ALL,"rus");
	GPU gpu;
	RAM ram;
	Vinchester vinchester;
	CDReader cdreader;
	PowerUnit powerunit;
	Sensors sensors;

	Computer computer( gpu,  ram,  vinchester,  cdreader,  powerunit,  sensors);

	computer.Start();


	computer.Stop();

	system("pause");
	return 0;
}