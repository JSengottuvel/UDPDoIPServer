// DoIPServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "binary/BigEndian.h"

using namespace binary;

int main() {
  uint8_t data[] = {0x02, 0xfd, 0x80, 0x01};
  uint16_t ver = BigEndian::Uint16(&data[0]);
  uint32_t ver_and_type = BigEndian::Uint32(&data[0]);
  if ((ver == 0x02fd) &&(ver_and_type == 0x02fd8001)) {
     std::cout << "sanity test for binary package ok\n";   
    }
  std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
