#include "stdafx.h"
#include "list.h"
#include <string>
#include <iostream>
using namespace std;


list::list()
{
	
	next = nullptr;
	info = "";
}

void list::add(int i, string data) {

	if (i == 0)
	{
		this->info = data;
	}
	else
	{
		if (this->next == nullptr)
		{
			this->next = new list();
			this->next->add(i - 1, data);
		}
		else
		{
			this->next->add(i - 1, data);
		}
	}
}

void list::get(int i)
{
	if (next == nullptr && info == "")  //чекаем пустой список или нет
	{
		cout << "list is empty" << endl;
		return;
	}
	bool empty = false; //чекаем создан элемент или нет
	list *pp = this;
	for (int j = 0; j < i; j++)
	{
		if (pp->next == nullptr&& j != 0)
		{
			empty = true;
			break;
		}
		pp = pp->next;
	}
	if (!empty)
	{
		cout << pp->info.data() << endl;
	}
	else
	{
		cout << "Index not created" << endl;
	}

}

void list::del(int i)
{
	list *p = this;
	list *pp;
	if (next == nullptr && info == "")
	{
		cout << "list is empty" << endl;
		return;
	}
	if (i = 0)   //удаление со сдвигом т.е. был 5 элемент = 10, при удалении 3 элемента, 4 элемент = 10
	{			 //а 5 больше не существует
		pp = p;
		p = p->next;
		delete pp;
	}
	else
	{
		for (int j = 0; j < i - 1; j++)
		{

			p = p->next;
		}
		pp = p;			//сохраняем предыдущий элемент
		p = p->next;
		pp->next = p->next;  //меняем указатель на предыдущем на указатель на следующий
		delete p;
	}
}