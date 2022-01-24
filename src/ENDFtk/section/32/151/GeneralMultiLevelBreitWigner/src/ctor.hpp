//! @todo pybind11 variant needs default constructor workaround
#ifdef PYBIND11
/**
 *  @brief Default constructor - only enabled for pybind11
 */
GeneralMultiLevelBreitWigner() = default;
#endif

/**
 *  @brief Constructor with scattering radius uncertainty
 *
 *  @param[in] spi       the target spin value
 *  @param[in] ap        the scattering radius
 *  @param[in] nls       the number of l values
 *  @param[in] dap       the scattering radius uncertainty data
 *  @param[in] cshort    the short range covariance blocks
 *  @param[in] clong     the long range covariance blocks
 */
GeneralMultiLevelBreitWigner( double spi, double ap, unsigned int nls, double dap,
                              std::vector< ShortRangeBreitWignerBlock >&& cshort,
                              std::vector< LongRangeCovarianceBlock >&& clong ) :
  // no need for a try ... catch: nothing can go wrong here
  GeneralCovarianceBase( spi, ap, nls, std::move( dap ),
                         std::move( cshort ), std::move( clong ) ) {

    Log::info( "Encountered error while constructing resonance and covariance "
               "parameters in the Multi-Level Breit-Wigner representation for "
               "the general covariance format (LCOMP = 1)" );
    throw;
  }

/**
 *  @brief Constructor without scattering radius uncertainty
 *
 *  @param[in] spi       the target spin value
 *  @param[in] ap        the scattering radius
 *  @param[in] nls       the number of l values
 *  @param[in] cshort    the short range covariance blocks
 *  @param[in] clong     the long range covariance blocks
 */
GeneralMultiLevelBreitWigner( double spi, double ap, unsigned int nls,
                              std::vector< ShortRangeBreitWignerBlock >&& cshort,
                              std::vector< LongRangeCovarianceBlock >&& clong ) :
  // no need for a try ... catch: nothing can go wrong here
  GeneralCovarianceBase( spi, ap, nls, std::move( cshort ), std::move( clong ) ) {

    Log::info( "Encountered error while constructing resonance and covariance "
               "parameters in the Multi-Level Breit-Wigner representation for "
               "the general covariance format (LCOMP = 1)" );
    throw;
  }

/**
 *  @brief Constructor (from a buffer)
 *
 *  @tparam Iterator        a buffer iterator
 *
 *  @param[in] it           the current position in the buffer
 *  @param[in] end          the end of the buffer
 *  @param[in] lineNumber   the current line number
 *  @param[in] MAT          the expected MAT number
 *  @param[in] MF           the expected MF number
 *  @param[in] MT           the expected MT number
 */
template< typename Iterator >
GeneralMultiLevelBreitWigner( Iterator& it, const Iterator& end, long& lineNumber,
                              int MAT, int MF, int MT ) :
  // no try ... catch: exceptions will be handled in the derived class
  GeneralCovarianceBase( it, end, lineNumber, MAT, MF, MT ) {

    Log::info( "Encountered error while constructing resonance and covariance "
               "parameters in the Multi-Level Breit-Wigner representation for "
               "the general covariance format (LCOMP = 1)" );
    throw;
  }
