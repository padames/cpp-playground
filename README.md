# cpp-playground

## OS Builds

Platform | Build status
---------|-------------:
Ubuntu 18.04 LTS | [![Build Status](https://api.travis-ci.com/padames/cpp-playground.svg?branch=main&status=failed)](https://travis-ci.org/padames/cpp-playground)


A simple example of a C++ project and how easy it is to start the continuous integration using Travis.

Uses Google tests with a recipe by author Craig Scott from his blog https://crascit.com/2015/07/25/cmake-gtest/

Stopped trying to build on Mac OSX because of the specification of the g++ compiler 4.5 or later was colliding with the default setting of 4.1 which does not understand lambdas and many of the newer std namespace upgrades.

Next steps to add packaging and deployment.
