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

#include "doip.h"

#include <stdint.h>

#include <binary/BigEndian.h>

using namespace binary;

DoIP::DoIP(uint16_t local_addr, uint16_t tester_Addr, UdsServer* udsServer) {
  this->tester_addr_ = tester_Addr;
  this->local_addr_ = local_addr;
  this->udsServer_ = udsServer;
}

void DoIP::HandleRequest(uint8_t* data, size_t length) {
  if (length >= DOIP_GEN_HEADER_SIZE) {
    uint16_t doipVer = BigEndian::Uint16(&data[DOIP_GEN_HEADER_IDX_VER]);
    uint16_t doipPlType = BigEndian::Uint16(&data[DOIP_GEN_HEADER_IDX_PLTYPE]);
    uint32_t doipPlLen = BigEndian::Uint32(&data[DOIP_GEN_HEADER_IDX_PLLEN]);
    if (doipVer == DOIP_VER_INV_VER) {
      switch (doipPlType) {
        case DOIP_PAYLOAD_TYPE_DIAGMSG: {
          HandleDiagMsg(&data[DOIP_GEN_HEADER_SIZE],
                        length - DOIP_GEN_HEADER_SIZE);
        } break;
        case DOIP_PAYLOAD_TYPE_RA_REQ: {
          HandleRaReq(&data[DOIP_GEN_HEADER_SIZE],
                      length - DOIP_GEN_HEADER_SIZE);
        } break;
        default: {
        }
      }
    }
  }
}

void DoIP::HandleDiagMsg(uint8_t* data, size_t length) {
  if (length >= DOIP_DIAG_HEADER_SIZE) {
    uint16_t tester_addr =
        BigEndian::Uint16(&data[DOIP_DIAG_HEADER_IDX_SRC_ADDR]);
    uint16_t target_addr =
        BigEndian::Uint16(&data[DOIP_DIAG_HEADER_IDX_TRGT_ADDR]);
    if ((target_addr == this->local_addr_) &&
        (tester_addr == this->tester_addr_)) {
      if (length > DOIP_DIAG_HEADER_SIZE) {
        /*At one byte UDS payload exist.*/
        if (this->udsServer_ != nullptr) {
          this->udsServer_->HandleRequest(&data[DOIP_DIAG_HEADER_SIZE],
                                          length - DOIP_DIAG_HEADER_SIZE);
        }
      }
    }
  }
}

void DoIP::HandleRaReq(uint8_t* data, size_t length) {}
