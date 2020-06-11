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

#include <stdint.h>


#include "uds_server.h"
#include "uds31.h"
#include "uds_types.h"


UdsServer::UdsServer(Uds31* uds31 = nullptr) {
     this->uds31_ = uds31;
     this->sid_ = 0;
}

void UdsServer::HandleRequest(uint8_t* data, size_t length) {
  if (length >= UDS_GEN_REQ_MIN_LEN) {
    this->sid_ = data[UDS_REQ_IDX_SID];
    switch (this->sid_) {
      case UDS_SID_ROUTINE_CONTROL: {
        if (length >= UDS_ROUTINE_CONTROL_REQ_MIN_LEN) {
          if (uds31_ != nullptr) {
            uds31_->HandleRequest(&data[UDS_REQ_SID_LEN],
                                  length - UDS_REQ_SID_LEN);
          }
        }
      } break;
      default: {
      }
    }
  }
}
