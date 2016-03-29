#include "stdafx.h"
#include "list.h"
#include <string>
#include <iostream>
using namespace std;


elements::elements()
{
	next = nullptr;
	data = "";
}
list::list()
{
	e = new elements;
}
list::~list()
{
	while (e->next != nullptr)
	{
		elements *t = e->next; 
		delete e;
		e = t;
	}
}
void list::add(int i, string data) {
	elements *temp;
	temp = e;

	if (i == 0)
	{
		temp->data = data;
	}
	else
	{
		if (temp->next == nullptr)
		{
			temp->next = new elements();
			temp = temp->next;
			add(i - 1, data);
		}
		else
		{
			add(i - 1, data);
		}
	}
}

string list::get(int i)
{
	elements *temp;
	temp = e;
	for (int j = 0; j < i; j++)
	{
		//if (temp->next == nullptr) break;
		temp = temp->next;
	}
	return (temp->data);
	//if (next == nullptr && info == "")  //чекаем пустой список или нет
	//{
	//	cout << "list is empty" << endl;
	//	return 0;
	//}
	//bool empty = false; //чекаем создан элемент или нет
	//list *pp = this;
	//for (int j = 0; j < i; j++)
	//{
	//	if (pp->next == nullptr&& j != 0)
	//	{
	//		empty = true;
	//		break;
	//	}
	//	pp = pp->next;
	//}
	//if (!empty)
	//{
	//	return(pp->info.data());
	//}
	//else
	//{
	//	return 0;
	//}

}

void list::del(int i)
{
	if (e->next == nullptr && e->data == "")  return;
	elements *temp;
	temp = e;
	if (i == 0)
	{
		if (e->next == nullptr)
		{
			e->data = "";
		}
		else
		{
			e = e->next;
			delete temp;
		}
	}
	else
	{
		elements *temp2;
		for (int j = 0; j < i - 1; j++)
		{
			temp = temp->next;
		}
		temp2 = temp;
		temp = temp->next;
		temp2->next = temp->next;
		delete temp;
	}
	//list *p = this;
	//list *pp;
	//if (next == nullptr && info == "")
	//{
	//	cout << "list is empty" << endl;
	//	return;
	//}
	//if (i = 0)   //удаление со сдвигом т.е. был 5 элемент = 10, при удалении 3 элемента, 4 элемент = 10
	//{			 //а 5 больше не существует
	//	pp = p;
	//	p = p->next;
	//	delete pp;
	//}
	//else
	//{
	//	for (int j = 0; j < i - 1; j++)
	//	{

	//		p = p->next;
	//	}
	//	pp = p;			//сохраняем предыдущий элемент
	//	p = p->next;
	//	pp->next = p->next;  //меняем указатель на предыдущем на указатель на следующий
	//	delete p;
	//}
}