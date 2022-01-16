#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>
#include "bread.h"
#include "bun.h"
#include "flour.h"
#include "milk.h"
#include "pasta.h"
#include "cheese.h"
#include "date.h"
#include "correctInput.h"
#include "interface.h"
#include "accounts.h"

using namespace std;

const string FILE_OF_MILK = "./Output/Milk.txt"; //Файл для хранения данных о молоке
const string FILE_OF_CHEESE = "./Output/Cheese.txt"; //Файл для хранения данных о сыре
const string FILE_OF_BREAD = "./Output/Bread.txt"; //Файл для хранения данных о хлебе
const string FILE_OF_BUN = "./Output/Bun.txt"; //Файл для хранения данных о булочках
const string FILE_OF_FLOUR = "./Output/Flour.txt"; //Файл для хранения данных о муке
const string FILE_OF_PASTA = "./Output/Pasta.txt"; //Файл для хранения данных о макаронах
const string FILE_OF_ACCOUNTS = "./Output/Accounts.txt"; //Файл для хранения данных о аккаунтах