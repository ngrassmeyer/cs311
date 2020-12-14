// CS 311 HW 5
// Vector Class
// Noah Grassmeyer

#include <iostream>

using namespace std;

class VectorDouble
{

private:

    double* _pda;

public:

    int maxCount;
    int count;

    VectorDouble() : maxCount{ 50 }, _pda{ new double[maxCount] }, count{ 0 } {}            // Default Constructor

    VectorDouble(int maxCount) : maxCount{ maxCount }, _pda{ new double[maxCount] }, count{ 0 }   // Parameterized Constructor
    {
        if (maxCount < 0)
        {
            cerr << "\nInvalid vector size. Exiting program.\n";
            exit(1);
        }
    }

    VectorDouble(const VectorDouble& that)                                                  // Copy Constructor
    {
        this->maxCount = that.maxCount;
        this->count = that.count;

        this->_pda = new double[maxCount];                                                  // Deep Copy
        for (int i = 0; i < count; i++)
        {
            this->_pda[i] = that._pda[i];
        }
    }

    VectorDouble& operator = (const VectorDouble& that)                                     // Copy Assignment Operator
    {
        if (this != &that)
        {
            this->maxCount = that.maxCount;
            this->count = that.count;

            double* temp = _pda;
            this->_pda = new double[maxCount];                                                  // Deep Copy
            for (int i = 0; i < count; i++)
            {
                this->_pda[i] = that._pda[i];
            }
            delete[] temp;
        }

        return *this;
    }

    friend bool operator == (const VectorDouble& v1, const VectorDouble& v2)                // Overload == Operator
    {
        if (v1.count != v2.count)                                                           // Check if amount of occupied positions are same in both dynamic arrays.
        {
            return 0;                                                                       // If not they are not equal.
        }

        for (int i = 0; i < v1.count; i++)                                                  // If amount of occupied positions are the same for both dynamic arrays but any of those positions are not the same, they are not equal. 
        {
            if (v1._pda[i] != v2._pda[i])
            {
                return 0;
            }
        }

        return 1;                                                                           // Otherwise they are equal.
    }

    void push_back(const double val)
    {
        if (count == maxCount)                                                              // If count == maxCount, double the size of _pda and double the value for maxCount.
        {
            double* temp = new double[maxCount];                                            // Deep Copy

            for (int i = 0; i < count; i++)
            {
                temp[i] = _pda[i];
            }

            maxCount *= 2;

            _pda = new double[maxCount];

            for (int i = 0; i < count; i++)
            {
                _pda[i] = temp[i];
            }

            delete[] temp;
        }

        _pda[count] = val;

        count++;
    }

    int capacity()
    {
        return maxCount;
    }

    int size()
    {
        return count;
    }

    void reserve(const int n)
    {
        if (n > maxCount)                                                                   // Reallocate the vector to size n if n is larger than current possible vector allocation.
        {
            double* temp = new double[maxCount];                                            // Deep Copy

            for (int i = 0; i < count; i++)
            {
                temp[i] = _pda[i];
            }

            maxCount = n;

            _pda = new double[maxCount];

            for (int i = 0; i < count; i++)
            {
                _pda[i] = temp[i];
            }

            delete[] temp;
        }
    }

    void resize(const int n, int val = 0)
    {
        reserve(n);     // Reallocate "vector" if resizing larger than the maxCount.

        if (n > count)                          // If resizing larger than spaces occupied in "vector", fill the remaining spaces.
        {
            for (int i = count; i < n; i++)
            {
                _pda[i] = val;
            }
            count = n;
        }

        if (n < count)                          // If resizing smaller than spaces occupied in "vector", destroy spaces past n - 1.
        {
            for (int i = count - 1; i >= n; i--)
            {
                _pda[i] = NULL;
            }
            count = n;
        }
    }

    double valueAt(const int loc)
    {
        if ((loc < 0) || (loc >= count))
        {
            cerr << "\nAccess violation. Location does not exist in vector. Exiting program.\n";
            exit(1);
        }

        return _pda[loc];
    }

    void changeValueAt(const int val, const int loc)
    {
        if ((loc < 0) || (loc >= count))
        {
            cerr << "\nAccess violation. Location does not exist in vector. Exiting program.\n";
            exit(1);
        }

        _pda[loc] = val;
    }

    ~VectorDouble()                                                                         // Destructor
    {
        delete[] _pda;
    }

};

int main()
{
    VectorDouble v1{ 4 };

    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(8);
    v1.push_back(8);
    v1.push_back(9);
    v1.push_back(8);
    v1.push_back(3);
    v1.push_back(8);

    VectorDouble v2{ 20 };

    v2.push_back(5);
    v2.push_back(7);
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(5);
    v2.push_back(8);
    v2.push_back(8);
    v2.push_back(9);
    v2.push_back(8);
    v2.push_back(3);
    v2.push_back(8);

    cout << (v1 == v2) << endl << endl << v2.capacity() << endl << endl;

    VectorDouble v3{ v2 };

    cout << (v1 == v3) << endl << endl;

    v3.push_back(1);

    cout << (v3 == v2) << endl << endl;

    v2 = v3;

    cout << (v3 == v2) << endl << endl;

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.valueAt(i) << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < v1.size(); i++)
    {
        v1.changeValueAt(0, i);
        cout << v1.valueAt(i) << " ";
    }

    cout << endl << endl;

    VectorDouble v4;

    cout << v4.capacity() << endl << endl;

    v4.reserve(80);

    cout << v4.capacity() << endl << endl;

    cout << v2.size() << endl << endl;

    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2.valueAt(i) << " ";
    }

    cout << endl << endl;

    v2.resize(5);

    cout << v2.size() << endl << endl;

    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2.valueAt(i) << " ";
    }

    cout << endl << endl;

    v2.resize(10, 99);

    cout << v2.size() << endl << endl;

    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2.valueAt(i) << " ";
    }

    cout << endl << endl << v2.capacity() << endl << endl;

    v2.resize(25);

    cout << v2.size() << endl << endl;

    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2.valueAt(i) << " ";
    }

    cout << endl << endl;

    return 0;
}
