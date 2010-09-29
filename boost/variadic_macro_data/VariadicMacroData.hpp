#if !defined(VARIADIC_MACRO_DATA_HPP)
#define VARIADIC_MACRO_DATA_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include <boost/preprocessor/array/data.hpp>
#include <boost/preprocessor/list/to_tuple.hpp>
#include <boost/preprocessor/seq/to_tuple.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include "detail/VMDDetail.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file

    The term 'Boost PP library' in this documentation is shorthand
    for the Boost preprocessor library.
    
    The macros provide support for variadic macro usage as well
    as integrating variadic macros with the Boost PP
    library without changing anything in the Boost PP
    library in any way. The latter is done by providing means
    of converting variadic macro data to Boost PP data types
    and by providing means of converting Boost PP data types
    back to variadic macro data.
    
    The macros will only work for compilers in which the Boost
    configuration macro, BOOST_NO_VARIADIC_MACROS, is not defined.
    
    Currently All of the macros in this library begin with the
    prefix of VMD_. If this library were accepted as a Boost 
    library, the macros could be changed to start with a prefix
    of BOOST_VMD_ .
    
    The word DATA in the name of some of the macros refers to variadic
    macro data, as represented by '...' when passed as the
    final parameter of a variadic macro and as __VA_ARGS__
    when expanded by the variadic macro definition.
    
    The words TUPLE, ARRAY, LIST, and SEQ in the name of some of the macros
    refer to the Boost PP library data types of tuples, arrays,
    lists, and sequences respectively. All mention in the comments
    of tuples, arrays, lists, and sequences refer to the Boost PP
    library definitions of these data types.
    
    The macros can be divided into these groups of functionality:
    
    - Macros which directly support variadic macro data processing.
      - VMD_DATA_SIZE(...)
      - VMD_DATA_ELEMENT(n,...)
    - Macros which convert variadic macro data to Boost PP
      data types.
      - VMD_DATA_TO_PP_TUPLE(...)
      - VMD_DATA_TO_PP_ARRAY(...)
      - VMD_DATA_TO_PP_LIST(...)
      - VMD_DATA_TO_PP_SEQ(...)
    - Macros which convert Boost PP data types to variadic
      macro data.
      - VMD_PP_TUPLE_TO_DATA(tuple)
      - VMD_PP_ARRAY_TO_DATA(array)
      - VMD_PP_LIST_TO_DATA(list)
      - VMD_PP_SEQ_TO_DATA(seq)
    - Macros which ease the use of the Boost PP tuple data
      type by not requiring that a tuple size be passed.
      - VMD_PP_TUPLE_SIZE(tuple)
      - VMD_PP_TUPLE_ELEM(n,tuple)
      - VMD_PP_TUPLE_REVERSE(tuple)
      - VMD_PP_TUPLE_TO_LIST(tuple)
      - VMD_PP_TUPLE_TO_SEQ(tuple)

*/

/// Expands to the number of comma-separated variadic macro data arguments.
/**

    ... = variadic macro data.

    returns = the number of comma-separated variadic macro data
              arguments being passed to it.
    
    The value returned can be between 1 and 64.
    
*/
#define VMD_DATA_SIZE(...) \
  VMD_DETAIL_DATA_SIZE(__VA_ARGS__) \
/**/

/// Expands to a particular variadic macro data argument.
/**

    n   = number of the variadic macro data argument.
          The number starts from 0 to the number of
          variadic macro data arguments - 1.
          
    ... = variadic macro data.

    returns = the particular macro data argument as specified
              by n. The argument returned can be any valid
              preprocessing token.
              
*/
#define VMD_DATA_ELEMENT(n,...) \
  VMD_DETAIL_DATA_ELEMENT(n,__VA_ARGS__) \
/**/

/// Expand to a Boost PP tuple data type.
/**

    ... = variadic macro data.

    returns = a Boost PP library tuple data type.
    
    You can use the result of this macro whenever 
    you need to pass a Boost PP library tuple as 
    data to a Boost PP library macro.
    
*/
#define VMD_DATA_TO_PP_TUPLE(...) \
  VMD_DETAIL_DATA_TO_PP_TUPLE(__VA_ARGS__) \
/**/

/// Expand to a Boost PP array data type.
/**

    ... = variadic macro data.

    returns = a Boost PP library array data type.
    
    You can use the result of this macro whenever 
    you need to pass a Boost PP library array as 
    data to a Boost PP library macro.
    
*/
#define VMD_DATA_TO_PP_ARRAY(...) \
  VMD_DETAIL_DATA_TO_PP_ARRAY(__VA_ARGS__) \
/**/

/// Expand to a Boost PP list data type.
/**

    ... = variadic macro data.

    returns = a Boost PP library list data type.
    
    You can use the result of this macro whenever
    you need to pass a Boost PP library list as
    data to a Boost PP library macro.
    
*/
#define VMD_DATA_TO_PP_LIST(...) \
  VMD_DETAIL_DATA_TO_PP_LIST(__VA_ARGS__) \
/**/

/// Expand to a Boost PP sequence data type.
/**

    ... = variadic macro data.

    returns = a Boost PP library sequence data type.
    
    You can use the result of this macro whenever
    you need to pass a Boost PP library sequence as
    data to a Boost PP library macro.
    
*/
#define VMD_DATA_TO_PP_SEQ(...) \
  VMD_DETAIL_DATA_TO_PP_SEQ(__VA_ARGS__) \
/**/

/// Expands to the number of elements in a tuple.
/**

    tuple = a Boost PP library tuple data type.

    returns = the number of elements in the tuple,
              commonly referred to as the tuple size.
              
    In the Boost PP library there is no way to calculate
    the size of a tuple, so that the size must be known
    in order to be used by Boost PP library tuple macros.
    With variadic macros the size of a tuple can be
    calculated from the tuple itself.
    
*/
#define VMD_PP_TUPLE_SIZE(tuple) \
  VMD_DETAIL_PP_TUPLE_SIZE(tuple) \
/**/

/// Expands to a particular tuple element.
/**

    n   = number of the tuple element.
          The number starts from 0 to the size of
          the tuple - 1.
          
    tuple = a Boost PP library tuple data type.

    returns = the particular tuple element as specified
              by n.
              
    In the Boost PP library there is no way to calculate 
    the size of a tuple, so that the size must be known 
    in order to be used by Boost PP library tuple macros.
    With variadic macros the size of a tuple can be 
    calculated from the tuple itself.
    
    Therefore this macro is a replacement for the BOOST_PP_TUPLE_ELEM
    macro without the necessity of having to pass a size.
    
*/
#define VMD_PP_TUPLE_ELEM(n,tuple) \
  VMD_DETAIL_PP_TUPLE_ELEM(VMD_PP_TUPLE_SIZE(tuple),n,tuple) \
/**/

/// Expands to a series of tokens which are equivalent to removing the parentheses from a tuple.
/**

    tuple = a Boost PP library tuple data type.

    returns = a series of comma-separated tokens equivalent to removing the parentheses from a tuple.
    
              This result is actually equivalent to the form of variadic macro data
              and can be used as an alternative to VMD_PP_TUPLE_TO_DATA to convert
              the tuple to variadic macro data.
              
    In the Boost PP library there is no way to calculate 
    the size of a tuple, so that the size must be known 
    in order to be used by Boost PP library tuple macros.
    With variadic macros the size of a tuple can be 
    calculated from the tuple itself.
    
    Therefore this macro is a replacement for the BOOST_PP_TUPLE_REM_CTOR
    macro without the necessity of having to pass a size.
    
*/
#define VMD_PP_TUPLE_REM_CTOR(tuple) \
  VMD_DETAIL_PP_TUPLE_REM_CTOR(VMD_PP_TUPLE_SIZE(tuple),tuple) \
/**/

/// Expands to a tuple whose elements are in reversed order.
/**

    tuple = a Boost PP library tuple data type.

    returns = a tuple whose elements are in reversed order
              from the original tuple.
              
    In the Boost PP library there is no way to calculate 
    the size of a tuple, so that the size must be known 
    in order to be used by Boost PP library tuple macros.
    With variadic macros the size of a tuple can be 
    calculated from the tuple itself.
    
    Therefore this macro is a replacement for the BOOST_PP_TUPLE_REVERSE
    macro without the necessity of having to pass a size.
    
*/
#define VMD_PP_TUPLE_REVERSE(tuple) \
  VMD_DETAIL_PP_TUPLE_REVERSE(VMD_PP_TUPLE_SIZE(tuple),tuple) \
/**/

/// Expands to a list whose elements are the same as a tuple.
/**

    tuple = a Boost PP library tuple data type.

    returns = a list whose elements are the same as the tuple
              that is inputted.
              
    In the Boost PP library there is no way to calculate 
    the size of a tuple, so that the size must be known 
    in order to be used by Boost PP library tuple macros.
    With variadic macros the size of a tuple can be 
    calculated from the tuple itself.
    
    Therefore this macro is a replacement for the BOOST_PP_TUPLE_TO_LIST
    macro without the necessity of having to pass a size.
    
*/
#define VMD_PP_TUPLE_TO_LIST(tuple) \
  VMD_DETAIL_PP_TUPLE_TO_LIST(VMD_PP_TUPLE_SIZE(tuple),tuple) \
/**/

/// Expands to a sequence whose elements are the same as a tuple.
/**

    tuple = a Boost PP library tuple data type.

    returns = a sequence whose elements are the same as the tuple
              that is inputted.
              
    In the Boost PP library there is no way to calculate 
    the size of a tuple, so that the size must be known 
    in order to be used by Boost PP library tuple macros.
    With variadic macros the size of a tuple can be 
    calculated from the tuple itself.
    
    Therefore this macro is a replacement for the BOOST_PP_TUPLE_TO_SEQ
    macro without the necessity of having to pass a size.
    
*/
#define VMD_PP_TUPLE_TO_SEQ(tuple) \
  VMD_DETAIL_PP_TUPLE_TO_SEQ(VMD_PP_TUPLE_SIZE(tuple),tuple) \
/**/

/// Expands to variadic macro data whose arguments are the same as a tuple's elements.
/**

    tuple = a Boost PP library tuple data type.

    returns = variadic macro data whose arguments are the same as the
              elements of a tuple that is inputted.
              
    The variadic macro data that is returned is in the form of
    of comma separated arguments. The variadic macro data can be
    passed to any macro which takes variadic macro data in the form
    of a final variadic macro data '...' macro parameter.
    
*/
#define VMD_PP_TUPLE_TO_DATA(tuple) \
  VMD_DETAIL_PP_TUPLE_TO_DATA(tuple) \
/**/

/// Expands to variadic macro data whose arguments are the same as an array's elements.
/**

    array = a Boost PP library array data type.

    returns = variadic macro data whose arguments are the same as the
              elements of an array that is inputted.
              
    The variadic macro data that is returned is in the form of
    of comma separated arguments. The variadic macro data can be
    passed to any macro which takes variadic macro data in the form
    of a final variadic macro data '...' macro parameter.
    
*/
#define VMD_PP_ARRAY_TO_DATA(array) \
  VMD_PP_TUPLE_TO_DATA(BOOST_PP_ARRAY_DATA(array)) \
/**/

/// Expands to variadic macro data whose arguments are the same as a list's elements.
/**

    list = a Boost PP library list data type.

    returns = variadic macro data whose arguments are the same as the
              elements of a list that is inputted.
              
    The variadic macro data that is returned is in the form of
    of comma separated arguments. The variadic macro data can be
    passed to any macro which takes variadic macro data in the form
    of a final variadic macro data '...' macro parameter.
    
*/
#define VMD_PP_LIST_TO_DATA(list) \
  VMD_PP_TUPLE_TO_DATA(BOOST_PP_LIST_TO_TUPLE(list)) \
/**/

/// Expands to variadic macro data whose arguments are the same as a sequence's elements.
/**

    seq = a Boost PP library sequence data type.

    returns = variadic macro data whose arguments are the same as the
              elements of a sequence that is inputted.
              
    The variadic macro data that is returned is in the form of
    of comma separated arguments. The variadic macro data can be
    passed to any macro which takes variadic macro data in the form
    of a final variadic macro data '...' macro parameter.
    
*/
#define VMD_PP_SEQ_TO_DATA(seq) \
  VMD_PP_TUPLE_TO_DATA(BOOST_PP_SEQ_TO_TUPLE(seq)) \
/**/

#endif // BOOST_NO_VARIADIC_MACROS
#endif // VARIADIC_MACRO_DATA_HPP
