#include "socio.h"

socio::socio(string CI, string name )
{
    this->CI = CI;
    this->name = name;
}
string socio::getCi()
{
    return this->CI;
}
string socio::getName()
{
    return this->name;
}  
void socio::setName(string name)
{
    this->name = name;
}

void socio::setCI(string CI)
{
    this->CI = CI;
}

socio::~socio()
{
 

}