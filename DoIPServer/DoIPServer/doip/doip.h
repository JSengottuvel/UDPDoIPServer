/**
MIT License

Copyright (c) 2020 Jayakumar Sengottuvel, www.jayakumar.de

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef _DOIP_H_
#define _DOIP_H_

#include <stddef.h>
#include <stdint.h>

#include "doip_types.h"
#include <uds/uds_server.h>

class DoIP {
 public:
  DoIP(uint16_t local_addr, uint16_t tester_Addr, UdsServer* udsServer);
  void HandleRequest(uint8_t* data, size_t length);

 private:
  void HandleDiagMsg(uint8_t* data, size_t length);
  void HandleRaReq(uint8_t* data, size_t length);
  uint16_t tester_addr_;
  uint16_t local_addr_;
  UdsServer* udsServer_;
};

#endif /*_DOIP_H_*/
