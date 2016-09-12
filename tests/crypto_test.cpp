#include "crypto.hpp"
#include <cassert>

using namespace std;

int main() {
  // Results copied from https://caligatio.github.io/jsSHA/
  assert(Crypto::hex(Crypto::sha1("Test")) == "640ab2bae07bedc4c163f679a746f7ab7fb5d1fa");
  assert(Crypto::hex(Crypto::sha1("Test", 2)) == "af31c6cbdecd88726d0a9b3798c71ef41f1624d5");


  //Teste md5
  assert(Crypto::hex(Crypto::md5("Password")) == "dc647eb65e6711e155375218212b3964");
  
  // teste sha256
  assert(Crypto::hex(Crypto::sha256("Password")) == "e7cf3ef4f17c3999a94f2c6f612e8a888e5b1026878e4e19398b23bd38ec221a");
  //Teste sha512
  assert(Crypto::hex(Crypto::sha512("Password")) == "E6C83B282AEB2E022844595721CC00BBDA47CB24537C1779F9BB84F04039E1676E6BA8573E588DA1052510E3AA0A32A9E55879AE22B0C2D62136FC0A3E85F8BB");
  // Results copied from http://www.freecodeformat.com/pbkdf2.php
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 4096, 128 / 8)) == "f66df50f8aaa11e4d9721e1312ff2e66");
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 8192, 512 / 8)) == "a941ccbc34d1ee8ebbd1d34824a419c3dc4eac9cbc7c36ae6c7ca8725e2b618a6ad22241e787af937b0960cf85aa8ea3a258f243e05d3cc9b08af5dd93be046c");
}
