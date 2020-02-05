#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
std::string ieee_float_to_hex( float f ) {
  static_assert( std::numeric_limits<float>::is_iec559,
                 "native float must be an IEEE float" ) ;

  union { float fval ; std::uint32_t ival ; };
  fval = f ;

  std::ostringstream stm ;
  stm << std::hex << std::uppercase << ival ;

  return stm.str() ;
}

//int main()
//{
  // Debug only
  //std::cout << ieee_float_to_hex( 32.76 ) << '\n' ; // 42030A3D
//}

// [[Rcpp::export]]
std::string ieee_float_to_bit( float f ) {
  static_assert( std::numeric_limits<float>::is_iec559,
                 "native float must be an IEEE float" ) ;

  union { float fval ; std::uint32_t ival ; };
  fval = f ;

  std::bitset<sizeof(float) * CHAR_BIT> bit(ival) ;

  return bit.to_string() ;
}

//int main()
//{
  // Debug only
  //std::cout << ieee_float_to_bit( 32.76 ) << '\n' ; // 01000010000000110000101000111101
//}
