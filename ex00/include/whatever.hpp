/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/28 12:37:37 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <cstdlib>

template <typename T>
void swap( T& lhs, T& rhs )
{
  T tmp;

  tmp = lhs;
  lhs = rhs;
  rhs = tmp;
  return ;
}

template <typename T>
const T& min( const T& lhs, const T& rhs )
{
  return ((lhs < rhs) ? lhs : rhs);
}

template <typename T>
const T& max( const T& lhs, const T& rhs )
{
  return ((lhs > rhs) ? lhs : rhs);
}

#endif
