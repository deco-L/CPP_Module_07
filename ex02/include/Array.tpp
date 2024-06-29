/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/29 18:01:18 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

template <typename T>
Array<T>::Array(void) : _size(0)
{
  this->_array = new T[this->_size];
}

template <typename T>
Array<T>::Array( const unsigned int& length ) : _size(length)
{
  this->_array = new T[this->_size];
}

template <typename T>
Array<T>::Array( const Array<T>* obj )
{
  this = obj;
}

template <typename T>
Array<T>::~Array()
{
  std::cout << "aaaa" << std::endl;
  delete[] this->_array;
  std::cout << "aaaa" << std::endl;
}

template <typename T>
const char* Array<T>::outOfBoundsIndex::what(void) const throw()
{
  return ("\e[1;38;5;182mError: out of bounds index");
}

template <typename T>
int& Array<T>::getSize()
{
  return (this->_size);
}

template <typename T>
T Array<T>::getElement(unsigned int& index)
{
  return (this->_array(index));
}

template <typename T>
T*  Array<T>::newArray()
{
  T*  array;

  array = new T[this->getSize()];
  for (unsigned int index; index < this->getSize(); index++)
    array[index] = this->getElement();
  return (array);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
  if (&obj != this)
  {
    this->_size = obj.getSize();
    if (this->_array)
      delete[] this->_array;
    this->_array = obj.newArray();
  }
  return (*this);
}

template <typename T>
T&  Array<T>::operator[](int index)
{
  if (this->getSize() < index || index < 0)
    throw Array<T>::outOfBoundsIndex();
  return (this->_array[index]);
}
