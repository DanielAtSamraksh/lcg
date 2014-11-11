
#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include <cstdio>
using std::fflush;

#include <cstdlib>
#include "lcg.h"

/// generate first n random numbers where n is the argument or 10.
int main ( int argc, char *argv[] ) {
  cout << "size of long long is " << sizeof (long long) << "\n";
  cout << "size of long is " << sizeof (long) << "\n";
  cout << "size of unsigned long long is " << sizeof (unsigned long long) << "\n";
  cout << "size of unsigned long is " << sizeof (unsigned long) << "\n";
  int n = 10; // default argument.
  
  if ( argc == 2 ) {
    n = atoi ( argv[1] );
    if ( n < 0 ) n *= -1;
  }
  
  lcg_t g, g1;
  cout << "Here are the first " << n << " random numbers:\n";
  for ( int i = 0; i < n; i++ ) {
    cout << g( (unsigned char) i ) << "\n";
    g1( (unsigned char) i );
    fflush ( stdout );
  }

  lcg_t g2;
  vector <unsigned char> v; // used as a buffer
  for ( int i = 0; i < n; i++ ) {
    v.push_back( (unsigned char) i );
  }
  
  cout << "buff hash = " << g2( v.data(), v.size() )
       << " == " << g1.seed << "\n";

  return (g2.seed == g1.seed)? 0: 1;
  
}
    
  
