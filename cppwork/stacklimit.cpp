#include <stdio.h>
int id = 0;

void myFunction(int &i)
{
    int j = 1;
    
    
    printf("%d: stack bottom : %p, current : %p\n", id++, &i, &j);
    
    myFunction(i);
}

int main()
{
    int i = 0;
    myFunction(i);
    
    return 0;
}
