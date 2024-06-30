/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/30 13:26:42 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{
private:
  T*  _array;
  unsigned int _size;

public:
  Array( void );
  Array( const unsigned int& length );
  Array( const Array& obj );
  ~Array();

  class outOfBoundsIndex : public std::exception
  {
  public:
    virtual const char* what( void ) const throw();
  };

  const unsigned int& getSize( void ) const;
  T             getElement( unsigned int& index) const;
  T*            newArray( void ) const;

  Array&  operator=( const Array& obj);
  T&      operator[](int index);
};

#include "Array.tpp"

#endif
