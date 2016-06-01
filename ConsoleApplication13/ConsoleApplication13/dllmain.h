#pragma once
#define EXPORT extern "C" __declspec (dllexport)

EXPORT int get();
EXPORT int f();