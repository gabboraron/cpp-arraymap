#include <iostream>
#include "arsmap.h"
#include <map>
#include <functional>
#include <algorithm>
#include <string>
#include "arsmap.h"

const int max = 1000;

struct string_size_less
{

  bool operator()( const std::string& lhs,
                   const std::string& rhs ) const
  {
    return lhs.size() < rhs.size();
  }

};

int main()
{
  int your_mark = 1;
  /* 2-es */
  int a[ max ] = { 8, 2, 5, 1, 9 };
  std::string s[] = { "Hello", "Goodbye", "Cruel", "World" };

  const arrays_map<int, std::string> m( a, sizeof( a ) / sizeof( a[ 0 ] ),
                                        s, sizeof( s ) / sizeof( s[ 0 ] ) );

  std::string t[] = { "Ada", "C", "C++", "Fortran", "Assembly" };
  int v[] = { 4, 1, 8, 2, 6, 6, 3 };

  arrays_map<std::string, int> lm( t, sizeof( t ) / sizeof( t[ 0 ] ),
                                   v, sizeof( v ) / sizeof( v[ 0 ] ) );

  if ( 4 == m.size() &&
       5 == lm.size() &&
       "Cruel" == m.at( 5 ) &&
       1 == lm.at( "C" ) )
  {
    your_mark = lm.at( "Fortran" );
  }

  /* 3-as */
  --lm[ "Ada" ];
  ++lm[ "C" ];

  if ( "Hello" == m[ 8 ] &&
      your_mark == lm[ "C" ] &&
       2 == v[ 1 ] &&
       3 == v[ 0 ] )
  {
    your_mark = lm[ "Ada" ];
  }

  /* 4-es
  std::string ls[] = { "Modula", "C++", "Swift", "Ruby" };
  int g[] = { 2, 4, 3, 1, 8 };

  const arrays_map<std::string, int> lsg( ls, sizeof( ls ) / sizeof( ls[ 0 ] ),
                                          g, sizeof( g ) / sizeof( g[ 0 ] ) );

  std::map<std::string, int, string_size_less> ms;
  ms[ "Ada" ] = -1;
  lsg.copy( ms );

  std::map<int, std::string, std::greater<int> > mi;
  m.copy( mi );

  std::map<int, std::string> cmi;
  m.copy( cmi );

  if ( 4 == ms[ "Ada" ] && 2 == ms[ "Erlang" ] &&
       0 == mi.count( 9 ) && 1 == mi.count( 5 ) &&
       "World" == cmi[ 1 ] && 4 == cmi.size() )
  {
    your_mark = ms.size();
  }
  */
  /* 5-os
  const std::map<std::string, int, string_size_less> cms = lsg;
  std::map<std::string, int, std::greater<std::string> > mlm = lm;
  std::map<int, std::string> oms = m;

  if ( 1 == cms.count( "Rust" ) &&
       2 == mlm[ "C" ] && 0 == cms.count( "C" ) &&
       "Hello" == oms[ 2 * your_mark ] &&
       4 == oms.size() && 4 == cms.size() )
  {
    your_mark = oms[ 1 ].size();
  }
  */
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}
