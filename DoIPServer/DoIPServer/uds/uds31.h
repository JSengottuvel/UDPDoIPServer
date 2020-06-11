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

#ifndef _UDS31_H_
#define _UDS31_H_

#include <stddef.h>
#include <stdint.h>

#include "uds_types.h"

#define UDS31_GEN_REQ_MIN_LEN (3u)

#define UDS31_REQ_IDX_ROUTINE_CONTROL_TYPE (0u)
#define UDS31_REQ_IDX_ROUTINE_ID (1u)

#define UDS31_ROUTINE_CONTROL_TYPE_START_ROUTINE (0u)
#define UDS31_ROUTINE_CONTROL_TYPE_STOP_ROUTINE (1u)

typedef bool (*RoutineHandlerType)(uint8_t, uint16_t);

class Uds31 {
  RoutineHandlerType func_routine_andler_;
  Uds31(RoutineHandlerType handler);

 public:
  void HandleRequest(uint8_t* data, size_t length);
};

#endif /* _UDS31_H_ */
