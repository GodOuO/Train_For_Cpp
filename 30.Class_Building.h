#include<iostream>
#include<string>
using namespace std;
class Building
{
friend class GoodGay;
friend void goodGay(Building *Build);
private:
    string m_BedRoom;
public:
    string m_SittingRoom;
    Building(/* args */);
    ~Building();
};

Building::Building(/* args */)
{
    m_SittingRoom = "SittingRoom";
    m_BedRoom = "BedRoom";
}

Building::~Building()
{
}