from setuptools import find_packages
from setuptools import setup

setup(
    name='ros_interface',
    version='0.0.0',
    packages=find_packages(
        include=('ros_interface', 'ros_interface.*')),
)
