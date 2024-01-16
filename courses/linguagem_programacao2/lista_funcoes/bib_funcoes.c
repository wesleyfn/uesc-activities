
int isPerfeito(int num)
{
    int i, acumulo;
    if (num > 0) {
        acumulo = 0;
        for (i = num; i > 1; i--)
            if (num%i == 0) acumulo += num/i;
    }
    return acumulo == num ? 1 : 0;
}

int isPrimo(int num)
{
    int i;
    for (i = 2; i < num-1; i++)
    {
        if (num%i == 0)
            return 0;
    }
    return num > 1 ? 1 : 0;
}