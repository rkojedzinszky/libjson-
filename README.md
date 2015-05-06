# libjson++
[![Build Status](https://travis-ci.org/rkojedzinszky/libjson-.svg?branch=master)](https://travis-ci.org/rkojedzinszky/libjson-)

A simple and intuitive easy-to use C++ class to read/write JSON structures

Example code:

Generate/output:
JSON::Value r = JSON::Object();
r["asd"] = "string";
r["asd"] = 3; // integer
r["asd"] = JSON::Object();
std::cout << r << std::endl;

Read/parse:
JSON::Value in;
std::cin >> in;
