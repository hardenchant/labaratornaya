// Threads.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <thread>
#include <iostream>
#include <string>
#include <chrono>
#include <mutex>

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

int main()
{
	thread thr2(func2, "bbbb");
	thread thr1(func1, "a");

	thr1.join();
	thr2.join();

    return 0;
}

