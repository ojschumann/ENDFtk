#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk/section/23.hpp"

// other includes
#include "ENDFtk/tree/Section.hpp"

// convenience typedefs
using namespace njoy::ENDFtk;

std::string chunk();
void verifyChunk( const section::Type< 23 >& );
std::string validSEND();
std::string invalidSEND();

SCENARIO( "section::Type< 23 >" ) {

  GIVEN( "valid data for a section::Type< 23 >" ) {

    std::string sectionString = chunk() + validSEND();

    WHEN( "the data is given explicitly" ) {

      int mt = 102;
      int zaid = 1001;
      double awr = 0.9991673;
      double epe = 2.224648e+6;
      double efl = 3.224648e+6;
      std::vector< long > interpolants = { 5, 2 };
      std::vector< long > boundaries = { 3, 6 };
      std::vector< double > energies = { 1e-5, 2e-5, 7.5e+5,
                                         1.9e+7, 1.95e+7, 2e+7 };
      std::vector< double > xs = { 1.672869e+1, 1.182897e+1, 3.347392e-5,
                                   2.751761e-5, 2.731301e-5, 2.710792e-5 };

      section::Type< 23 > chunk( mt, zaid, awr, epe, efl,
                                std::move( boundaries ),
                                std::move( interpolants ),
                                std::move( energies ), std::move( xs ) );

      THEN( "a section::Type< 23 > can be constructed and "
            "members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 125, 23 );

        CHECK( buffer == sectionString );
      } // THEN
    } // WHEN

    WHEN( "the data is read from a string/stream with a valid SEND" ) {

      auto begin = sectionString.begin();
      auto end = sectionString.end();
      long lineNumber = 0;
      HeadRecord head( begin, end, lineNumber );

      section::Type< 23 > chunk( head, begin, end, lineNumber, 125 );

      THEN( "a section::Type< 23 > can be constructed and "
            "members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 125, 23 );

        CHECK( buffer == sectionString );
      } // THEN
    } // WHEN

    WHEN( "there is a tree::Section" ) {

      tree::Section section( 125, 23, 102, std::string( sectionString ) );

      section::Type< 23 > chunk = section.parse< 23 >();

      THEN( "a section::Type< 23 > can be constructed and "
            "members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 125, 23 );

        CHECK( buffer == sectionString );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid data for a section::Type< 23 >" ) {

    WHEN( "a string representation of a section::Type< 23 > with "
          "an invalid SEND" ) {

      std::string sectionString = chunk() + invalidSEND();
      auto begin = sectionString.begin();
      auto end = sectionString.end();
      long lineNumber = 1;
      HeadRecord head( begin, end, lineNumber );

      THEN( "an exception is thrown" ){

        CHECK_THROWS( section::Type< 23 >( head, begin, end,
                                            lineNumber, 125 ) );
      } // THEN
    } // WHEN
  } // THEN
} // SCENARIO

std::string chunk(){
  return
    " 1.001000+3 9.991673-1          0          0          0          0 12523102     \n"
    " 2.224648+6 3.224648+6          0          0          2          6 12523102     \n"
    "          3          5          6          2                       12523102     \n"
    " 1.000000-5 1.672869+1 2.000000-5 1.182897+1 7.500000+5 3.347392-5 12523102     \n"
    " 1.900000+7 2.751761-5 1.950000+7 2.731301-5 2.000000+7 2.710792-5 12523102     \n";
}

void verifyChunk( const section::Type< 23 >& chunk ) {

  CHECK( 102 == chunk.MT() );
  CHECK( 1001 == chunk.ZA() );
  CHECK( 0.9991673 == Approx( chunk.AWR() ) );
  CHECK( 0.9991673 == Approx( chunk.atomicWeightRatio() ) );
  CHECK( 2.224648e+6 == Approx( chunk.EPE() ) );
  CHECK( 2.224648e+6 == Approx( chunk.subshellBindingEnergy() ) );
  CHECK( 3.224648e+6 == Approx( chunk.EFL() ) );
  CHECK( 3.224648e+6 == Approx( chunk.fluorescenceYield() ) );

  CHECK( 6 == chunk.NP() );
  CHECK( 2 == chunk.NR() );
  CHECK( 2 == chunk.interpolants().size() );
  CHECK( 2 == chunk.boundaries().size() );
  CHECK( 5 == chunk.interpolants()[0] );
  CHECK( 2 == chunk.interpolants()[1] );
  CHECK( 3 == chunk.boundaries()[0] );
  CHECK( 6 == chunk.boundaries()[1] );
  CHECK( 6 == chunk.energies().size() );
  CHECK( 6 == chunk.crossSections().size() );
  CHECK( 1e-5 == Approx( chunk.energies()[0] ) );
  CHECK( 2e-5 == Approx( chunk.energies()[1] ) );
  CHECK( 7.5e+5 == Approx( chunk.energies()[2] ) );
  CHECK( 1.9e+7 == Approx( chunk.energies()[3] ) );
  CHECK( 1.95e+7 == Approx( chunk.energies()[4] ) );
  CHECK( 2e+7 == Approx( chunk.energies()[5] ) );
  CHECK( 1.672869e+1 == Approx( chunk.crossSections()[0] ) );
  CHECK( 1.182897e+1 == Approx( chunk.crossSections()[1] ) );
  CHECK( 3.347392e-5 == Approx( chunk.crossSections()[2] ) );
  CHECK( 2.751761e-5 == Approx( chunk.crossSections()[3] ) );
  CHECK( 2.731301e-5 == Approx( chunk.crossSections()[4] ) );
  CHECK( 2.710792e-5 == Approx( chunk.crossSections()[5] ) );

  CHECK( 5 == chunk.NC() );
}

std::string validSEND(){
  return
    "                                                                   12523  0     \n";
}

std::string invalidSEND(){
  return
    "                                                                   12523  1     \n";
}
