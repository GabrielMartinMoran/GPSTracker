#----------------------------- IMPORTAMOS EL DIRECTORIO src ---------------------------
import os
import sys

#IMPORTAMOS DEL PADRE
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../src')))
#--------------------------------------------------------------------------------------

import unittest

class TestConfiguracionBaliza(unittest.TestCase):	

	def test_base(self):
		pass

def main():
	unittest.main()

if __name__ == '__main__':
	main()
