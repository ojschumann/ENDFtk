#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk.hpp"

using namespace njoy::ENDFtk;

std::string LRF2();
std::string Tab1();

SCENARIO( "Testing energy-independent unresolved resonances" ){
  GIVEN( "valid ENDF parameters" ){
    long lineNumber = 0;
    int MAT = 5655;
    int MF = 2;
    int MT = 151;
    
    WHEN( "NRO == 0" ){
      std::string ENDF = LRF2();
      auto begin = ENDF.begin();
      auto end = ENDF.end();
      
      resonanceParameters::Base base( 2.3E4, 1.0E5, 2, 1, 0, 0 );
      std::string baseString =
        " 2.300000+4 1.000000+5          2          1          0          05655 2151     \n";
      
      resonanceParameters::unresolved::EnergyIndependent
        ei( base, begin, end, lineNumber, MAT, MF, MT );

      THEN( "the parameters can be verified" ){
        REQUIRE( 2.3E4 == ei.EL() );
        REQUIRE( 1.0E5 == ei.EH() );
        REQUIRE( 0 == ei.NRO() );
        REQUIRE( 0 == ei.NAPS() );
        REQUIRE( 2 == ei.LRU() );
        REQUIRE( 1 == ei.LRF() );
        REQUIRE( 10 == ei.NC() );
          
        REQUIRE( 0.0 == ei.SPI() );
        REQUIRE( 6.233E-1 == Approx( ei.AP() ) );
        REQUIRE( 0 == ei.LSSF() );
        REQUIRE( 3 == ei.NLS() );
        REQUIRE( 3 == ei.lValues().size() );

        SECTION( "L == 0"){
          auto lValue =  ei.lValues()[0];
          REQUIRE( 1.38709E2 == lValue.AWRI() );
          REQUIRE( 0 == lValue.L() );
          REQUIRE( 1 == lValue.NJS() );
          REQUIRE( 1 == lValue.jValues().size() );
          auto jValue =  lValue.jValues()[0];
          REQUIRE( 4.4E3 == jValue.D() );
          REQUIRE( 0.5 == jValue.AJ() );
          REQUIRE( 1.0 == jValue.AMUN() );
          REQUIRE( 4.4E-1 == jValue.GNO() );
          REQUIRE( 5.E-2 == jValue.GG() );
        }

        SECTION( "L == 1"){
          auto lValue =  ei.lValues()[1];
          REQUIRE( 1.38709E2 == lValue.AWRI() );
          REQUIRE( 1 == lValue.L() );
          REQUIRE( 2 == lValue.NJS() );
          REQUIRE( 2 == lValue.jValues().size() );
          auto jValue =  lValue.jValues()[0];
          REQUIRE( 4.4E3 == jValue.D() );
          REQUIRE( 0.5 == jValue.AJ() );
          REQUIRE( 1.0 == jValue.AMUN() );
          REQUIRE( 5.28E-1 == jValue.GNO() );
          REQUIRE( 9.E-2 == jValue.GG() );
        }
      }

      SECTION( "print" ){
        std::string buffer;
        auto output = std::back_inserter( buffer );
        ei.print( output, MAT, MF, MT );

        REQUIRE( buffer == baseString + LRF2() );
      }
    }
    WHEN( "NRO != 0" ){
      std::string ENDF = Tab1() + LRF2();
      auto begin = ENDF.begin();
      auto end = ENDF.end();

      resonanceParameters::Base base( 2.3E4, 1.0E5, 2, 1, 1, 0 );
      std::string baseString =
        " 2.300000+4 1.000000+5          2          1          1          05655 2151     \n";
            
      resonanceParameters::unresolved::EnergyIndependent
        ei( base, begin, end, lineNumber, MAT, MF, MT );
      
      THEN( "the parameters can be verified" ){
        REQUIRE( 2.3E4 == ei.EL() );
        REQUIRE( 1.0E5 == ei.EH() );
        REQUIRE( 1 == ei.NRO() );
        REQUIRE( 0 == ei.NAPS() );
        REQUIRE( 29 == ei.NC() );
        
        REQUIRE( 0.0 == ei.SPI() );
        REQUIRE( 6.233E-1 == Approx( ei.AP() ) );
        REQUIRE( 0 == ei.LSSF() );
        REQUIRE( 3 == ei.NLS() );
        REQUIRE( 3 == ei.lValues().size() );

        REQUIRE( 1 == ei.APE().NR() );
        REQUIRE( 50 == ei.APE().NP() );
        REQUIRE( 50 == ei.APE().x().size() );
        REQUIRE( 50 == ei.APE().y().size() );
        REQUIRE( 1.0E-5 == Approx( ei.APE().x().front() ) );
        REQUIRE( 1.2381 == Approx( ei.APE().y().front() ) );
        REQUIRE( 2.0E5 == Approx( ei.APE().x().back() ) );
        REQUIRE( 0.5803 == Approx( ei.APE().y().back() ) );
      }
      
      SECTION( "print" ){
        std::string buffer;
        auto output = std::back_inserter( buffer );
        ei.print( output, MAT, MF, MT );

        REQUIRE( buffer == baseString + Tab1() + LRF2() );
      }
    }
  }

  GIVEN( "invalid ENDF parameters" ){
    long lineNumber = 0;
    int MAT = 5655;
    int MF = 2;
    int MT = 151;

    std::string ENDF = LRF2();
    ENDF[53] = '-';
    auto begin = ENDF.begin();
    auto end = ENDF.end();

    THEN( "an exception is thrown" ){
      resonanceParameters::Base base( 2.3E4, 1.0E5, 2, 1, 0, 0 );
      REQUIRE_THROWS(
        resonanceParameters::unresolved::EnergyIndependent(
          base, begin, end, lineNumber, MAT, MF, MT ) );
    }
  }
}

std::string LRF2() {
  return
      // base
    // " 2.300000+4 1.000000+5          2          1          0          05655 2151\n"
    // range CONT
    " 0.000000+0 6.233000-1          0          0          3          05655 2151     \n"
    // L=0 LIST                                                                      
    " 1.387090+2 0.000000+0          0          0          6          15655 2151     \n"
    " 4.400000+3 5.000000-1 1.000000+0 4.400000-1 5.000000-2 0.000000+05655 2151     \n"
    // L=1 LIST                                                                      
    " 1.387090+2 0.000000+0          1          0         12          25655 2151     \n"
    " 4.400000+3 5.000000-1 1.000000+0 5.280000-1 9.000000-2 0.000000+05655 2151     \n"
    " 2.200000+3 1.500000+0 1.000000+0 2.640000-1 9.000000-2 0.000000+05655 2151     \n"
    // L=2 LIST                                                                      
    " 1.387090+2 0.000000+0          2          0         12          25655 2151     \n"
    " 2.200000+3 1.500000+0 1.000000+0 3.300000-2 5.000000-2 0.000000+05655 2151     \n"
    " 1.466670+3 2.500000+0 1.000000+0 2.200000-2 5.000000-2 0.000000+05655 2151     \n";
}

std::string Tab1(){
  return
    " 0.000000+0 0.000000+0          0          0          1         505655 2151     \n"
    "         50          2                                            5655 2151     \n"
    " 1.000000-5 1.238100+0 4.000000+1 1.188400+0 5.000000+1 1.153200+05655 2151     \n"
    " 6.000000+1 1.126500+0 7.000000+1 1.105300+0 8.000000+1 1.087800+05655 2151     \n"
    " 9.000000+1 1.073100+0 1.000000+2 1.060500+0 2.000000+2 9.888000-15655 2151     \n"
    " 3.000000+2 9.547000-1 4.000000+2 9.334000-1 5.000000+2 9.184000-15655 2151     \n"
    " 6.000000+2 9.069000-1 7.000000+2 8.978000-1 8.000000+2 8.903000-15655 2151     \n"
    " 9.000000+2 8.839000-1 1.000000+3 8.783000-1 2.000000+3 8.456000-15655 2151     \n"
    " 3.000000+3 8.286000-1 4.000000+3 8.170000-1 5.000000+3 8.081000-15655 2151     \n"
    " 6.000000+3 8.008000-1 7.000000+3 7.946000-1 8.000000+3 7.892000-15655 2151     \n"
    " 9.000000+3 7.844000-1 1.000000+4 7.800000-1 1.200000+4 7.721000-15655 2151     \n"
    " 1.400000+4 7.653000-1 1.600000+4 7.592000-1 1.800000+4 7.536000-15655 2151     \n"
    " 2.000000+4 7.484000-1 2.500000+4 7.369000-1 3.000000+4 7.269000-15655 2151     \n"
    " 3.500000+4 7.180000-1 4.000000+4 7.098000-1 4.200000+4 7.067000-15655 2151     \n"
    " 4.400000+4 7.038000-1 4.600000+4 7.009000-1 4.800000+4 6.980000-15655 2151     \n"
    " 5.000000+4 6.953000-1 5.500000+4 6.888000-1 6.000000+4 6.826000-15655 2151     \n"
    " 6.500000+4 6.767000-1 7.000000+4 6.712000-1 7.500000+4 6.659000-15655 2151     \n"
    " 8.000000+4 6.608000-1 8.500000+4 6.560000-1 9.000000+4 6.513000-15655 2151     \n"
    " 9.500000+4 6.469000-1 2.000000+5 5.803000-1                      5655 2151     \n";
}