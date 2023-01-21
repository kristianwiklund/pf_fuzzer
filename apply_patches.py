from os.path import join, isfile
from os import getcwd
from platformio.project.config import ProjectConfig
Import("env")

# brutally run patch

print("* Patching")
env.Execute("patch %s %s" % (".pio/libdeps/attiny85/Adafruit-Trinket-USB-kbd_only/usbconfig.hx","patches/1-kbd-changepins.patch"))
