#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}
 
bool isPrime(int number);
bool isRotaryPrime(int number);
vector<int> getPermutations(int number);
void permute(vector<string> &pVec, string a, int l, int r);

int main(){
  auto start = high_resolution_clock::now();

  vector <int> rotaryPrimes;
  for(int i = 0; i < 1000000; ++i){
    if(isPrime(i)){
      if(isRotaryPrime(i)){
      	  rotaryPrimes.push_back(i);
      }
    }
  }
  cout << rotaryPrimes;

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);

  cout << "\n";
  cout << "Program took " << duration.count()
       << " milli seconds to finish\n";
}

bool isPrime(int number) {
  if(number < 2){
    return false;
  }
  for(int i = 2; i < int(sqrt(number)) + 1; ++i){
    if(number % i == 0) {
      return false;
    }
  }
  return true;
}

bool isRotaryPrime(int number){
  vector<int> permutatedNumbers = getPermutations(number);
  for(size_t i = 0; i < permutatedNumbers.size(); ++i){
    if(!isPrime(permutatedNumbers[i])){
      return false;
    }
  }
  return true;
}

void permute(vector<string> &pVec, string a, int l, int r){
  if(l == r){
    pVec.push_back(a);
  } else {
    for(int i = l; i <= r; ++i){
      swap(a.at(l), a.at(i));
      permute(pVec, a, l+1, r);
      swap(a.at(l), a.at(i));
    }
  }
}

vector<int> getPermutations(int number){
  string strNumber = to_string(number);
  vector<string> v;
  vector<int> vi;
  permute(v, strNumber, 0, strNumber.size() - 1);
  for(const auto &i : v){
    vi.push_back(stoi(i));
  }
  return vi;
}
