/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/29 17:56:08 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{
private:
  T*            _array;
  int  _size;

public:
  Array( void );
  Array( const unsigned int& length );
  Array( const Array<T>* obj );
  ~Array();

  class outOfBoundsIndex : public std::exception
  {
  public:
    virtual const char* what( void ) const throw();
  };

  int& getSize( void );
  T             getElement( unsigned int& index);
  T*            newArray( void );

  Array&  operator=( const Array<T>& obj);
  T&      operator[](int index);
};

#include "Array.tpp"

#endif
