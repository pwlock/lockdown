/* ffs.c
   Purpose: The implementation for ffs{l} */
#include <strings.h>

int ffs(int _num)
{
    return ffsl(_num);
}

int ffsl(long _num)
{
    if (!_num)
        return 0;

    int bit = 0;
    while (!(_num & 1)) {
        _num >>= 1;
        bit++;
    }

    return bit + 1;
}
