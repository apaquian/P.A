#include "socio.h"

socio::socio(int CI, string name )
{
    this->CI = CI;
    this->name = name;
}
int socio::getCi()
{
    return this->CI;
}
string socio::getName()
{
    return this->name;
}
void socio::setId(int CI)
{
    this->CI = CI;
}
void socio::setName(string name)
{
    this->name = name;
}