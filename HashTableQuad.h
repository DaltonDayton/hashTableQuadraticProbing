#pragma once

class Hashtable
{
private:
    int *table;
    int currentSize;
    int tableSize;
    double loadFactorThreshold;

    // Private helper functions

public:
    // Constructors
    Hashtable();

    // Destructor
    ~Hashtable();

    // Member functions
    void insert(const int value);
};

Hashtable::Hashtable() : currentSize{0}, tableSize{7}, loadFactorThreshold{.65}
{
    table = new int[tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }
}

Hashtable::~Hashtable()
{
}

void Hashtable::insert(const int value)
{
    int index = value % tableSize;

    table[index] = value;
}
