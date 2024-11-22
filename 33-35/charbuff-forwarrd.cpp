#include "charbuffer.h"

CharBuffer& assign(CharBuffer& to, const CharBuffer& from)
{
    to = from;
    return to;
}

CharBuffer& assign(CharBuffer& to, CharBuffer&& from)
{
    to = static_cast<CharBuffer&&>(from);
    return to;
}

int main(void)
{
    CharBuffer buff1;
    CharBuffer buff2(100);
    assign(buff1,std::move(buff2));
}