// CS 311 HW 9
// Set Template Class
// Noah Grassmeyer

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class set
{
private:
    vector<T> _set;

    T* _dynArr = nullptr;

public:
    void insert(T i)
    {
        if (any_of(_set.begin(), _set.end(), [i](T j) { return i == j; }))
            return;
        else
            _set.push_back(i);
    }    
    void extract(T i)
    {
        _set.erase(remove(_set.begin(), _set.end(), i));
    }    
    unsigned size()
    {
        return _set.size();
    }    
    bool present(T i)
    {
        return any_of(_set.begin(), _set.end(), [i](T j) { return i == j; });
    }

    T* copy()
    {
        _dynArr = new T[_set.size()];
        for (T i : _set)
            *(_dynArr++) = i;
        return _dynArr -= _set.size();
    }

    void clean()
    {
        delete[] _dynArr;
    }
};

int main()
{
    set<int> s1;

    s1.insert(9);

    cout << s1.size() << endl << endl;    
    
    s1.insert(2);

    cout << s1.size() << endl;

    cout << s1.present(9) << endl << s1.present(3) << endl << endl;

    s1.extract(2);

    cout << s1.present(2) << endl << endl << s1.size() << endl << endl;

    int* copys1 = s1.copy();

    cout << *copys1 << endl;

    s1.clean();

    return 0;
}
