#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string N):_Name(N),_HitPoint(10),_Energy(10),_Attack(0)
{
    std::cout << "ClapTrap is being created" << std::endl;
}

ClapTrap:: ClapTrap()
{
    std::cout << "ClapTrapm Default Constructor " << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
    std::cout << "Copy ClapTrap Constructor called" << std::endl;
    _Name = copy._Name;
    _HitPoint = copy._HitPoint;
    _Energy = copy._Energy;
    _Attack = copy._Attack;
}

ClapTrap& ClapTrap::operator =(ClapTrap& obj)
{
    _Name =  obj.GetName();
    _HitPoint = obj.GetHitPoint();
    _Energy  = obj.GetEnergy();
    _Attack = obj.GetAttack();
    return *this;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap is being deleted" << std::endl;
}

/***************************************************************************************************************/

void    ClapTrap::SetName(std::string N)
{
    _Name = N;
    return ;
}

/***************************************************************************************************************/

unsigned int    ClapTrap::GetHitPoint()
{
    return (_HitPoint);
}
std::string     ClapTrap::GetName()
{
    return (_Name);
}
unsigned int    ClapTrap::GetEnergy()
{
    return (_Energy);
}

unsigned int    ClapTrap::GetAttack()
{
    return (_Attack);
}
/******************************************** Functions *****************************************************/


void    ClapTrap::attack(const std::string& target)
{
    if (!GetHitPoint() || !GetEnergy ())
    {
        std::cout << "Lah ghaleb makaynchi bach n attacki. a zeen " << std::endl;
        return ;
    }
    std::cout << _Name << " attacks " << target << " causing " << _Attack << " points of damage! " << std::endl;
    _Energy--;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!GetHitPoint() || !GetEnergy ())
    {
        std::cout << "Lah ghaleb mshit " << std::endl;
        return ;
    }
    _Energy--;
    _HitPoint += amount;
    std::cout << _Name << " has been repaired, causing " << amount << " points regained!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    _HitPoint -= amount;
    std::cout << _Name << " took Damage, causing " << amount << " points of damage! " << std::endl;
   
}