#include <iostream>
#include "HashTableQuad.h"

int main(int argc, char const *argv[])
{
    Hashtable h1;
    h1.insert(3);
    h1.insert(10);
    h1.remove(3);
    h1.remove(8);
    h1.insert(17);
    h1.insert(24);
    h1.insert(31);
    h1.insert(38);
    h1.insert(45);

    return 0;
}
