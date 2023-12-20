#include <iostream>
#include <string>
using namespace std;
/*
 * ����� ������������� ��������������� ��������� ������ ������ ����������� ��������� ����������.
 * ����� ���������� ��������� ����� �������� ������, ������� �������� ������������� ����������.
 * ��������� �� ���������� ��������� �������������� ������� ������� � �����.
 * ����� ���� ������� �������������� - ������ � �������� ����������� ��������� ���� �� ����� � ����� ����������� ����� ����.
 * ���� �� �������� ������� ���� ������ - �������� ������� �����, ��������������� ������ ���������� ��������� � ����� ������� ��������� ���������.

 ������ ����������:
 - ��������� ���������������� ����������;
 - ��������� ������, ���������� �������� Facade;
 - ������ �� ������ � ������������� ������, �� ���� �� ������ ������ �� ����.
  */
class GPU
{
public:
	void Start()
	{
		cout << "������.\n";
	}
	void CheckConectionWithDisplay()
	{
		cout << "�������� ����� � ���������.\n";
	}
	void ShowRAMData() {
		cout << " ����� ������ �� ����������� ������\n";
	}
	void ShowCDRederData() {
		cout << " ����� ���������� �� ���������� ������ ������\n";
	}
	void ShowVinchesterData() {
		cout << "  ����� ������ � ����������.\n";
	}
	void ShowGoodBuyMassage() {
		cout << "������� �� ������� ������ ���������� ���������\n";
	}
};

class RAM
{
public:
	void Start()
	{
		cout << " ������ ���������.\n";
	}
	void Analis() {
		cout << " : ������ ������.\n";

	}
	void Clear() {
		cout << " ������� ������.\n";
	}

};

class Vinchester
{
public:
	void Start()
	{
		cout << "������.\n";
	}
	void Check() {
		cout << "�������� ������������ �������.\n";
	}
	void Stop() {
		cout << " ��������� ����������.\n";
	}

};

class CDReader
{
public:
	void Start()
	{
		cout << "������.\n";
	}
	void checkCD()
	{
		cout << " �������� ������� �����\n";
	}
	void Return() {
		cout << " ������� � �������� �������.\n";
	}
};

class PowerUnit
{
public:
	void serveVoltage()
	{
		cout << "������ �������\n";
	}
	void serveVoltageToGPU()
	{
		cout << "������ ������� �� ����������\n";
	}
	void serveVoltageToRAM()
	{
		cout << "������ ������� �� ����������� ������\n";
	}
	void serveVoltageToCDReader()
	{
		cout << "������ ������� �� ���������� ������ ������\n";
	}
	void serveVoltageToVinchester()
	{
		cout << " ������ ������� �� ���������\n";
	}
	void stopVoltageToGPU()
	{
		cout << "���������� ������� ����� �����.\n";
	}
	void stopVoltageToRAM()
	{
		cout << " ���������� ������� ����������� ������\n";
	}
	void stopVoltageToCDReader()
	{
		cout << "���������� ������� ���������� ������ ������.\n";
	}
	void stopVoltageToVinchester()
	{
		cout << " ���������� ������� ����������.\n";
	}
	void Stop() {
		cout << "����������.\n";
	}
};

class Sensors
{
public:
	void checkVoltage()
	{
		cout << " ��������� ����������\n";
	}
	void checkTemperatureInPowerunit()
	{
		cout << "  ��������� ����������� � ����� �������.\n";
	}
	void checkTemperatureInGPU()
	{
		cout << "  ��������� ����������� � ����������.\n";
	}
	void checkTemperatureInRAM()
	{
		cout << "  ��������� ����������� � ����������� ������.\n";
	}
	void checkTemperatureForAll()
	{
		cout << " ��������� ����������� ���� ������.\n";
	}
};
/*
 * Facade - �����:
- ������, ����� ������� ���������� ���������� ������;
- ���������� ������� �������� ���������� �������� ������ ����������;
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