#ifndef __Rount__Map__
#define __Rount__Map__
#include <vector>
using namespace std;

struct Rount_map
{
	unsigned int desIP;
	unsigned int mask;
	unsigned int masklen;
	unsigned int nexthop;
};

typedef vector<Rount_map> STUD_route_map;

#endif // !__Rount__Map__


