#if !defined(VMD_MAIN_COMMON_HPP)
#define VMD_MAIN_COMMON_HPP

#include "detail/vmd_detail_setup.hpp"

#if BOOST_VMD_VARIADICS

#include <boost/preprocessor/facilities/identity.hpp>

#include "vmd_is_tuple_begin.hpp"
#include "detail/vmd_detail_main.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

#if !BOOST_VMD_MSVC

#define BOOST_VMD_IS_EMPTY(...) \
    VMD_DETAIL_IS_EMPTY_IIF \
      ( \
      BOOST_VMD_IS_TUPLE_BEGIN \
        ( \
        __VA_ARGS__ \
        ) \
      ) \
      ( \
      0, \
      BOOST_VMD_IS_TUPLE_BEGIN \
        ( \
        VMD_DETAIL_IS_EMPTY_NON_FUNCTION_C __VA_ARGS__ () \
        ) \
      ) \
/**/

#endif /* BOOST_VMD_MSVC */

#endif /* BOOST_VMD_VARIADICS */

#endif /* VMD_MAIN_COMMON_HPP */
