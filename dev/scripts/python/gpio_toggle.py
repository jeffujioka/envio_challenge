#!/usr/bin/env python3

import threading, time, textwrap, argparse
from gpio import Gpio

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
  toggle_interval = 1 # it could come from options as welll

  gpio = Gpio()
  gpio._set_gpio_base_path_only_for_testing_purposes('./sys/class/gpio')
  gpio.export(gpio_pin_y)
  gpio.export(gpio_pin_x)

  gpio.set_direction(gpio_pin_y, 'in')
  gpio.set_direction(gpio_pin_x, 'out')

  try:
    toggle_value = 0

    while (True):
      output_value = 0
      sleep_interval = 0.1

      if (gpio.input(gpio_pin_y) == '1'):
        toggle_value = (0, 1)[toggle_value == 0] # toggle output value
        output_value = toggle_value
        sleep_interval = 1
      else:
        toggle_value = 0 # gpio y is low... so reset it
      
      gpio.output(gpio_pin_x, output_value)

      print(''.join((f"gpio Y [pin={gpio_pin_y}, value={gpio.input(gpio_pin_y)}]",
                      " | ",
                     f"gpio X [pin={gpio_pin_x}, value={gpio.input(gpio_pin_x)}]")))

      time.sleep(sleep_interval)

  except KeyboardInterrupt:
    print("Shutdown requested...exiting")
  except Exception:
    try:
      sys.exit(0)
    except SystemExit:
      os._exit(0)
  finally:
    gpio.unexport(gpio_pin_y)
    gpio.unexport(gpio_pin_x)