from os import path

class Gpio:
  _GPIO_BASE_PATH = '/sys/class/gpio'

  def _set_gpio_base_path_only_for_testing_purposes(self, new_path):
    # "taking advantage of python not having constant for changing the value of _GPIO_BASE_PATH
    self._GPIO_BASE_PATH = new_path

  def _get_gpio_path(self, pin):
    return path.join(self._GPIO_BASE_PATH, 'gpio{0}'.format(pin))
  
  def _get_gpio_file_path(self, pin, file):
    return path.join(self._GPIO_BASE_PATH, 'gpio{0}'.format(pin), file)

  def _get_file(self, file_path, mode):
    file = None
    try:
      file = open(file_path, mode)
    except Exception as e:
      print(e)
    
    return file

  def _write(self, file_path, data):
    file = None
    try:
      file = self._get_file(file_path, 'w')
      file.write(str(data))
      file.flush()
    except Exception as e:
      print(e)
    finally:
      if (file): file.close()

  def _read(self, file_path):
    ret = None
    file = None
    try:
      file = self._get_file(file_path, 'r')
      if (file):
        ret = file.read().strip()
    except Exception as e:
      print(e)
    finally:
      if (file): file.close()
    
    return ret

  def export(self, pin):
    """Exports a given gpio pin.
    Equivalent to: echo pin > /sys/class/gpio/export

    Parameter:
      pin : int
        Gpio pin to be exported
    """
    self._write(path.join(self._GPIO_BASE_PATH, 'export'), pin)
    
  def unexport(self, pin):
    """Unexports a given gpio pin.
    Equivalent to: echo pin > /sys/class/gpio/unexport

    Parameter:
      pin : int
        Gpio pin to be unexported
    """
    self._write(path.join(self._GPIO_BASE_PATH, 'unexport'), pin)

  def set_direction(self, pin, direction):
    """Sets the direction of a given gpio pin.
    Equivalent to: echo <direction> /sys/class/gpio/<gpio_pin>/direction

    Parameters:
      pin : int
        Gpio pin to set the direction
      direction : str
        Direction to be set to the given gpio pin
        Possible values are 'in' or 'out'
    """
    if direction not in ['in', 'out']:
        raise ValueError(f"ERROR! Setting direction [{direction}] of pin [{pin}]. Direction must be 'in' or 'out'")
    
    self._write(self._get_gpio_file_path(pin, 'direction'), direction)
  
  def output(self, pin, value):
    """Sets the output of a given gpio pin.

    Parameters:
      pin : int
        Gpio pin to be set the output to
      value : int
        Value to be set to the given gpio pin
        Possible values are 0 or 1
    """
    # TODO validate parameters
    self._write(self._get_gpio_file_path(pin, 'value'), value)
  
  def input(self, pin):
    """Reads the value of a given gpio pin.

    Parameters:
      pin : int
        Gpio pin to be read the state from
      value : int
        Value to be set to the given gpio pin
        Possible values are 0 or 1
    
    Returns:
      str
        '0' if gpio pin level is low,
        '1' if gpio pin level is high
    """
    return self._read(self._get_gpio_file_path(pin, 'value'))