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

void func(string str)
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

int main()
{
	thread thr1(func, "peace");
	thread thr2(func, "of");
	thread thr3(func, "shit");
	thr1.join();
	thr2.join();
	thr3.join();
    return 0;
}

