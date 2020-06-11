// DoIPServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "BigEndian.h"
#include "uds31.h"
#include "uds_server.h"
#include "doip.h"

using namespace binary;

bool UserHandler_RoutineControl(uint8_t controltype, uint16_t rid) {
  std::cout << "Routine control. Type : " <<std::hex << (uint16_t)controltype << " , rid : " <<  rid << std::endl;
  return true;
}

int main() {
  uint8_t data[] = {0x02, 0xfd, 0x80, 0x01};
  uint16_t ver = BigEndian::Uint16(&data[0]);
  uint32_t ver_and_type = BigEndian::Uint32(&data[0]);
  if ((ver == 0x02fd) &&(ver_and_type == 0x02fd8001)) {
     std::cout << "sanity test for binary package ok\n";   
    }
  /*Create Uds Routine control object with user handler*/
  Uds31 *uds31 = new Uds31(UserHandler_RoutineControl);

  /*Create Uds server object with specific instance of Uds31 object*/
  UdsServer *udsServer = new UdsServer(uds31);

  /*Create DoIP object with specific instance of UdsServer*/
  DoIP *doip = new DoIP(0x0102, 0x0f01, udsServer);
  
  /*Example DoIP request for Routine Control - start routine*/
  uint8_t doip_req_start_routine[] = {0x02, 0xfd, 0x80, 0x01, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x01, 0x01, 0x02, 0x31, 0x01, 0xAA, 0xBB};
  doip->HandleRequest(doip_req_start_routine, sizeof(doip_req_start_routine));
  uint8_t doip_req_stop_routine[] = {0x02, 0xfd, 0x80, 0x01, 0x00, 0x00,
                                      0x00, 0x08, 0x0f, 0x01, 0x01, 0x02,
                                      0x31, 0x02, 0xAA, 0xBB};  
  doip->HandleRequest(doip_req_stop_routine, sizeof(doip_req_stop_routine));
  /*Service not implemented. user handler of Routine control shall not be called*/
  uint8_t doip_req_not_implemented[] = {0x02, 0xfd, 0x80, 0x01, 0x00, 0x00,
                                     0x00, 0x08, 0x0f, 0x01, 0x01, 0x02,
                                     0x32, 0x02, 0xAA, 0xBB};
  doip->HandleRequest(doip_req_not_implemented,
                      sizeof(doip_req_not_implemented));  
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
