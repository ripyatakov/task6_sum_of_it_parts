#include <iostream>
using namespace std;
#include "parts.h"
void Part::describe()
{
    cout<<"Part "<<this->name<<" subparts are:"<<"\n";
    if (subparts.size() == 0)
    {
        cout<<"It has no subparts.\n\n";
    } else
        for(auto subpart = subparts.begin();subpart!=subparts.end();subpart++)
        {
            cout<<subparts[subpart->first]<<" "<<subpart->first->name;
        }
}
int Part::count_howmany(Part const *p)
{
    int answ = 0;
    if (subparts.size() == 0)
        return 0;
    for (auto subpart = subparts.begin(); subpart != subparts.end();subpart++)
    {
        if (p == subpart->first)
        {
            answ += subpart->second;
        } else
            answ += subpart->second*subpart->first->count_howmany(p);
    }
    return answ;
}
Part* NameContainer::lookup(string const &name)
{
    if (name_map.find(name) == name_map.end())
    {
        name_map[name] = new Part(name);
    }
    return name_map[name];
}
void add_part(string const &x, int q, string const &y){
    Part* px = partContainer.lookup(x);
    Part* py = partContainer.lookup(y);
    px->subparts[py] = q;
}