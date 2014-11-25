#ifndef PREGO_H
#define PREGO_H

using namespace std;

class Prego
{
private:
    int _x, _y;

public:
    int x() const { return _x; }
    int y() const { return _y; }
    
    Prego(int x, int y)
    {
        _x = x, _y = y;
        if (log) cout << "> Prego construindo (" << _x << "," << _y << ")" << endl;
    }

    ~Prego()
    {
        if (log) cout << "> ~Prego destruindo (" << _x << "," << _y << ")" << endl;
    }

    void mudaDeSitio(int x, int y)
    {
        _x = x, _y =y;
    }

    static bool log;
};

bool Prego::log = false;

#endif;
