#include "crypto.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
  std::string x = "";
  cout << "SHA-1 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha1("Test")) << endl
       << endl;

  cout << "SHA-1 with two iterations" << endl;
  cout << Crypto::hex(Crypto::sha1(Crypto::sha1("Test"))) << endl;
  cout << Crypto::hex(Crypto::sha1("Test", 2)) << endl
       << endl;

  cout << "The derived key from the PBKDF2 algorithm" << endl;
  cout << Crypto::hex(Crypto::pbkdf2("Password", "Salt")) << endl;

  static const char alphanum[] = "ABCDEFGHIJKLMNPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  for (char c : alphanum) {
    for (char d : alphanum) {
      for (char e : alphanum) {
        string x(3, ' ');
        x[0] = c;
        x[1] = d;
        x[2] = e;
        string out = Crypto::hex(Crypto::pbkdf2(x, "Saltet til Ola", 2048, 20));
        cout << x << "\n";
        if (out == "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6") {
          cout << "Passordet hans er: " << endl;
          return 0;
        }
      }
    }
  }
}
