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
class TextEditor
{
public:
	void CreateCode()
	{
		cout << "Create code\n";
	}
	void Save()
	{
		cout << "Save code\n";
	}
};

class Compiler
{
public:
	void Compile()
	{
		cout << "Compile application\n";
	}
};

class CLR
{
public:
	void Execute()
	{
		cout << "Execute application\n";
	}
	void Finish()
	{
		cout << "Finish application\n";
	}
};

/*
 * Facade - �����:
- ������, ����� ������� ���������� ���������� ������;
- ���������� ������� �������� ���������� �������� ������ ����������;
 */

class VisualStudioFacade
{
	TextEditor textEditor;
	Compiler compiler;
	CLR clr;
public:
	VisualStudioFacade(TextEditor te, Compiler compiler, CLR clr)
	{
		textEditor = te;
		compiler = compiler;
		clr = clr;
	}
	void Start()
	{
		textEditor.CreateCode();
		textEditor.Save();
		compiler.Compile();
		clr.Execute();
	}
	void Stop()
	{
		clr.Finish();
	}
};

// ����� ������������� ������� ��������� ����� �������� ������, ������� �������� ������������� ����������.
class Programmer
{
public:
	void CreateApplication(VisualStudioFacade facade)
	{
		facade.Start();
		facade.Stop();
	}
};

int main()
{
	TextEditor textEditor;
	Compiler compiler;
	CLR clr;

	VisualStudioFacade ide(textEditor, compiler, clr);

	Programmer programmer;
	programmer.CreateApplication(ide);

	system("pause");
	return 0;
}