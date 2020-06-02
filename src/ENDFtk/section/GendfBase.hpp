class GendfBase : protected Base {

protected:
  /* fields */
  std::vector< ListRecord > lists_;
  int num_legendre_;
  int num_sigma0_;
  int lrflag_;
  int num_groups_;
  double temperature_;

  /* methods */
  #include "ENDFtk/section/GendfBase/src/populateLists.hpp"

public:
  /* constructor */
  #include "ENDFtk/section/GendfBase/src/ctor.hpp"

  /* methods */
  int legendreOrder() const { return num_legendre_-1; }
  int numLegendre() const { return num_legendre_; }
  int numSigma0() const { return num_sigma0_; }
  int breakupFlag() const { return lrflag_; }
  int numGroups() const { return num_groups_; }
  double temperature() const { return temperature_; }

};
