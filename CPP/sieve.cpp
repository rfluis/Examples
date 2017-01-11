#include <vector>
#include <iostream>
#include <fstream>

int main()
{
  unsigned long long int size,half,index,subindex,step;
  size = 32L*1024L*1024L*1024L; // 32 gigabit = 4 gigabyte :)
  half=  185363 ; 
  std::vector<bool> tabla(size,true);
  for (subindex=4 ; subindex<size ; subindex+=2) tabla[subindex]=false;
  std::cout << "Numero primo:"<<2<<std::endl;
  for (index=3;index<half;index++){
    while (!tabla[index]) index++; 
    if (tabla[index]) std::cout << "Numero primo:"<<index<<std::endl;
    step = 2*index;
    for (subindex=index*index ; subindex<size ; subindex+=step) tabla[subindex]=false;
  }
  std::fstream out("pipe",std::ios::out);
  for (index=1;index<size;) 
  {
    unsigned char k=0;
    if (tabla[index++]) k=k+128;
    if (tabla[index++]) k=k+64;
    if (tabla[index++]) k=k+32;
    if (tabla[index++]) k=k+16;
    if (tabla[index++]) k=k+8;
    if (tabla[index++]) k=k+4;
    if (tabla[index++]) k=k+2;
    if (tabla[index++]) k=k+1;
    out << k ;     
  }
  return 0;  
}
