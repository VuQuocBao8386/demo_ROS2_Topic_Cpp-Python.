from setuptools import find_packages
from setuptools import setup

setup(
    name='ros_serivce',
    version='0.0.0',
    packages=find_packages(
        include=('ros_serivce', 'ros_serivce.*')),
)
