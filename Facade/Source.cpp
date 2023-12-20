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
 * Facade - фасад:
- «знает», каким классам подсистемы адресовать запрос;
- делегирует запросы клиентов подходящим объектам внутри подсистемы;
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

// Фасад предоставляет клиенту интерфейс более высокого уровня, который упрощает использование подсистемы.
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