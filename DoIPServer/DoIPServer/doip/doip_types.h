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

#define DOIP_GEN_HEADER_SIZE (8u)
#define DOIP_DIAG_HEADER_SIZE (4u)
#define DOIP_VER_INV_VER (0x02fdu)

#define DOIP_GEN_HEADER_IDX_VER (0u)
#define DOIP_GEN_HEADER_IDX_PLTYPE (2u)
#define DOIP_GEN_HEADER_IDX_PLLEN (4u)

#define DOIP_DIAG_HEADER_IDX_SRC_ADDR (0u)
#define DOIP_DIAG_HEADER_IDX_TRGT_ADDR (2u)

#define DOIP_PAYLOAD_TYPE_DIAGMSG (0x8001u)
#define DOIP_PAYLOAD_TYPE_DOIPACK (0x8002u)
#define DOIP_PAYLOAD_TYPE_DOIPNACK (0x8003u)
#define DOIP_PAYLOAD_TYPE_RA_REQ (0x0005u)
#define DOIP_PAYLOAD_TYPE_RA_RES (0x8006u)
