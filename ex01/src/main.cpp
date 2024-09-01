/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/08/25 15:18:26 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <sstream>
#include <sys/ioctl.h>
#include <unistd.h>

static size_t get_term_line() {
	winsize	terminal_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size);
	return (terminal_size.ws_col);
}

static void draw_terminal_line() {
	size_t	terminal_col;

	terminal_col = get_term_line();
	for (size_t i = 0; i < terminal_col; i++)
		std::cout << "=";
	std::cout << std::endl;
	return ;
}

static void printString(const std::string& str)
{
  std::cout << str << " ";
}

static void  printInt(const int nbr)
{
  std::cout << nbr << " ";
}

int main() {
  draw_terminal_line();
  std::string stringArray[] = {"apple", "banana", "cherry"};
  int         intArray[] = {42, 84, 126};
  std::size_t slength = sizeof(stringArray) / sizeof(std::string);
  std::size_t ilength = sizeof(intArray) / sizeof(int);

  std::cout << "String array: ";
  iter(stringArray, slength, printString);
  std::cout << std::endl << "Int array: ";
  iter(intArray, ilength, printInt);
  std::cout << std::endl;
  draw_terminal_line();
  return (EXIT_SUCCESS);
}