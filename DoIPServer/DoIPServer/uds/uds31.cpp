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

#include "uds31.h"

#include <stdint.h>

#include "BigEndian.h"
#include "uds_types.h"

using namespace binary;

Uds31::Uds31(RoutineHandlerType handler = nullptr) {
  this->func_routine_andler_ = handler;
}

void Uds31::HandleRequest(uint8_t* data, size_t length) {
  if (length >= UDS31_GEN_REQ_MIN_LEN) {
    uint8_t routine_controltype = data[UDS31_REQ_IDX_ROUTINE_CONTROL_TYPE];
    uint16_t routine_id = BigEndian::Uint16(&data[UDS31_REQ_IDX_ROUTINE_ID]);
    if (this->func_routine_andler_ != nullptr) {
      this->func_routine_andler_(routine_controltype, routine_id);
    }
  }
}
