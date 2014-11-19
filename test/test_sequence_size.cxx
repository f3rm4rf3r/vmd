#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/identifier.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/list.hpp>
#include <boost/vmd/number.hpp>
#include <boost/vmd/seq.hpp>
#include <boost/vmd/sequence.hpp>
#include <boost/vmd/tuple.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>
#include <boost/preprocessor/array/elem.hpp>
#include <boost/preprocessor/array/size.hpp>
#include <boost/preprocessor/list/at.hpp>
#include <boost/preprocessor/list/size.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/preprocessor/variadic/size.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS

  #define BOOST_VMD_REGISTER_ggh (ggh)
  #define BOOST_VMD_DETECT_ggh_ggh
  #define BOOST_VMD_REGISTER_dvd (dvd)
  #define BOOST_VMD_DETECT_dvd_dvd
  
  #define ANIDENTIFIER ggh
  #define ANIDENTIFIER2 dvd
  #define ANUMBER 249
  #define ANUMBER2 17
  #define ASEQ (25)(26)(27)
  #define ATUPLE (0,1,2,3,((a,b))((c,d))((e))((f,g,h)))
  #define ALIST (0,(1,(2,(3,BOOST_PP_NIL))))
  #define ANARRAY (3,(a,b,38))
  #define ASEQUENCE ANUMBER ALIST ATUPLE ANIDENTIFIER ANARRAY ASEQ
  #define ASEQUENCE2 ANIDENTIFIER2 ASEQ ALIST ANUMBER ATUPLE
  #define ASEQUENCE3 ASEQ ANUMBER2 ATUPLE
  #define ASEQUENCE4
  
  /* SIZE */
  
  BOOST_TEST_EQ(BOOST_VMD_SIZE(ASEQUENCE),6);
  BOOST_TEST_EQ(BOOST_VMD_SIZE(ASEQUENCE2),5);
  BOOST_TEST_EQ(BOOST_VMD_SIZE(ASEQUENCE3),3);
  BOOST_TEST_EQ(BOOST_VMD_SIZE(ASEQUENCE4),0);
  
#endif

  return boost::report_errors();
  
  }
