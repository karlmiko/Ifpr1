//14 - Aula 18

#include "biblaureano.h"



int main()
{
    string GRUPOG [11] = {" my", " our common", " the party’s", " my family’s", " our children’s", " my fellow Europeans’", "the government’s", "the industry’s", " the consumers’", " the immigrants’", " the only truly"};

    string GRUPOA [15] = {" improved", " responsible", " peacekeeping", " free", " pro-life", " politically correct", " integrated", "federal", " progressive", " anti-crime", " drug-addicted", " gradual", " democratic", " genetically engineered", " racial"};

    string GRUPOS [17] = {" freedom", " national security", " abuse", " opportunity", " tax cut", " congress", " task force", " Europe", " decision", " dialogue", " future", " community", " answer", " environment", " set of family-values", " legislation", " discrimination"};

    string GRUPOV [10] = {" benefits", " improves", " decreases", " supports", " is built on", " is the best guarantee for", " creates an opportunity for",  " forms", " is necessary for", " will be established to combat"};

    cout << GRUPOG[randomico(0,10)];
    cout << GRUPOA[randomico(0,14)];
    cout << GRUPOS[randomico(0,16)];
    cout << GRUPOV[randomico(0,9)];
    cout << GRUPOG[randomico(0,10)];
    cout << GRUPOA[randomico(0,14)];
    cout << GRUPOS[randomico(0,16)];
}

