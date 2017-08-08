#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk.hpp"

using namespace njoy::ENDFtk;

std::string LRF2(){
  return
  " 3.809000+4 8.913540+1          0          0          1          03843 2151    1\n"
  " 3.809000+4 1.000000+0          0          1          1          03843 2151    2\n"
  " 6.000000+3 1.000000+5          2          2          0          03843 2151    3\n"
  " 0.000000+0 6.795900-1          0          0          3          03843 2151    4\n"
  " 8.913540+1 0.000000+0          0          0          1          03843 2151    5\n"
  " 5.000000-1 0.000000+0          5          0         84         133843 2151    6\n"
  " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151    7\n"
  " 6.000000+3 1.240600+4 0.000000+0 4.590100-1 2.050000-1 0.000000+03843 2151    8\n"
  " 7.000000+3 1.240600+4 0.000000+0 4.590100-1 2.050000-1 0.000000+03843 2151    9\n"
  " 8.000000+3 1.240600+4 0.000000+0 4.590100-1 2.050000-1 0.000000+03843 2151   10\n"
  " 1.000000+4 1.231300+4 0.000000+0 4.555800-1 2.050000-1 0.000000+03843 2151   11\n"
  " 1.500000+4 1.226300+4 0.000000+0 4.537400-1 2.050000-1 0.000000+03843 2151   12\n"
  " 2.500000+4 1.212200+4 0.000000+0 4.485000-1 2.050000-1 0.000000+03843 2151   13\n"
  " 3.000000+4 1.205400+4 0.000000+0 4.460100-1 2.050000-1 0.000000+03843 2151   14\n"
  " 4.000000+4 1.191800+4 0.000000+0 4.409700-1 2.050000-1 0.000000+03843 2151   15\n"
  " 5.000000+4 1.181000+4 0.000000+0 4.369800-1 2.050000-1 0.000000+03843 2151   16\n"
  " 6.000000+4 1.113000+4 0.000000+0 4.118100-1 2.050000-1 0.000000+03843 2151   17\n"
  " 7.000000+4 1.077400+4 0.000000+0 3.986200-1 2.050000-1 0.000000+03843 2151   18\n"
  " 8.000000+4 1.039500+4 0.000000+0 3.846100-1 2.050000-1 0.000000+03843 2151   19\n"
  " 1.000000+5 9.669700+3 0.000000+0 3.577800-1 2.050000-1 0.000000+03843 2151   20\n"
  " 8.913540+1 0.000000+0          1          0          2          03843 2151   21\n"
  " 5.000000-1 0.000000+0          5          0         84         133843 2151   22\n"
  " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151   23\n"
  " 6.000000+3 1.240600+4 0.000000+0 6.723800+0 2.050000-1 0.000000+03843 2151   24\n"
  " 7.000000+3 1.240600+4 0.000000+0 6.723800+0 2.050000-1 0.000000+03843 2151   25\n"
  " 8.000000+3 1.240600+4 0.000000+0 6.723800+0 2.050000-1 0.000000+03843 2151   26\n"
  " 1.000000+4 1.231300+4 0.000000+0 6.673600+0 2.050000-1 0.000000+03843 2151   27\n"
  " 1.500000+4 1.226300+4 0.000000+0 6.646600+0 2.050000-1 0.000000+03843 2151   28\n"
  " 2.500000+4 1.212200+4 0.000000+0 6.569900+0 2.050000-1 0.000000+03843 2151   29\n"
  " 3.000000+4 1.205400+4 0.000000+0 6.533500+0 2.050000-1 0.000000+03843 2151   30\n"
  " 4.000000+4 1.191800+4 0.000000+0 6.459600+0 2.050000-1 0.000000+03843 2151   31\n"
  " 5.000000+4 1.181000+4 0.000000+0 6.401200+0 2.050000-1 0.000000+03843 2151   32\n"
  " 6.000000+4 1.113000+4 0.000000+0 6.032400+0 2.050000-1 0.000000+03843 2151   33\n"
  " 7.000000+4 1.077400+4 0.000000+0 5.839300+0 2.050000-1 0.000000+03843 2151   34\n"
  " 8.000000+4 1.039500+4 0.000000+0 5.634100+0 2.050000-1 0.000000+03843 2151   35\n"
  " 1.000000+5 9.669700+3 0.000000+0 5.241000+0 2.050000-1 0.000000+03843 2151   36\n"
  " 1.500000+0 0.000000+0          5          0         84         133843 2151   37\n"
  " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151   38\n"
  " 6.000000+3 6.202800+3 0.000000+0 3.361900+0 2.050000-1 0.000000+03843 2151   39\n"
  " 7.000000+3 6.202800+3 0.000000+0 3.361900+0 2.050000-1 0.000000+03843 2151   40\n"
  " 8.000000+3 6.202800+3 0.000000+0 3.361900+0 2.050000-1 0.000000+03843 2151   41\n"
  " 1.000000+4 6.156500+3 0.000000+0 3.336800+0 2.050000-1 0.000000+03843 2151   42\n"
  " 1.500000+4 6.131600+3 0.000000+0 3.323300+0 2.050000-1 0.000000+03843 2151   43\n"
  " 2.500000+4 6.060800+3 0.000000+0 3.285000+0 2.050000-1 0.000000+03843 2151   44\n"
  " 3.000000+4 6.027200+3 0.000000+0 3.266800+0 2.050000-1 0.000000+03843 2151   45\n"
  " 4.000000+4 5.959100+3 0.000000+0 3.229800+0 2.050000-1 0.000000+03843 2151   46\n"
  " 5.000000+4 5.905100+3 0.000000+0 3.200600+0 2.050000-1 0.000000+03843 2151   47\n"
  " 6.000000+4 5.564900+3 0.000000+0 3.016200+0 2.050000-1 0.000000+03843 2151   48\n"
  " 7.000000+4 5.386800+3 0.000000+0 2.919600+0 2.050000-1 0.000000+03843 2151   49\n"
  " 8.000000+4 5.197500+3 0.000000+0 2.817000+0 2.050000-1 0.000000+03843 2151   50\n"
  " 1.000000+5 4.834900+3 0.000000+0 2.620500+0 2.050000-1 0.000000+03843 2151   51\n"
  " 8.913540+1 0.000000+0          2          0          2          03843 2151   52\n"
  " 1.500000+0 0.000000+0          5          0         84         133843 2151   53\n"
  " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151   54\n"
  " 6.000000+3 6.202800+3 0.000000+0 2.233000-1 2.050000-1 0.000000+03843 2151   55\n"
  " 7.000000+3 6.202800+3 0.000000+0 2.233000-1 2.050000-1 0.000000+03843 2151   56\n"
  " 8.000000+3 6.202800+3 0.000000+0 2.233000-1 2.050000-1 0.000000+03843 2151   57\n"
  " 1.000000+4 6.156500+3 0.000000+0 2.216300-1 2.050000-1 0.000000+03843 2151   58\n"
  " 1.500000+4 6.131600+3 0.000000+0 2.207400-1 2.050000-1 0.000000+03843 2151   59\n"
  " 2.500000+4 6.060800+3 0.000000+0 2.181900-1 2.050000-1 0.000000+03843 2151   60\n"
  " 3.000000+4 6.027200+3 0.000000+0 2.169800-1 2.050000-1 0.000000+03843 2151   61\n"
  " 4.000000+4 5.959100+3 0.000000+0 2.145300-1 2.050000-1 0.000000+03843 2151   62\n"
  " 5.000000+4 5.905100+3 0.000000+0 2.125900-1 2.050000-1 0.000000+03843 2151   63\n"
  " 6.000000+4 5.564900+3 0.000000+0 2.003400-1 2.050000-1 0.000000+03843 2151   64\n"
  " 7.000000+4 5.386800+3 0.000000+0 1.939200-1 2.050000-1 0.000000+03843 2151   65\n"
  " 8.000000+4 5.197500+3 0.000000+0 1.871100-1 2.050000-1 0.000000+03843 2151   66\n"
  " 1.000000+5 4.834900+3 0.000000+0 1.740500-1 2.050000-1 0.000000+03843 2151   67\n"
  " 2.500000+0 0.000000+0          5          0         84         133843 2151   68\n"
  " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151   69\n"
  " 6.000000+3 4.135200+3 0.000000+0 1.488700-1 2.050000-1 0.000000+03843 2151   70\n"
  " 7.000000+3 4.135200+3 0.000000+0 1.488700-1 2.050000-1 0.000000+03843 2151   71\n"
  " 8.000000+3 4.135200+3 0.000000+0 1.488700-1 2.050000-1 0.000000+03843 2151   72\n"
  " 1.000000+4 4.104300+3 0.000000+0 1.477600-1 2.050000-1 0.000000+03843 2151   73\n"
  " 1.500000+4 4.087700+3 0.000000+0 1.471600-1 2.050000-1 0.000000+03843 2151   74\n"
  " 2.500000+4 4.040500+3 0.000000+0 1.454600-1 2.050000-1 0.000000+03843 2151   75\n"
  " 3.000000+4 4.018100+3 0.000000+0 1.446500-1 2.050000-1 0.000000+03843 2151   76\n"
  " 4.000000+4 3.972700+3 0.000000+0 1.430200-1 2.050000-1 0.000000+03843 2151   77\n"
  " 5.000000+4 3.936800+3 0.000000+0 1.417200-1 2.050000-1 0.000000+03843 2151   78\n"
  " 6.000000+4 3.710000+3 0.000000+0 1.335600-1 2.050000-1 0.000000+03843 2151   79\n"
  " 7.000000+4 3.591200+3 0.000000+0 1.292800-1 2.050000-1 0.000000+03843 2151   80\n"
  " 8.000000+4 3.465000+3 0.000000+0 1.247400-1 2.050000-1 0.000000+03843 2151   81\n"
  " 1.000000+5 3.223200+3 0.000000+0 1.160400-1 2.050000-1 0.000000+03843 2151   82\n"
  " 0.000000+0 0.000000+0          0          0          0          03843 2  099999\n"
  " 0.000000+0 0.000000+0          0          0          0          03843 0  0    0\n";
}

std::string Tab1(){
  return
  " 0.000000+0 0.000000+0          0          0          1         506922 2151    4\n"
  "         50          2                                            6922 2151    5\n"
  " 1.000000-5 1.238100+0 4.000000+1 1.188400+0 5.000000+1 1.153200+06922 2151    6\n"
  " 6.000000+1 1.126500+0 7.000000+1 1.105300+0 8.000000+1 1.087800+06922 2151    7\n"
  " 9.000000+1 1.073100+0 1.000000+2 1.060500+0 2.000000+2 9.888000-16922 2151    8\n"
  " 3.000000+2 9.547000-1 4.000000+2 9.334000-1 5.000000+2 9.184000-16922 2151    9\n"
  " 6.000000+2 9.069000-1 7.000000+2 8.978000-1 8.000000+2 8.903000-16922 2151   10\n"
  " 9.000000+2 8.839000-1 1.000000+3 8.783000-1 2.000000+3 8.456000-16922 2151   11\n"
  " 3.000000+3 8.286000-1 4.000000+3 8.170000-1 5.000000+3 8.081000-16922 2151   12\n"
  " 6.000000+3 8.008000-1 7.000000+3 7.946000-1 8.000000+3 7.892000-16922 2151   13\n"
  " 9.000000+3 7.844000-1 1.000000+4 7.800000-1 1.200000+4 7.721000-16922 2151   14\n"
  " 1.400000+4 7.653000-1 1.600000+4 7.592000-1 1.800000+4 7.536000-16922 2151   15\n"
  " 2.000000+4 7.484000-1 2.500000+4 7.369000-1 3.000000+4 7.269000-16922 2151   16\n"
  " 3.500000+4 7.180000-1 4.000000+4 7.098000-1 4.200000+4 7.067000-16922 2151   17\n"
  " 4.400000+4 7.038000-1 4.600000+4 7.009000-1 4.800000+4 6.980000-16922 2151   18\n"
  " 5.000000+4 6.953000-1 5.500000+4 6.888000-1 6.000000+4 6.826000-16922 2151   19\n"
  " 6.500000+4 6.767000-1 7.000000+4 6.712000-1 7.500000+4 6.659000-16922 2151   20\n"
  " 8.000000+4 6.608000-1 8.500000+4 6.560000-1 9.000000+4 6.513000-16922 2151   21\n"
  " 9.500000+4 6.469000-1 2.000000+5 5.803000-1                      6922 2151   22\n";
}

SCENARIO( "Testing energy-dependent unresolved resonances" ){
  GIVEN( "valid ENDF parameters" ){
    long lineNumber = 0;
    int MAT = 3843;
    int MF = 2;
    int MT = 151;

    WHEN( "NRO == 0" ){
      std::string caseC = LRF2();
      auto begin = caseC.begin();
      auto end = caseC.end();

      resonanceParameters::Base base( 6.0E3, 1.0E5, 2, 2, 0, 0 );

      THEN( "a 'Case C' (LRU=2, LR2)  can be constructed" ){
      }
    }
    WHEN( "NRO != 0" ){
      std::string caseC = Tab1() + LRF2();
      auto begin = caseC.begin();
      auto end = caseC.end();

      resonanceParameters::Base base( 6.0E3, 1.0E5, 2, 2, 1, 0 );

      THEN( "a 'Case C' (LRU=2, LR2)  can be constructed" ){
      }
    }
  }
}
