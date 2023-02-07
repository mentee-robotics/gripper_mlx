#ifndef MLX90393_h
#define MLX90393_h

class MLX90393 {
  public:
    MLX90393(unsigned char Addr);
    void Read();
    int x; 
    int y; 
    int z;
    unsigned char _Addr;
  private:
    int once;
    int startTime;
    int first_xMag;
    int first_yMag;
    int first_zMag;
    unsigned int data[7];
};

#endif