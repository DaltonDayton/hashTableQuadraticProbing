#pragma once

class Hashtable
{
private:
    int *table;
    int currentSize;
    int tableSize;
    double loadFactorThreshold;

    // Private helper functions

    /// @brief Calculates the hash index for a given value.
    /// @param value The integer value for which the hash index needs to be calculated.
    /// @return The hash index for the input value.
    int hash(int value);

    /// @brief Computes the index for quadratic probing.
    /// This function uses the equation H + c1 * i + c2 * i^2 with c1 = 0 and c2 = 1.
    /// @param H The initial hash index.
    /// @param i The current probing iteration.
    /// @return The computed index after applying quadratic probing.
    int quadraticProbing(int H, int i);

public:
    // Constructors
    Hashtable();

    // Destructor
    ~Hashtable();

    // Member functions

    /// @brief Inserts a value into the hash table at its computed hash index.
    /// @param value The integer value to be inserted into the hash table.
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
    delete[] table;
}

int Hashtable::hash(int value)
{
    return value % tableSize;
}

int Hashtable::quadraticProbing(int H, int i)
{
    return hash(H + (0 * 1) + (1 * (i * i)));
}

void Hashtable::insert(const int value)
{
    int index = hash(value);

    int i{0};
    while (table[index] != -1)
    {
        index = quadraticProbing(value, i);
        i++;
    }

    table[index] = value;
}
