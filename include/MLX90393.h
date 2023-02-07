#ifndef MLX90393_h
#define MLX90393_h

class MLX90393 {
  public:
    MLX90393(unsigned char Addr);
    void Read();
    void Setup(unsigned char Addr);
    int x; 
    int y; 
    int z;
    unsigned char _Addr;
  private:
    unsigned int data[7];
};

#endif