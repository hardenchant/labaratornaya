// Threads.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <thread>
#include <iostream>
#include <string>
#include <chrono>
#include <mutex>
#include <system_error>

using namespace std;

mutex glock;

void func1(string str)
{
	for (int j = 0; j < 100; j++) {
		glock.lock();
		for (int i = 0; i < 4; i++) {
			cout << str << endl;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		glock.unlock();
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void func2(string str)
{
	glock.lock();
	for (int k = 0; k < 50; k++)
	{
		cout << str << endl;
	}
	glock.unlock();

	for (int j = 0; j < 100; j++) {
		glock.lock();
		for (int i = 0; i < 4; i++) {
			cout << str << endl;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		glock.unlock();
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

mutex m_deadlock1;											//deadlock demo
mutex m_deadlock2;

void deadlock1() {
	
	m_deadlock1.lock(); //
	try {
		m_deadlock1.lock(); // if m_deadlock1 - mutex is locked and get system_error
	}
	catch (const system_error &e) {
		cout << "Err: " << e.code() << endl;
		cout << "mutex -> recursive_mutex == no this error" << endl;
	}
	this_thread::sleep_for(chrono::milliseconds(10));
	m_deadlock2.lock();
	cout << "Never come to do 1" << endl;

}
void deadlock2() {
	m_deadlock2.lock();
	this_thread::sleep_for(chrono::milliseconds(10));
	m_deadlock1.lock();
	cout << "Never come to do 2" << endl;
}															//deadlock demo

int main()
{
	//thread thr2(func2, "bbbb");
	//thread thr1(func1, "a");

	thread deadlock1(deadlock1);
	thread deadlock2(deadlock2);

	//thr1.join();
	//thr2.join();

	
	deadlock1.join();			//dealock thread
	deadlock2.join();			//
	

    return 0;
}

