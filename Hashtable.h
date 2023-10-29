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

    /// @brief Clears the hash table of all elements.
    /// This function will set all elements in the hash table to -1.
    /// It will also reset the current size of the hash table to 0.
    void clear();

    /// @brief Retrieves the current number of elements in the hash table.
    /// @return The count of current elements in the hash table.
    int size();

    /// @brief Retrieves the maximum capacity of the hash table.
    /// This refers to the total number of slots (both occupied and unoccupied) in the hash table.
    /// @return The capacity of the hash table.
    int capacity();

    /// @brief Retrieves the load factor threshold of the hash table.
    /// The load factor threshold dictates when the hash table should be resized.
    /// @return The current load factor threshold value.
    double getLoadFactorThreshhold();
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

void Hashtable::clear()
{
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }
    currentSize = 0;
}

int Hashtable::size()
{
    return currentSize;
}

int Hashtable::capacity()
{
    return tableSize;
}

double Hashtable::getLoadFactorThreshhold()
{
    return loadFactorThreshold;
}
