#include "biblaureano.h"

int main()
{
    TEMPO w;

    w = tempoInicio();

    cout << "oi..." << endl;

    while (true)
    {if (tempoPassado(w) > 1000)
    {
        cout <<"tchau"<< endl;
        break;
    }
    }
}
