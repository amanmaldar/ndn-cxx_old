//  (C) Copyright 2009-2011 Frederic Bron.
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_HAS_MULTIPLIES_ASSIGN_HPP_INCLUDED
#define BOOST_TT_HAS_MULTIPLIES_ASSIGN_HPP_INCLUDED

#define BOOST_TT_TRAIT_NAME has_multiplies_assign
#define BOOST_TT_TRAIT_OP *=
#define BOOST_TT_FORBIDDEN_IF\
   ::ndnboost::type_traits::ice_or<\
      /* Lhs==fundamental and Lhs==const and Rhs==fundamental */\
      ::ndnboost::type_traits::ice_and<\
         ::ndnboost::is_fundamental< Lhs_nocv >::value,\
         ::ndnboost::is_const< Lhs_noref >::value,\
         ::ndnboost::is_fundamental< Rhs_nocv >::value\
      >::value,\
      /* Lhs==pointer and (Rhs==fundamental or Rhs==pointer) */\
      ::ndnboost::type_traits::ice_and<\
         ::ndnboost::is_pointer< Lhs_noref >::value,\
         ::ndnboost::type_traits::ice_or<\
            ::ndnboost::is_fundamental< Rhs_nocv >::value,\
            ::ndnboost::is_pointer< Rhs_noref >::value\
         >::value\
      >::value,\
      /* Rhs==pointer and (Lhs==fundamental or Lhs==pointer) */\
      ::ndnboost::type_traits::ice_and<\
         ::ndnboost::is_pointer< Rhs_noref >::value,\
         ::ndnboost::type_traits::ice_or<\
            ::ndnboost::is_fundamental< Lhs_nocv >::value,\
            ::ndnboost::is_pointer< Lhs_noref >::value\
         >::value\
      >::value\
   >::value


#include <ndnboost/type_traits/detail/has_binary_operator.hpp>

#undef BOOST_TT_TRAIT_NAME
#undef BOOST_TT_TRAIT_OP
#undef BOOST_TT_FORBIDDEN_IF

#endif
