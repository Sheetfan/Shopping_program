#ifndef SHOPPING
#define SHOPPING
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;

const std::array <std::string, 3> products = {"Bread","Egg","Jam"}; //the product in the shop
const std::array <float, 3>  price = {10.0,5.50,7.20}; //the prices for the items

void clear();
void receipt();
void calculateTotal();
void choice();
bool again();
#endif