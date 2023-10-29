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

    /// @brief Removes a value from the hash table.
    /// This function will find the value using quadratic probing and set its position to -1.
    /// If the value is not present in the table, it takes no action.
    /// @param value The integer value to be removed from the hash table.
    void remove(int value);
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
    // return hash(H + i * i)
}

void Hashtable::insert(const int value)
{
    int index = hash(value);

    for (int i = 0; table[index] != -1; i++)
    {
        index = quadraticProbing(value, i);
    }

    table[index] = value;
    currentSize++;
}

void Hashtable::remove(int value)
{
    int index = hash(value);

    for (int i = 0; table[index] != value && i < tableSize; i++)
    {
        index = quadraticProbing(value, i);
    }

    if (table[index] == value)
    {
        table[index] = -1;
        currentSize--;
    }
}
