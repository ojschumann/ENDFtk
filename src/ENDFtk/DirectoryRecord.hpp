class DirectoryRecord : protected record::Base< record::Integer< 33 >,
                                                record::Integer< 11 >,
                                                record::Integer< 11 >,
                                                record::Integer< 11 > > {
public:

  using base =
    record::Base< record::Integer< 33 >, record::Integer< 11 >,
                  record::Integer< 11 >, record::Integer< 11 > >;
  
  using tail = record::TailVerifying< record::MAT, record::MF, record::MT >;

  DirectoryRecord( int64_t L1, int64_t L2, int64_t N1, int64_t N2 ) :
    base( L1, L2, N1, N2 ){}

  template< typename Iterator >
  DirectoryRecord( Iterator& it, const Iterator& end, long& lineNumber,
                   int MAT, int MF, int MT )
    try: base( it, end ){
      tail( MAT, MF, MT, it, end, lineNumber );
    } catch ( std::exception& e ) {
      /* TODO error information here */
      throw e;
    } catch ( int fieldNo ){
      --lineNumber;
      /* TODO error information here */
      throw std::exception();
    }

#define DEFINE_GETTER( name, index )                            \
  MutableReturnType< index >                                    \
  name (){ return std::get< index >( this->fields ); }          \
                                                                \
  ImmutableReturnType< index >                                  \
  name () const { return std::get< index >( this->fields ); }

  DEFINE_GETTER( L1, 0 )
  DEFINE_GETTER( L2, 1 )
  DEFINE_GETTER( N1, 2 )
  DEFINE_GETTER( N2, 3 )

#undef DEFINE_GETTER
  
  bool
  operator==( const DirectoryRecord& rhs ){
    return static_cast< base& >( *this ) == rhs;
  }

  bool
  operator!=( const DirectoryRecord& rhs ){
    return not( *this == rhs );
  }  
};
