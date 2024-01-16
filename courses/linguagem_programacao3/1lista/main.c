#include <stdio.h>
#include <time.h>
#include "data.h"

int main(void)
{
    Data* data = new_Data();
    setData(data, 4, 2, 2001);

    printf("%s, ", getDiaSemana(data));
    prtData(data);
    return 0;
}