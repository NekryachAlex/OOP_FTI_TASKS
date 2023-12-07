// HashMapStrategy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "HashMap.h"
#include "NumberOfRequests.h"
#include "NoStrategy.h"
#include <iostream>
#include <Windows.h>
#include "TimeoutStrategy.h"
#include <chrono>

int main()
{
    HashMap<double, ULONGLONG, TimeoutStrategy, ULONGLONG> testMap2(2);
}

