#!/usr/bin/env python3

import argparse
import time

if __name__ == '__main__':
  
  _HELP_GPIO_PIN = 'Defines the gpio {gpioPin} pin'

  parser = argparse.ArgumentParser()

  parser.add_argument('-i', type=int, required=True,
                      help=_HELP_GPIO_PIN.format(gpioPin='Y'))
  parser.add_argument('-o', type=int, required=True,
                      help=_HELP_GPIO_PIN.format(gpioPin='X'))

  arg = parser.parse_args()
  
  gpio_pin_y = arg.i
  gpio_pin_x = arg.o

  print(gpio_pin_x)
  print(gpio_pin_y)