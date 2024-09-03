/**
 *  @brief Return iterator to the section with the given mt number
 *
 *  @param[in] mt    the mt number
 */
auto find( int mt ) {

  auto iter = std::lower_bound( this->sections_.begin(), this->sections_.end(), mt,
                                [] ( auto&& left, auto&& right )
                                   { return Derived::getSectionNumber( left ) < right; } );

  if ( iter != this->sections_.end() ) {

    if ( Derived::getSectionNumber( *iter ) == mt ) {

      return iter;
    }
  }
  return this->sections_.end();
}

/**
 *  @brief Return iterator to the section with the given mt number
 *
 *  @param[in] mt    the mt number
 */
auto find( int mt ) const {

  auto iter = std::lower_bound( this->sections_.begin(), this->sections_.end(), mt,
                                [] ( auto&& left, auto&& right )
                                   { return Derived::getSectionNumber( left ) < right; } );

  if ( iter != this->sections_.end() ) {

    if ( Derived::getSectionNumber( *iter ) == mt ) {

      return iter;
    }
  }
  return this->sections_.end();
}